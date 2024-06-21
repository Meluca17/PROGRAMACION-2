
/* 
 * File:   Furgon.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:42
 */
#include "Utils.h"
#include "Furgon.h"
#include "Vehiculo.h"
using namespace std;

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::lee(ifstream &arch){
    Vehiculo::lee(arch);
    char c;
    arch>>filas>>c>>puertas;
    arch.get();
}

void Furgon::insertaPed(class NPedido &ped){
    mdeposito.push_back(ped);
}

void Furgon::imprime(ofstream &arch){
    char cod[50];
    Vehiculo::imprime(arch);
    arch<<"Pedidos furgon"<<endl;
//    int cant = mdeposito.size();
//    cout <<cant<<endl;
    //if(mdeposito.empty()) arch<< "No hay pedidos"<<endl;
    if(mdeposito.size()==0) arch<< "No hay pedidos"<<endl;
    else{
        for(int i=0; i<mdeposito.size();i++){
            arch<<mdeposito[i].GetPeso()<<endl;
            //arch<<"Ola"<<endl;
        }
    }
    arch<<"---------------------------"<<endl;
}