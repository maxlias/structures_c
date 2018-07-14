#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

nodo* crear_nodo(int );
void mostrar_cola (nodo aux, int *, int *);
void acolar(nodo** p,nodo** u, nodo *q);
nodo desacolar(nodo** inicio);

int main()
{
   int i,num, sumatoria = 0, cant_elementos = 0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));
   }

   printf("\nVamos a desacolar todo\n");

   while(p!=NULL)
   {
    	mostrar(desacolar(&p), &sumatoria, &cant_elementos);
   }

   if (cant_elementos > 0)
   {
       printf("El promedio de los elementos que son mayores a 6 es %d", sumatoria/cant_elementos);
   }
   else
   {
       printf("No existen elementos mayores a 6 en la cola para calcular el promedio");
   }

   return 0;
}

void mostrar (nodo aux, int *sumatoria, int *cant_elementos)
{
  	printf("%d \n", aux.dato);

  	if (aux.dato > 6)
    {
        *sumatoria = *sumatoria + aux.dato;
        *cant_elementos = *cant_elementos + 1;
    }
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}


