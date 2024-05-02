/* 
 * Proyecto: Cola_Funciones
 * Archivo:   cola.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de septiembre de 2023, 14:23
 */

#include <iostream>
#include <iomanip>
#include <type_traits> 
using namespace std;
#include "cola.h"

void construir(Cola &C){
    C.fin = NULL; 
    C.frente = NULL;
    C.longitud = 0;
    
}


bool esColaVacia(Cola C){
    return C.longitud ==0;
    //return C.final == NULL;
    //return C.frente == NULL;
}

NodoC *crearNodoCola(Elemento e, NodoC *sig){
    NodoC *p;
    p = new NodoC;
    
    p ->elem = e;
    p->sig = sig; 
    
    return p; 
}

int obtenerLongitud(Cola C){
    return C.longitud;
}

void encolar(Cola &C,Elemento e){
    //cuando encolamos se añade un elemento al final de la cola
    NodoC *p, *pU; 
    p = crearNodoCola(e,NULL);
    
    if(esColaVacia(C)){
        //si la cola esta vacia es el inicio y es el fin
        C.frente = p; 
//        C.fin = p;
//        C.longitud++;
    }else{
        pU = C.fin; 
        pU->sig = p; 
//        C.fin = p; 
//        C.longitud ++;
    }
    C.fin = p;
    C.longitud++;
}

void mostrar(Cola C){
    //como muestro la cola???
    NodoC *p; 
    if(esColaVacia(C)){
        cout <<"La cola esta vacia"<<endl;
    }else{
        p= C.frente;
        while(p!=NULL){
            cout <<p->elem<<" ";
            p = p->sig;
        }
        cout <<endl;
    }
}

//SOLO SI LA COLA NO ESTA VACIA
//funcion que DESENCOLA UN ELEMENTO (del inicio ), tmb devuelve el valor
Elemento desencolar(Cola &C){ //retorna un dato del tipo Elemento
    Elemento x; 
    NodoC *p; 
    
    p = C.frente; //apunta al primer elemento (el que queremos eliminar) 
    
    //EN CASO LA COLA SOLO TENGA UN NODO
    if(p->sig ==NULL){
        C.fin =NULL; 
    }
    
    x = p->elem;
    C.frente = p->sig; 
    C.longitud--; 
    
    delete p; 
    return x; 
}

void destruir(Cola &C){
    //quiero destruir toda la cola:)), para ello debo recorrerla 
    NodoC *p, *q; //q
    
    if(!esColaVacia(C)){ //si la lista no esta vacia se puede destruir
        p = C.frente; 
        while(p!=NULL){
            q = p->sig; 
            delete p; 
            p = q; 
        }
        C.fin = NULL;
        C.frente = NULL;
        C.longitud = 0;
    }
}

Cola copiar(Cola cOriginal){
    NodoC *p;
    Elemento e; 
    Cola cCopia; 
    
    construir(cCopia);
    p = cOriginal.frente; 
    
    while(p!=NULL){
        e = p->elem; 
        encolar(cCopia,e);
        p = p->sig; 
    }
    
    return cCopia; 
}






