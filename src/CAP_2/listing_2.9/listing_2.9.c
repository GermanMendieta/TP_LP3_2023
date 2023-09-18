#include <stdio.h>
// #include <tiff.h>

// hay que espeficar la ruta del archivo
int main (int argc, char** argv) 
{ 
  FILE* tiff; 
  tiff = fopen (argv[1], "r"); 
  fclose(tiff); 
  return 0; 
}