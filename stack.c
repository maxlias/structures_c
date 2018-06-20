#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar_pila (nodo, int, int *);
nodo* crear_nodo(int );
void apilar(nodo** , nodo*);
nodo desapilar(nodo**);

int main()
{
   int i,num, primero, productoria = 1;
   nodo* p=NULL;

   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);

    if(i == 0)
    {
        primero = num;
    }

   	apilar(&p, crear_nodo(num));
   }

   printf("el primero es %d", primero);
   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), primero, &productoria);
   }

   if(productoria > 0)
   {
       printf("\nLa productoria de los numeros multiplos del primer elemento ingresado es de %d\n",productoria);
   }
   else
   {
       printf("\nNo hay numeros multiplos del primer elemento para realizar la productoria");
   }

   return 0;
}

void mostrar (nodo aux, int primero, int *productoria)
{
    printf("%d \n", aux.dato);

    if (aux.dato != primero && aux.dato%primero == 0)
    {
      *productoria = *productoria * aux.dato;
    }
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");

  	u->siguiente = *p;
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}


