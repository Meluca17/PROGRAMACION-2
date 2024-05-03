#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    struct nodo *ant; // ant es la dirección del nodo anterior
    Elemento elem;  // el dato que almacena el nodo
    struct nodo *sig;  // sig es la dirección del siguiente nodo
} Nodo;

typedef struct
{
    Nodo *cabeza; // cabeza almacena la direccion del primer nodo de la lista
    int longitud; // cantidad de nodos de la lista
} ListaD;

void construir( ListaD &Ld );
bool esListaVacia( ListaD Ld );
Nodo* crearNodo( Nodo *a, Elemento e, Nodo *s );
int obtenerLongitud( ListaD Ld );
void insertarComienzo( ListaD &Ld, Elemento e );
void mostrar( ListaD Ld );
Nodo* ubicarUltimo( ListaD Ld );
void mostrarReves( ListaD Ld );
void insertarFinal( ListaD &Ld, Elemento e );
Nodo* ubicar( ListaD Ld, Elemento e );
void eliminar( ListaD &Ld, Elemento e);
void destruir( ListaD &Ld );
void insertarOrdenado(ListaD& Ld, Elemento e);

#endif /* LISTADOBLE_H */