
/* 
 * File:   Vehiculo.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:31
 */
#include "Utils.h"
#include "Vehiculo.h"
using namespace std;

Vehiculo::Vehiculo() {
    placa = nullptr;
    actcarga = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    
}

Vehiculo::~Vehiculo() {
    //if(placa) delete placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* placa) {
    if(this->placa!=nullptr) delete this->placa;
    this->placa = new char [strlen(placa)+1];
    strcpy(this->placa,placa);
}
void Vehiculo::GetPlaca(char*c) const {
    if(placa==nullptr) c[0] = 0;
    else strcpy(c,placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void  Vehiculo::lee(ifstream &arch){
    char c, buff[50];
    
    arch>>cliente>>c;
    arch.getline(buff,50,',');
    arch>>maxcarga>>c;
    SetPlaca(buff);
    
    //cout <<cliente<<endl;
}

void Vehiculo::imprime(ofstream &arch){
    char buff[50];
    GetPlaca(buff);
    
    arch<<setw(10)<<cliente<<endl;
    arch<<setw(10)<<maxcarga<<endl;
    //arch<<setw(10)<<buff<<endl;
}