
/* 
 * File:   LVehiculos.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:20
 */
#include "Utils.h"
#include "LVehiculos.h"
#include "Furgon.h"
#include "Camion.h"
#include "Vehiculo.h"
using namespace std;

LVehiculos::LVehiculos() {
    lfin = nullptr;
    lini = nullptr;
}

LVehiculos::~LVehiculos() {
    // llama a un metodo que elimina a una lista 
}

void LVehiculos::leeDatos(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout << "No se abrio "<<filename;
        exit(1);
    }
    
    class Vehiculo *vehiculo;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        asignaMemoria(vehiculo,tipo);
        vehiculo->lee(arch);
        insertarFinal(vehiculo);
    }
}

void LVehiculos::asignaMemoria(class Vehiculo *&vel, char tipo){
    if(tipo=='F'){
        vel = new class Furgon;
    }
    else if(tipo=='C'){
        vel = new class Camion;
    }
}

void LVehiculos::insertarOrden(class Vehiculo *&vehiculo){
    class NodoLista *ant=nullptr, *rec = lini, *nuevo;
    nuevo = new class NodoLista;
    nuevo->unidad = vehiculo;
    
    while(rec){
        //condicion de insertado
        if(*rec->unidad > *vehiculo) break; //sobrecarga :) 
        ant = rec;
        rec = rec->sig;
    }
    //insertamos nodo
    nuevo->sig = rec;
    if(rec==nullptr) lfin = nuevo;
    if(ant!=nullptr){
        ant->sig = nuevo;
    }else{ 
        lini = nuevo;
    }
}

// E N C O L A R 
void LVehiculos::insertarFinal(class Vehiculo *&vehiculo){
    class NodoLista *nuevo;
    nuevo = new class NodoLista;
    nuevo->unidad = vehiculo;
    
    if(lini==nullptr){
        lini = nuevo;
        lfin = nuevo;
    }
    else{
        lfin->sig = nuevo;
        lfin = nuevo;
    }
}

void LVehiculos::mostrarDatos(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout << "No se abrio "<<filename;
        exit(1);
    }
    arch<<setw(50)<<"REPORTE DE FLOTA"<<endl;
    for(int i=0;i<50;i++)  arch<<'=';
    arch<<endl;
    
    class NodoLista *rec=lini;
    while(rec){
        rec->unidad->imprime(arch);
        rec = rec->sig;
    }
}
// VEHICULO -> lista (pila) de pedidos
//aca ya existe la lista de pedidos 
void LVehiculos::leePedidos(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout << "No se abrio "<<filename;
        exit(1);
    }
    
    class NPedido *ped; // es el nodo 
    int dni;
    
    while(true){
        arch>>dni;
        if(arch.eof()) break;
        arch.get();
        
        ped = new class NPedido; //similar a la parte de asignar memoria
        ped->lee(arch);
        asignaPedidoVariante(dni,ped);
    }
}

void LVehiculos::asignaPedido(int dni,class NPedido *ped){
    class NodoLista *rec = lini, *ant = nullptr;
    
    while(rec){
        cout<<ped->GetPeso()<<endl;
        if(rec->unidad->GetCliente() == dni and 
                rec->unidad->pesoSobrante()>=ped->GetPeso()){
            rec->unidad->push(ped);
            break;
        }
        ant = rec;
        rec = rec->sig;
    }
}

void LVehiculos::asignaPedidoVariante(int dni,class NPedido *ped){
    class NodoLista *rec = lini, *ant = nullptr;
    
    while(rec){
        if(rec->unidad->pesoSobrante()>=ped->GetPeso()){
            rec->unidad->push(ped);
            break;
        }
        else{
        ant = rec;
        rec = rec->sig;
        }
    }
}