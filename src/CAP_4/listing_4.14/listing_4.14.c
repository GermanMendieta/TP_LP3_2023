#include <semaphore.h>
#include <pthread.h> 
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 

#define MAX_JOBS 3

int thread_flag; 
pthread_cond_t thread_flag_cv; 
pthread_mutex_t thread_flag_mutex; 

struct job { 
/* Link field for linked list. */
  int n_job;
  struct job* next; 
  /* Other fields describing work to be done... */ 
};
/* A linked list of pending jobs. */ 
struct job* job_queue; 

/* A mutex protecting job_queue. */ 
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER; 
/* process de job*/
void process_job (struct job* jobs){
  sleep (1);
  printf("Job %dth finished\n", jobs->n_job );
}

void initialize_flag () 
{ 
  /* Initialize the mutex and condition variable. */ 
  pthread_mutex_init (&thread_flag_mutex, NULL); 
  pthread_cond_init (&thread_flag_cv, NULL); 
  /* Initialize the flag value. */ 
  thread_flag = 1; 
} 
/* Sets the value of the thread flag to FLAG_VALUE. */ 
void set_thread_flag (int flag_value) 
{ 
  /* Lock the mutex before accessing the flag value. */ 
  pthread_mutex_lock (&thread_flag_mutex); 
  /* Set the flag value, and then signal in case thread_function is blocked, waiting for 
  the flag to become set. However, thread_function can't actually check the flag until the mutex is unlocked. */ 
  thread_flag = flag_value; 
  pthread_cond_signal (&thread_flag_cv); 
  /* Unlock the mutex. */ 
  pthread_mutex_unlock (&thread_flag_mutex); 
} 

/* Add a new job to the front of the job queue. */ 
void enqueue_job (int n_job) 
{ 
  struct job* new_job; 
  /* Allocate a new job object. */ 
  new_job = (struct job*) malloc (sizeof (struct job)); 
  /* Set the other fields of the job struct here... */ 
  new_job->n_job = n_job; 
  /* Lock the mutex on the job queue before accessing it. */ 
  pthread_mutex_lock (&thread_flag_mutex); 
  /* Place the new job at the head of the queue. */ 
  new_job->next = job_queue; 
  job_queue = new_job; 
  
  pthread_cond_signal(&thread_flag_cv);
  /* Unlock the job queue mutex. */ 
  pthread_mutex_unlock (&thread_flag_mutex); 
} 

/* work functioin */
void do_work (){
  struct job* next_job;
  pthread_mutex_lock (&job_queue_mutex); 
  /* Because of the semaphore, we know the queue is not empty. Get 
  the next available job. */ 
  next_job = job_queue; 
  /* Remove this job from the list. */ 
  job_queue = job_queue->next; 
  /* Unlock the mutex on the job queue because we're done with the 
  queue for now. */ 
  pthread_mutex_unlock (&job_queue_mutex); 
  /* Carry out the work. */ 
  process_job (next_job); 
  /* Clean up. */ 
  free (next_job); 
  set_thread_flag(0);
}
/* Calls do_work repeatedly while the thread flag is set; blocks if the flag is clear. */ 
void* thread_function (void* thread_arg) 
{ 
  /* Loop infinitely. */ 
  while (1) { 
    /* Lock the mutex before accessing the flag value. */ 
    pthread_mutex_lock (&thread_flag_mutex); 
    while (!thread_flag) 
      /* The flag is clear. Wait for a signal on the condition variable, indicating that the flag 
      value has changed. When the signal arrives and this thread unblocks, loop and check the flag again. */ 
      pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex); 
    /* When we've gotten here, we know the flag must be set. Unlock the mutex. */ 
    pthread_mutex_unlock (&thread_flag_mutex); 
    /* Do some work. */ 
    do_work (); 
    
  } 
  return NULL; 
} 


int main () 
{ 

  initialize_flag();
  /* add some jobs*/
  for (int i=0; i< MAX_JOBS; ++i){
    enqueue_job(i+1);
  }
  
  pthread_t thread1; 
  pthread_t thread2; 
  
  pthread_create (&thread1, NULL, &thread_function, NULL); 
  pthread_create (&thread2, NULL, &thread_function, NULL); 

  sleep(20);
  pthread_cancel(thread1);
  pthread_cancel(thread2);

  return 0; 
} 