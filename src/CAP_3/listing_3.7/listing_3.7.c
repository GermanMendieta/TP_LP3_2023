#include <signal.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>


sig_atomic_t child_exit_status;

void clean_up_child_process (int signal_number) 
{ 
  /* Clean up the child process. */ 
  int status; 
  wait(&status); 
  printf("The child process finished! The handler will clean up this place\n");
  /* Store its exit status in a global variable. */ 
  child_exit_status = status; 
} 

int main () 
{ 
  /* Handle SIGCHLD by calling clean_up_child_process. */ 
  struct sigaction sigchld_action; 
  memset (&sigchld_action, 0, sizeof(sigchld_action)); 
  sigchld_action.sa_handler = &clean_up_child_process; 
  sigaction (SIGCHLD, &sigchld_action, NULL); 
  /* Now do things, including forking a child process. */
  /* do something */
  pid_t child_pid = fork (); 
  if (child_pid > 0) { 
    /* This is the parent process. Sleep for a minute. */ 
    sleep (60); 
  } else { 
    printf("Child process: Hi, am working here!\n");
    sleep(2);
    /* This is the child process. Exit immediately. */ 
    exit (0); 
  } 
   printf("The child exit status was: %d \n", child_exit_status);
  /* ... */ 
  return 0; 
}