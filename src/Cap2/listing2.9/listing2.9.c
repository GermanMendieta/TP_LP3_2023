#include <stdio.h>
#include <tiff.h>

int main (int argc, char** argv) 
{ 
  TIFF* tiff; 
  tiff = TIFFOpen (argv[1], "r"); 
  TIFFClose (tiff); 
  return 0; 
}