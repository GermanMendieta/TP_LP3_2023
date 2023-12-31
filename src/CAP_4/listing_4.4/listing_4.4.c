#include <pthread.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
/* Compute successive prime numbers (very inefficiently). Return the 
 Nth prime number, where N is the value pointed to by *ARG. */ 
void* compute_prime (void* arg) 
{ 
  int candidate = 2; 
  int n = *((int*) arg);
  int * res = (int *) malloc(sizeof(candidate));
  while (1) { 
    int factor; 
    int is_prime = 1; 
    /* Test primality by successive division. */ 
    for (factor = 2; factor < candidate; ++factor) 
      if (candidate % factor == 0) { 
        is_prime = 0; 
      break; 
    } 
    /* Is this the prime number we're looking for? */ 
    if (is_prime) { 
      if (--n == 0) {  
        /* Return the desired prime number as the thread return value. */ 
        *res = candidate;
        return ((void*) res); 
      }
    } 
   ++candidate; 
  } 
  return NULL; 
} 
int main () 
{ 
  pthread_t thread; 
  int which_prime = 5000; 
  void * prime; 
  /* Start the computing thread, up to the 5,000th prime number. */ 
  pthread_create (&thread, NULL, &compute_prime, &which_prime); 
  /* Do some other work here... */ 
  sleep(2);
  /* Wait for the prime number thread to complete, and get the result. */ 
  pthread_join (thread, &prime); 
  /* Print the largest prime it computed. */ 
  printf("The %dth prime number is %d.\n", which_prime, *((int *) prime)); 
  return 0; 
} 