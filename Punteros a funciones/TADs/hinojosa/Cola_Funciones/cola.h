/* 
 * Proyecto: Cola_Funciones
 * Archivo:   cola.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de septiembre de 2023, 14:23
 */

#ifndef COLA_H
#define COLA_H
#include <iostream>
using namespace std;


typedef int Elemento;

typedef struct nodoC{
    Elemento elem;
    struct nodoC *sig;
}NodoC;

typedef struct{
    //debe tener dos punteros que apuenten al inciio y el final
    NodoC *frente;
    NodoC *fin; 
    int longitud;
}Cola;

void construir(Cola &C);
bool esColaVacia(Cola C);
NodoC *crearNodoCola(Elemento e, NodoC *sig);
int obtenerLongitud(Cola C);
void encolar(Cola &C,Elemento e);
void mostrar(Cola C);
Elemento desencolar(Cola &C);
void destruir(Cola &C);
Cola copiar(Cola cOriginal);


#endif /* COLA_H */

