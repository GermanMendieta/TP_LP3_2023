#include <malloc.h>
#include <pthread.h>
struct job
{
    /* Link field for linked list. */
    struct job *next;
    int number;
    /* Other fields describing work to be done... */
};
/* A linked list of pending jobs. */

struct job *job_queue;
/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
/* Process queued jobs until the queue is empty. */
void process_job(struct job * trabajo){

    printf("%d - ", trabajo->number);
    

}
void *thread_function(void *arg)
{
    while (1)
    {
        struct job *next_job;
        /* Lock the mutex on the job queue. */
        pthread_mutex_lock(&job_queue_mutex);
        /* Now it’s safe to check if the queue is empty. */
        if (job_queue == NULL)
            next_job = NULL;
        else
        {
            /* Get the next available job. */
            next_job = job_queue;
            /* Remove this job from the list. */
            job_queue = job_queue->next;
        }
        /* Unlock the mutex on the job queue because we’re done with the
        queue for now. */
        pthread_mutex_unlock(&job_queue_mutex);
        /* Was the queue empty? If so, end the thread. */
        if (next_job == NULL)
            break;
        /* Carry out the work. */

        process_job(next_job);
        /* Clean up. */
        free(next_job);
        
    }
    return NULL;
}
int main(void)
{
    int i = 0;

    for (i = 0; i < 10; ++i)
    {
        struct job *new_job = (struct job *)malloc(sizeof(struct job));
        new_job->number = i;
        new_job->next = job_queue;
        job_queue = new_job;
    }

    pthread_t threads[5];
    /* Create threads to do the work. */

    for (i = 0; i < 5; ++i)
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    /* Wait for all threads to finish. */

    for (i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);

    return 0;
}
