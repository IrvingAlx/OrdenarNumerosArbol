#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
{
  int num;
  struct elemento *izq, *der;
};
typedef struct elemento nodo;