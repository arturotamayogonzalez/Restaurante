//
//  main.c
//  Lista estatica
//
//  Created by Arturo Tamayo Gonzalez on 17/10/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//

#include "listasTexto.h"
#define EXIT 12

void mostrarMenu();
int seleccionarOpcion();
void ejecutarOpcion(Lista* miLista, int opcion);


int main(){
    Lista miLista;
    int opcion;
    
    miLista = lista_crear();
    do{
        mostrarMenu();
        opcion = seleccionarOpcion();
        ejecutarOpcion(&miLista, opcion);
    }while (opcion != EXIT);
                       
}
void mostrarMenu(){
    printf("------LISTA DE TUS PLATILLOS FAVORITOS------\n");
    printf("1.- Agregar platillo\n");
    printf("2.- Imprimir lista de platillos\n");
    printf("3.- Insertar platillo\n");
    printf("4.- Borrar platillo\n");
    printf("5.- Borrar lista de platillos\n");
    printf("6.- Buscar platillo\n");
    printf("7.- Buscar lo posicion en que se encuentra tu platillo\n");
    printf("8.- Reemplazar platillo\n");
    printf("9.- Siguiente platillo\n");
    printf("10.- Platillo anterior\n");
    printf("11.- Primer platillo de la lista\n");
    printf("%d.- SALIR\n", EXIT);
}
    
int seleccionarOpcion(){
    int opcion;
        printf("\tOpcion: ");
        scanf("%d", &opcion);
        getchar();
     
    return opcion;
}
void ejecutarOpcion (Lista* miLista , int opcion){
    char* platillo;
    char* platillonuevo;
    char* siguiente;
    char* anterior;
    char* primero;
    int posicion, buscar;
    
    
    platillo = malloc(sizeof(char)*100);
    platillonuevo = malloc(sizeof(char)*100);
    siguiente= malloc(sizeof(char)*100);
    anterior = malloc(sizeof(char)*100);
    primero = malloc(sizeof(char)*100);
    
    switch (opcion) {
        case 1:
            printf ("Platillo a agregar: ");
            fgets(platillo, 100, stdin);
            lista_agregar(miLista, platillo);
            break;
        case 2:
            lista_imprimir(*miLista);
            break;
        case 3:
            printf("Platillo a insertar:  ");
            fgets(platillo, 100, stdin);
            printf("Posicion en la que desea insertar el platillo:  ");
            scanf("%d", &posicion);
            lista_insertar(miLista, platillo, posicion);
            break;
        case 4:
            printf("Posicion del platillo que desea eliminar:  ");
            scanf("%d", &posicion);
            getchar();
            lista_borrar(miLista, posicion);
            break;
        case 5:
            lista_borrarTODO(miLista);
            getchar();
            break;
        case 6:
            printf("Posicion del platillo que desea buscar:  ");
            scanf("%d", &posicion);
            getchar();
            lista_buscarPlatillo (*miLista, posicion);
            printf("Platillo encontraro: %s\n", miLista->platillos[posicion]);
            getchar();
            break;
        case 7:
            printf("Platillo que desea buscar:  ");
            fgets(platillo, 100, stdin);
            buscar = lista_buscarPosicion(*miLista, platillo);
            if(buscar==-1)
                printf("Ese platillo no existe\n");
            else
                printf("La posicion del platillo es: %d\n", buscar);
            break;
        case 8:
            printf("Platillo que deseas reemplazar:  ");
            fgets(platillo, 100, stdin);
            printf("Platillo nuevo:  ");
            fgets(platillonuevo, 100, stdin);
            lista_reemplazar(miLista, platillo, platillonuevo);
            break;
        case 9:
            printf("Platillo del que quisieras saber el siguiente:  ");
            fgets(platillo, 100, stdin);
            siguiente = lista_siguiente(*miLista, platillo);
            if(siguiente == platillo)
                printf("EL platillo no existe\n");
            else
                printf("EL platillo siguiente es: %s\n", siguiente);
            getchar();
            break;
        case 10:
            printf("Platillo del que quisieras saber el anterior:  ");
            fgets (platillo, 100, stdin);
            anterior = lista_anterior(*miLista, platillo);
            if(anterior == platillo)
                printf("No existe el platillo");
            else
                printf("El platillo anterior es: %s\n", anterior);
            getchar();
            break;
        case 11:
            primero = lista_primero(*miLista);
            printf("El primer platillo de tu lista es: %s\n", primero);
            getchar();
            break;
        case 12:
            break;
    }
    
                       }
