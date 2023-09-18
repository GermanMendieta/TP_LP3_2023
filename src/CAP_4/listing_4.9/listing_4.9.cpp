#include <pthread.h>
#include <stdio.h>
class ThreadExitException
{
public:
    /* Create an exception-signaling thread exit with RETURN_VALUE. */
    static int i;
    ThreadExitException(void *return_value)
        : thread_return_value_(return_value)
    {
    }
    /* Actually exit the thread, using the return value provided in the
    constructor. */
    void *DoThreadExit()
    {
        pthread_exit(thread_return_value_);
    }

private:
    /* The return value that will be used when exiting the thread. */
    void *thread_return_value_;
};

int ThreadExitException::i = 0;
bool should_exit_thread_immediately()
    {
        return (ThreadExitException::i >= 5);
    }
void do_some_work()
{
    while (1)
    {
        /* Do some useful things here... */
        printf("%d - ", ThreadExitException::i++);
        if (should_exit_thread_immediately())
            throw ThreadExitException(/* thread’s return value = */ NULL);
    }
}
void *thread_function(void *)
{
    try
    {
        do_some_work();
    }
    catch (ThreadExitException ex)
    {
        /* Some function indicated that we should exit the thread. */
        ex.DoThreadExit();
    }
    return NULL;
}
int main(void)
{
    int i;
    pthread_t threads[5];
    /* Create threads to do the work. */
    for (i = 0; i < 5; ++i)
        pthread_create(&(threads[i]), NULL, thread_function, NULL);
    /* Wait for all threads to finish. */
    for (i = 0; i < 5; ++i)
        pthread_join(threads[i], NULL);
    return 0;
}
