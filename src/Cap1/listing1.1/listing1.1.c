#include <stdio.h> 
#include <stdlib.h>
#include "../listing1.2/listing1.2.cpp" 

int main (int argc, char **argv) 
{ 
 int i; 
 i = atoi (argv[1]); 
 printf ("The recipcrocal of %d is %g\n", i, reciprocal (i)); 
  
 return 0;
} 