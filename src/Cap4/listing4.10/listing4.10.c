#include <pthread.h> 
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 

#define MAX_JOBS 3

/* Time job*/
int time = 2;


struct job { 
/* Link field for linked list. */
  int n_job;
  struct job* next; 
  /* Other fields describing work to be done... */ 
}; 
/* A linked list of pending jobs. */ 
struct job* job_queue; 

void process_job (struct job* jobs){
  printf("Job %dth finished", jops->n_job );
  sleep (time);
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
  int n = 0;
  while (n++ < MAX_JOBS){
    struct job* next_job = (struct job* ) malloc (sizeof(struct job));
  }
}

int main () 
{ 
  init_jobs ();
  
  pthread_t thread1; 
  pthread_t thread2; 
  
  pthread_create (&thread1, NULL, &thread_function, NULL); 
  pthread_create (&thread1, NULL, &thread_function, NULL); 


  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0; 
} 