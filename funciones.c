#include "defTipos.h"

void guardarDato(int par);

extern nodo *insertarNodoArbol(nodo *pt, int numero)
{
  nodo *nuevo, *aux;

  aux = pt;
  int salir = 1;
  nuevo = (nodo *)malloc(sizeof(nodo));
  if(nuevo == NULL)
   {
    printf("\nNo hay memoria disponible.\n\n");
    exit(1);
   }
  nuevo->num = numero;
  nuevo->izq = NULL;
  nuevo->der = NULL;

  if(aux == NULL) pt = nuevo;
  while((aux != NULL)&&(salir != 0))
   {
     if(numero >  aux->num) //Mover a la derecha
      {
        if(aux->der != NULL) aux = aux->der;
        else
         {
           
           aux->der = nuevo;
           salir = 0;
         }
      }
     if(numero <= aux->num) //Mover a la izquierda
      {
        if(aux->izq != NULL) aux = aux->izq;
        else
         {
          // aux->rep=aux->rep+1;
           aux->izq = nuevo;
           salir = 0;
         }
      }

   }
  return pt;
}


extern void recorrer(nodo *aux) //En orden ascendente
{
if(aux != NULL)
 {
  recorrer (aux->izq);
  printf("%d\n", aux->num);
  guardarDato (aux->num);
  recorrer (aux->der);
 }
return;
}

extern void guardarDato(int par)
{
  FILE *fp;

  fp = fopen("pares.txt", "a");

  if(fp == NULL)
    {
      printf("\nArchivo no encontrado.");
      exit(1);
    }
	if (par % 2 == 0) 
	{
  	fprintf(fp, "%d\n", par);
  }
	
  fclose(fp);

  return;
}
