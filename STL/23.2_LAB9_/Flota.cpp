
/* 
 * File:   Flota.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:46
 */
#include "Utils.h"
#include "Flota.h"
#include "NPedido.h"
#include <algorithm>
using namespace std;

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv",ios::in);
    if(!arch.is_open()){
        cout<<"pipipp "<<endl;
        exit(1);
    }
    
    char tipo;
    class NVehiculo dato;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        dato.asignamemoria(tipo);
        dato.leeDatos(arch);
        vflota.push_back(dato);
    }
    
    sort(vflota.begin(),vflota.end());
    
}
 
void Flota::muestracarga(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch.is_open()){
        cout<<"pipipp "<<endl;
        exit(1);
    }
    arch<<setw(50)<<"REPORTE"<<endl;
//    for(NVehiculo vehiculo: vflota){ //aca no puedo acceder a los campos de vflota
//        
//    }
    
    for(int i=0; i<vflota.size();i++){
        vflota[i].imprimeDatos(arch);
    }
}

void Flota::cargapedidos(){
    ifstream arch("Pedidos3.csv",ios::in);
    if(!arch.is_open()){
        cout<<"pipipp "<<endl;
        exit(1);
    }
    int cliente, pos;
    class NPedido ped;
    while(true){
        arch>>cliente;
        if(arch.eof()) break;
        arch.get();
        ped.leePed(arch);
        //busco el codigo del cliente en el vector de vehiculo
        pos = buscarCliente(cliente);
        if(pos!=-1){
            vflota[pos].insertaPedidoVector(ped);
        }
    }
    
    
}

int Flota::buscarCliente(int cliente){
    for(int i=0; i<vflota.size();i++){
        if(vflota[i].GetCliente()==cliente) return i;
    }
    return -1;
}