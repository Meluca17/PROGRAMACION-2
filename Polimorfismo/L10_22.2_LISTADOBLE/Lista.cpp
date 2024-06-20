
/* 
 * File:   Lista.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:42
 */
#include "Utils.h"
#include "Lista.h"
using namespace std;
#include "PedidoEspecial.h"
#include "PedidoEventual.h"
#include "PedidoUsual.h"
#include "Pedido.h"
#include "Nodo.h"

Lista::Lista() {
    lfin = nullptr;
    lini = nullptr;
}

Lista::~Lista() {
}

//118050,10,PAPAYA,8,8,79475585,16/12/2019
// COD DESC/FLETE NOMB CANT MONTO DNI EFCHA
void Lista::leeDatos(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    
    class Pedido *ped; 
    int codigo; 
    // LECTURA 
    while(true){
        arch>>codigo; 
        if(arch.eof()) break; 
        arch.get(); 
        
        asignaMemoria(codigo, ped); 
        ped->SetCodigo(codigo); 
        ped->lee(arch);
        
        insertarOrd(ped); 
    }
}

void Lista::asignaMemoria(int cod, class Pedido *&ped){
    if(cod <  400000){
        ped = new class PedidoEspecial;
    }
    else if(cod>=400000 and cod < 600000){
        ped = new class PedidoUsual; 
    }
    else if(cod >= 600000){
        ped = new class PedidoEventual; 
    }
}

void Lista::insertarOrd(class Pedido *&dato){
    class Nodo *rec = lini, *ant = nullptr, *nuevo; 
    //creamos un nuevo nodo
    nuevo = new class Nodo; 
    nuevo->ped = dato; 
    //posicion a insertar
    while(rec){
        if(*nuevo->ped > *dato) break; 
        ant = rec; 
        rec = rec->sig; 
    }
    //ya se puede insertar 
    nuevo->sig = rec; 
    nuevo->ant = ant;
    
    if(rec==nullptr){ //estamos al final de la lista
        lfin = nuevo;
    }else{
        rec->ant = nuevo;
    }
    if(ant!=nullptr)ant->sig = nuevo;
    else lini = nuevo ; 
}

void Lista::imprimeDatos(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    
    arch<<setw(50)<<"REPORTE DE PROMOCIONES"<<endl; 
    for(int i=0; i<100; i++) arch<<'=';
    arch<<endl;
    imprimirIterativo(arch); 
}

void Lista::imprimirIterativo(ofstream &arch){
    class Nodo *rec = lini;
    //arch<<"Datos de la lista: "<<endl;
    while(rec){
        rec->ped->imprime(arch);
        rec = rec->sig;
    }
    arch<<endl;
}


void Lista::imprimeRec(class Nodo *rec,ofstream &arch){
    if(rec==nullptr) return; 
    
    rec->ped->imprime(arch); 
    imprimeRec(rec->sig,arch); 
}

void Lista::actualizaDatos(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio "<<filename;
        exit(1);
    }
    
    int dniLeid,fecha,dia,mes,anho;
    char c;
    
    while(true){
        arch>>dniLeid;
        if(arch.eof()) break;
        arch>>c>>dia>>c>>mes>>c>>anho;
        fecha = anho*100000+mes*100 +dia;
        
        actualizaClientes(dniLeid,fecha);
    }
}

// OBLIGATORIAMENTE USA EL PUNTERO ANT 
void Lista::actualizaClientes(int dni,int fecha){
//    class Nodo *rec = lini, *ant = nullptr; 
//
//    //buscamos al cliente 
//    while(rec){
//        if(rec->ped->GetDni()==dni and 
//                rec->ped->GetFecha()<fecha){
//            rec->ped->actualizaMonto();
//        } 
//        ant = rec; 
//        rec = rec->sig; 
//    }
    
    class Nodo *rec = lfin;
    while(rec){
        if(rec->ped->GetDni()==dni and 
                rec->ped->GetFecha()<fecha){
            rec->ped->actualizaMonto();
        } 
        rec = rec->ant;
    }
    
}