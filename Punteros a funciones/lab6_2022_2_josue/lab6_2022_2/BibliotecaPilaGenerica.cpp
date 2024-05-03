/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistro.h"
enum pila {CIMA,CANT};
enum nodo {SIG,DAT};
void cargaarrelo(void *&arreglo,int (*cmpnumero)(const void*,const void*),
        void *(*leenumero)(ifstream &),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    void *dato,*buffArreglo[100]{};
    int cant=0,*val;
    while(true){
        dato=leenumero(arch);
        if(arch.eof())break;
        buffArreglo[cant]=dato;
        cant++;
    }
    void **nuevoBuff=new void*[cant+1]{};
    for(int i=0;i<cant;i++){
        nuevoBuff[i]=buffArreglo[i];
    }
    arreglo=nuevoBuff;
    //ordenamos la pila de mayor a menor
    qsort(arreglo,cant,sizeof(void *),cmpnumero);
}


void cargapila(void *&pilaini,void *arreglo){
    construyePila(pilaini);
    void **auxArreglo=(void **)arreglo;
    int cant=0;
    while(auxArreglo[cant]){
        push(pilaini,auxArreglo[cant]);
        cant++;
    }
}

void push(void *&pilaini,void *dato){
    void **pila=(void **)pilaini,**nodo=new void*[2];
    nodo[DAT]=dato;
    nodo[SIG]=pila[CIMA];
    pila[CIMA]=nodo;
    int *cantDatos=(int *)pila[CANT];
    (*cantDatos)++;
}


bool pilavacia(void *pila){
    void **pilaAux=(void **)pila;
    if(pilaAux[CIMA]==nullptr){
        return true;
    }
    else{
        return false;
    }
}
void construyePila(void *&pilaini){
    void **nuevaPila=new void*[2];
    int *cantDatos=new int;
    *cantDatos=0;
    nuevaPila[CIMA]=nullptr;
    nuevaPila[CANT]=cantDatos;
    pilaini=nuevaPila;
}

void muevepila(void *&pilaini,void *&pilafin){
    void *aux,**inicial=(void **)pilaini;
    int cantDatos=*(int *)inicial[CANT];
    construyePila(pilafin);
    construyePila(aux);
    hanoi(cantDatos,pilaini,aux,pilafin);
}

void hanoi(int cantDatos,void *pilaini,void *aux,void *pilafin){
    void *dato;
    if(cantDatos==1){
        dato=pop(pilaini);
        push(pilafin,dato);
    }
    else{
        hanoi(cantDatos-1,pilaini,pilafin,aux);
        dato=pop(pilaini);
        push(pilafin,dato);
        hanoi(cantDatos-1,aux,pilaini,pilafin);
    }
}

void *pop(void *pila){
    void **auxPila=(void **)pila,**auxNodo;
    auxNodo=(void **)auxPila[CIMA];
    if(pilavacia(pila)){
        return nullptr;
    }
    else{
        void *dato;
        int *cant=(int *)auxPila[CANT];
        dato=auxNodo[DAT];
        auxPila[CIMA]=auxNodo[SIG];
        (*cant)--;
        delete auxNodo;
        return dato;
    }
}

void imprimepila(void *pilafin,void (*imp)(void *,ofstream &),const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR CON EL REPORTE"<<endl;
        exit(1);
    }
    void **auxPila=(void **)pilafin,**aux;
    int *cant=(int *)auxPila[CANT];
    archRep<<"REPORTE DE DATOS"<<endl<<endl;
    aux=(void **)auxPila[CIMA];
    while(aux){
        imp(aux[DAT],archRep);
        aux=(void **)aux[SIG];
    }
}