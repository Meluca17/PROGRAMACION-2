
/* 
 * File:   Camion.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:34
 */
#include "Utils.h"
#include "Camion.h"
#include "Vehiculo.h"
using namespace std;

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::insertaPed(class NPedido &ped){
    mdeposito.push_back(ped);
}

void Camion::imprime(ofstream &arch){
    char cod[50];
    Vehiculo::imprime(arch);
    arch<<"Pedidos camion"<<endl;
//    int cant = mdeposito.size();
//    cout <<cant<<endl;
    if(mdeposito.size()==0) arch<< "No hay pedidos"<<endl;
    else{
        for(int i=0; i<mdeposito.size();i++){
            arch<<mdeposito[i].GetPeso()<<endl;
        }
    }
    arch<<"---------------------------"<<endl;
}