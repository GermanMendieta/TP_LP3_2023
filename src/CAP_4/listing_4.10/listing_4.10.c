#include <pthread.h> 
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 

/* MAX OF JOBS */
#define MAX_JOBS 15


struct job { 
/* Link field for linked list. */
  int n_job;
  struct job* next; 
  /* Other fields describing work to be done... */ 
}; 
/* A linked list of pending jobs. */ 
struct job* job_queue; 

void process_job (struct job* jobs){
  sleep (1);
  printf("Job %dth finished\n", jobs->n_job );
}



/* Process queued jobs until the queue is empty. */ 
void* thread_function (void* arg) 
{ 
  while (job_queue != NULL) { 
    /* Get the next available job. */ 
    struct job* next_job = job_queue; 
    /* Remove this job from the list. */ 
    job_queue = job_queue->next; 
    /* Carry out the work. */ 
    process_job (next_job); 
    /* Clean up. */ 
    free (next_job); 
  } 
  return NULL; 
} 

/* iniicalizar los trabajos */
void init_jobs(){
  // initial Job
  struct job* new_job = (struct job* ) malloc (sizeof(struct job));
  new_job->n_job = 1;
  new_job->next = NULL;

  job_queue = new_job;
  int n = 1;

  // joion queue to add jobs
  while (n < MAX_JOBS){
    new_job = (struct job* ) malloc (sizeof(struct job));
    new_job->n_job = 1 + n++;
    new_job->next = NULL;
    
    struct job* jobs = job_queue;
    while (jobs->next){
      jobs = jobs->next;
    }
    
    jobs->next = new_job;
  }
}

int main () 
{ 
  init_jobs ();
  
  pthread_t thread1; 
  pthread_t thread2; 
  
  pthread_create (&thread1, NULL, &thread_function, NULL); 
  pthread_create (&thread2, NULL, &thread_function, NULL); 


  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0; 
} 