#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int, int *, int *, int *);

int main ()
{
    int raiz, mayor = 0, cant_hoj_impares = 0, cant_nodos_pares = 0;

    printf ("Parcial 2 \n");
    treenode* arbol=NULL;

    crear (&arbol);
    raiz = arbol->dato;

    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &mayor, &cant_hoj_impares, &cant_nodos_pares);
    printf("\nEl mayor elemento multiplo de la raiz es %d",mayor);
    printf("\n La cantidad de nodos hojas impares es %d y nodos pares son %d", cant_hoj_impares, cant_nodos_pares);

    return 0;
}
void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{

        if (numero>(*hoja)->dato)
        {
            insertar (&(*hoja)->der,elem);
        }
        else
        {
            insertar (&(*hoja)->izq,elem);
        }
    }

    return;
}

void mostrar (treenode *hoja, int raiz, int *mayor, int *cant_hoj_impares, int *cant_nodos_pares)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, mayor, cant_hoj_impares, cant_nodos_pares);

        if (hoja->dato%raiz==0 && hoja->dato!=raiz && hoja->dato > *mayor) {
            *mayor = hoja->dato;
        }

        if (hoja->dato%2 == 0) {
            *cant_nodos_pares = *cant_nodos_pares+1;
        }

        if (hoja->izq==NULL && hoja->der==NULL && hoja->dato%2!=0)
        {
            *cant_hoj_impares = *cant_hoj_impares+1;
        }

        printf("%d ",hoja->dato);
        mostrar(hoja->der, raiz, mayor, cant_hoj_impares, cant_nodos_pares);
    }
    return;
}
