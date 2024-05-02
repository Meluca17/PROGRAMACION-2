
#include "Utils.h"
#include "ListaConEnteros.h"
using namespace std;
//enum Lista{CABEZA, PESOTOTAL}; //LISTA DE CAMIONES
//enum Nodo{DATO, SIG}; //DATO = CAMION

//enum Pila{CIM, PES};
//enum Nodo{SIG,DAT};


void* leenumero(ifstream &arch){
    double num, *reg;
    
    arch>>num;
    if(arch.eof()) return nullptr;
    
    reg = new double;
    *reg = num;
    return reg; //lo castea automaticamente -> (void *)reg
}

 double calculanumero(void*dato){
     //casteamos
     double *peso = (double *)dato;
     return *peso;
 } 
 
 int cmpnumero(const void*a,const void*b){
     void **ai = (void **)a, **bi=(void **)b;
     //accedemos a los campos
     void **regA = (void **)(ai[0]), **regB=(void **)(*bi);
     
     int *pesoA = (int *)regA[PES], *pesoB = (int *)regB[PES];
     
     return *pesoB - *pesoA;
 }

 void imprimenumero(void *dato, ofstream &arch){
     double *peso = (double *)dato;
     
     arch<< *peso<<endl;
 }