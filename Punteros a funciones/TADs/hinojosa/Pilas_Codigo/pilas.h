/* 
 * Proyecto: Pilas_Codigo
 * Archivo:   pilas.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 22 de septiembre de 2023, 17:04
 */

#ifndef PILAS_H
#define PILAS_H

#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoP *sig;  // sig es la direcciÃ³n del siguiente nodo
} NodoP;

typedef struct
{
    NodoP *cima; // cima almacena la direccion del primer nodo de la pila
    int longitud; // cantidad de nodos de la pila
} Pila;



void construir( Pila &P );
bool esPilaVacia( Pila P );
NodoP* crearNodoPila( Elemento e, NodoP *s );
void apilar( Pila &P, Elemento e );
void mostrar(Pila P);
Elemento desapilar(Pila &P);
void destruir( Pila &P );
Pila copiar(Pila &P);


#endif /* PILAS_H */

