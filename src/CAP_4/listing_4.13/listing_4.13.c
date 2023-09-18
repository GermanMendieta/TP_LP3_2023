#include <pthread.h>
#include <stdio.h>
int thread_flag;
pthread_mutex_t thread_flag_mutex;
pthread_key_t thread_log_key;
int contador = 0;
void close_thread_log(void *thread_log)
{
    fclose((FILE *)thread_log);
}
/* Sets the value of the thread flag to FLAG_VALUE. */
void set_thread_flag(int flag_value)
{
    /* Protect the flag with a mutex lock. */
    pthread_mutex_lock(&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_mutex_unlock(&thread_flag_mutex);
}
void initialize_flag()
{
    pthread_mutex_init(&thread_flag_mutex, NULL);
    thread_flag = 2;
}
/* Calls do_work repeatedly while the thread flag is set; otherwise
spins. */
void do_work()
{
    printf("%d\n", thread_flag);
    set_thread_flag(0);
}
void *thread_function(void *thread_arg)
{
    while (1)
    {
        int flag_is_set;
        /* Protect the flag with a mutex lock. */
        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;
        pthread_mutex_unlock(&thread_flag_mutex);
        if (flag_is_set)
            do_work();
        else
            break;
        /* Else don’t do anything. Just loop again. */
    }
    return NULL;
}

int main()
{
    int i;
    initialize_flag();
    pthread_t threads[5];
    /* Create a key to associate thread log file pointers in
    thread-specific data. Use close_thread_log to clean up the file
    pointers. */
    pthread_key_create(&thread_log_key, close_thread_log);
    /* Create threads to do the work. */
    for (i = 0; i < 5; ++i)
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    /* Wait for all threads to finish. */
    for (i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);
    return 0;
}