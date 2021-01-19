//
//  listaTexto.h
//  Lista estatica
//
//  Created by Arturo Tamayo Gonzalez on 17/10/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura para almacenar los datos de una lista de platillos

struct MiLista{
    char* platillos[100];
    int posicionActual;
    int MAX_PLATILLOS;
    };
typedef struct MiLista Lista;

//Creacion de una lista de platillos
Lista lista_crear(){
    Lista lista;
    lista.posicionActual = 0;
    lista.MAX_PLATILLOS = 100;
    return lista;
}

//Aregar platillos a la lista
void lista_agregar (Lista* lista, char* platillo){
    if( lista->posicionActual < lista->MAX_PLATILLOS){
        lista->platillos [lista->posicionActual] = platillo;
        lista->posicionActual++;
    }
}

//imprimir lista de platillos
void lista_imprimir (Lista lista){
    int i;
    printf("Contenido de la lista de platillos\n");
    for(i=0; i<lista.posicionActual;i++){
        printf("%s\n", lista.platillos[i]);
    }
}

//Insertar platillo en una posicion dada
void lista_insertar(Lista* lista, char* platillo, int posicion){
    int i;
    if(lista->posicionActual < lista->MAX_PLATILLOS){
        if (posicion >=0 && posicion < lista->posicionActual){
            //Mover los platillos a la derecha del lugar a insertar
            for(i=lista->posicionActual; i>posicion; i--){
                lista->platillos[i] = lista->platillos[i-1];
            }
            //Insertar platillo
            lista->platillos[posicion] = platillo;
            lista->posicionActual ++;
        }
        else{
            printf("Posicion invalida\n");
        }
    }
    else{
        printf("Lista llena. Maximo de platillos alcanzado\n");
    }
}

//Borrar un platillo desde posicion
void lista_borrar(Lista* lista, int posicion){
    int i;
    if(posicion >=0 && posicion < lista->posicionActual){
        for(i=posicion; i<lista->posicionActual; i++){
            lista->platillos[i] = lista->platillos[i+1];
        }
        lista->posicionActual--;
    }
    else{
        printf("Posicion invalida\n");
    }
}

//Borrar toda la lista de platillos
void lista_borrarTODO(Lista* lista){
    int i;
    for(i=0; i<lista->posicionActual;i++){
        lista->platillos[i] = 0;
    }
    lista->posicionActual =0;
}

//Buscar la posicion de un platillo
int lista_buscarPosicion(Lista lista, char* platillo){
    int i;
    for(i=0; i<lista.posicionActual; i++){
        if (strcmp(platillo, lista.platillos[i])==0){
            return i;
        }
    }
    return -1;
}

//Buscar el platillo en la posicion dada
int lista_buscarPlatillo (Lista lista, int posicion){
    if(posicion >=0 && posicion < lista.posicionActual){
        return *lista.platillos[posicion];
    }
    return -1;
}
//Reemplazar platillo
char* lista_reemplazar(Lista* lista, char* platillo, char*platillonuevo){
    int i;
    for(i=0; i<lista->posicionActual; i++){
        if(strcmp(platillo, lista->platillos[i])==0){
            strcpy(lista->platillos[i],platillonuevo);
            return platillo;
        }
    }
    return 0;
}
//Mostrar el platillo siguiente
char* lista_siguiente(Lista lista , char* platillo){
    int i;
    for(i=0; i<lista.posicionActual ; i++){
        if (strcmp(platillo, lista.platillos[i])==0){
            return lista.platillos[i+1];
        }
    }
    return platillo;
}
//Mostrar el platillo anterior
char* lista_anterior(Lista lista, char* platillo){
    int i;
    for(i=0; i<lista.posicionActual; i++){
        if (strcmp(platillo, lista.platillos[i])==0){
            return lista.platillos[i-1];
        }
    }
    return platillo;
}
//Mostrar el primer platillo de la lista
char* lista_primero(Lista lista){
    return lista.platillos[0];
}

















