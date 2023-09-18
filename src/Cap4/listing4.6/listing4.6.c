#include <pthread.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 
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
  
  /* Begin critical section. */ 
  pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state); 
  /* Move the money. */ 
  account_balances[to_acct] += dollars; 
  printf("\nTransaction was successfully finished!\n");
  sleep(5);
  account_balances[from_acct] -= dollars; 
  /* End critical section. */ 
  pthread_setcancelstate (old_cancel_state, NULL); 
  
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
  sleep(4);
  // try to cancel the thread
  pthread_cancel(thread);
  pthread_join (thread, NULL); 

  //print the actual state of acounts
  printf("\nAcount A: %.2f \nAcount B: %.2f \n", acounts[0], acounts[1]);
  return 0; 
} 