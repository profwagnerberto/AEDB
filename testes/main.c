#include <stdio.h>
#include <stdlib.h>

const int CL = 3;
const int CC = 5;

int main(){
//  char v[CL][CC];
  int l,c = CL,teste = 'A',i;
  char* p;
  p = (char*) malloc (c * sizeof(char[CC]));

  *p = 'A';
  p+=CC;
  *p = 'B';
  p+=CC;

  p-=CC;
  printf("%d-%c \n",*p,*p);
  p-=CC;
  printf("%d-%c \n",*p,*p);


/*
  for(i = 0; i < CL * CC; i++){
    *p = 'A';
    p++;
  }
*/

/*
  p-=25;

  for(i = 0; i < CL * CC; i++){
    printf("%d-%c \n",*p,*p);
    p++;
  }
*/

/*
  for(l = 0; l < CL; l++){
    for(c = 0; c < CC; c++)
      v[l][c] = teste + c;
    teste += 10;
  }

  for(l = 0; l < CL; l++){
    for(c = 0; c < CC; c++)
      printf("%d-%c \t",v[l][c],v[l][c]);
    printf(" \n");
  }

  printf(" \n");

  p = &v[0][0];
  for(i = 0; i < CL * CC; i++){
    printf("%d-%c \n",*p,*p);
    p++;
  }
*/

  return 0;
}