/* 
 * Proyecto: Pilas_Codigo
 * Archivo:   pilas.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 22 de septiembre de 2023, 17:04
 */

#include <iostream>
#include <iomanip>
#include <csetjmp>
#include <ratio> 
using namespace std;
#include "pilas.h"

void construir( Pila &P )
{
    // se crea la pila vacia
    P.cima = NULL;
    P.longitud = 0;
}

bool esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return P.longitud == 0;
}

NodoP* crearNodoPila( Elemento e, NodoP *s )
{
    NodoP *p;
    p = new NodoP; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void apilar( Pila &P, Elemento e )
{
    NodoP *p;
    p = crearNodoPila( e, P.cima );
    P.cima = p;
    P.longitud++;
}

void mostrar( Pila P )
{
    //como hago para mostrar los elementos de una pila????
    NodoP *p; 
    p = P.cima; 
    
    if(esPilaVacia(P)){
        cout <<" No se puede imprimir una pila vacia "<<endl; 
    }else{
//        while(p != NULL){
//            cout <<p->elem<<" ";
//            p  = p->sig;
//        }
//        cout <<endl;
        for(int i=1; i<=P.longitud; i++)
        {
            cout << p->elem << endl;
            p = p->sig;
        }
        cout << endl;
    }

}

//FUNCION DESAPILAR -> devuelve el valor desapilado
//                  & -> la pila cambia!!
Elemento desapilar(Pila &P){
    //se desaila el primer elemento de la pila
    Elemento e; 
    NodoP *p; 
    
    p = P.cima; 
    e = p->elem; 
    
    P.cima = p->sig; 
    P.longitud --; 
    
    //borramos el puntero usado 
    delete p;
    return e; //retornamos el elemento desapilado
}

//quiero destruir la pila creada
void destruir( Pila &P ){
    NodoP *p, *q; //q guardara el sgte valor de p
    p = P.cima; 
    //vamos a recorrer la pila para eliminar los punteros
    if(!esPilaVacia(P)){ // se puede destruir solo si tiene elementos
        
//        while(p!=NULL){
//            q = p->sig; //guarda el siguiente valor de q
//            //borramos p
//            delete p;
//            p = q;
//        }
        
        for(int i=1; i<P.longitud-1; i++){
            q = p->sig;
            delete p;
            p = q; 
        }
        
        
        P.cima = NULL; 
        P.longitud = 0; 
    }
}

//PARA COPIAR UNA PILA EN OTRA
Pila copiar(Pila &P){
    Pila Q, R;
    Elemento x;
    construir(Q);
    construir(R);
    
    while(!esPilaVacia(P)){ //la lista de entrada
        //desapilamos el elemento en P1
        x = desapilar(P);
        //apilamos el elemento en P2
        apilar(Q,x);
    }
    
    //Q es una PILA AUXILIAR 
    while(!esPilaVacia(Q)){
        x = desapilar(Q);
        apilar(R,x); //apilamos en la pila COPIA
        apilar(P,x); //apilamos en la pila ORIGINAL
    }
    return R;
}




