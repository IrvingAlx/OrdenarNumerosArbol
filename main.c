#include "defTipos.h"

nodo *insertarNodoArbol(nodo *pt, int numero);
void recorrer(nodo *pt);

int main(int argc, char *argv[])
{
  int numero = 0;
	nodo *raiz;
  FILE *fp;
  raiz = NULL;
  remove("pares.txt"); 

  fp = fopen(argv[1], "r");
  if(fp == NULL)
   {
     printf("\nArchivo no disponible.\n");
     exit(1);
   }
  while(fscanf(fp, " %d", &numero) == 1)
   {
     raiz = insertarNodoArbol(raiz, numero);
   }
  fclose(fp);



 recorrer(raiz); //Es para revisar el árbol creado

	

  return 0;
}
