#include <pthread.h> 
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 
/* Allocate a temporary buffer. */ 
void* allocate_buffer (size_t size) 
{ 
  return malloc (size); 
} 
/* Deallocate a temporary buffer. */ 
void deallocate_buffer (void* buffer) 
{ 
  free (buffer);   
} 
void do_some_work () 
{ 
  /* Allocate a temporary buffer. */ 
  void* temp_buffer = allocate_buffer (1024); 
  /* Register a cleanup handler for this buffer, to deallocate it in case the thread exits or is cancelled. */ 
  pthread_cleanup_push (deallocate_buffer, temp_buffer); 
  /* Do some work here that might call pthread_exit or might be cancelled... */ 
  printf("\nCleaning up this place!");
  for (int i= 0; i < 10; ++i){
    sleep(1);
  }
  printf("\n");
  /* Unregister the cleanup handler. Because we pass a nonzero value, this actually performs the cleanup by 
    calling deallocate_buffer. */ 
  pthread_cleanup_pop (1); 
} 

/* BASED ON LISTING 4.10*/


/* An array of balances in accounts, indexed by account number. */ 
float* account_balances; 
/* Transfer DOLLARS from account FROM_ACCT to account TO_ACCT. Return 
 0 if the transaction succeeded, or 1 if the balance FROM_ACCT is 
 too small. */ 
int process_transaction (int from_acct, int to_acct, float dollars) 
{ 
  int old_cancel_state; 
  /* Check the balance in FROM_ACCT. */ 
  if (account_balances[from_acct] < dollars) 
    return 1; 
  
  /* Begin critical section. BUT IS ABLE TO CANCEL*/ 
  /* Move the money. */ 
  account_balances[to_acct] += dollars; 
  do_some_work();
  account_balances[from_acct] -= dollars; 
  /* End critical section. */ 
  
  printf("\nTransaction was successfully finished!\n");
  return 0; 
} 

void* thread_method (void* arg) 
{ 
  if ( process_transaction(((int *)arg)[0], ((int *)arg)[1], 10000.0)){
    printf("\nTransaction was interrupted!\n");
    sleep(1);
  }
  return NULL; 
} 
int main () 
{ 
  pthread_t thread; 
  float acounts [] = {10000.0, 0.0};
  printf("\nAcount A: %.2f \nAcount B: %.2f \n", acounts[0], acounts[1]);
  account_balances = acounts;
  int args [] = {0, 1};
  pthread_create (&thread, NULL, &thread_method, (void *) args); 
  /* Do some other work here... */ 
  sleep(5);
  
  // try to cancel the thread
  pthread_cancel(thread);

  //print the actual state of acounts
  printf("\nAcount A: %.2f \nAcount B: %.2f \n", acounts[0], acounts[1]);
  return 0; 
} 