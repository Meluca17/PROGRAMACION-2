
/* 
 * File:   Pedido.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:29
 */

#include "Utils.h"
#include "Pedido.h"
using namespace std;

Pedido::Pedido() {
    nombre = nullptr;
    dni = 0; 
    fecha =  0; 
}


Pedido::~Pedido() {
    if(nombre) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(const char* nombre) {
    
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Pedido::GetNombre(char*c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream &arch){
    int dia,mes,anho; 
    char buffN[50],c; 
    
    arch.getline(buffN,50,','); 
    arch>>cantidad>>c>>total>>c>>dni>>c>>dia>>c>>mes>>c>>anho;
    SetFecha(anho*100000+mes*100+dia); 
    SetNombre(buffN);
    //cout << dni<<endl; 
}

bool Pedido::operator >(const class Pedido &ped){
    if(this->dni !=ped.dni){
        return this->dni > ped.dni; 
    }
    else{ // si los dnis son iguales filtra por fecha
        return this->fecha > ped.fecha; 
    }
}

void Pedido::imprime(ofstream &arch){
    char buff[50]; 
    GetNombre(buff); 
    
    arch.precision(2); 
    arch<<fixed; 
    
    arch<<fecha<<endl; 
    arch<<left<<setw(15)<<codigo<<setw(60)<<buff<<endl;
    arch<<left<<setw(15)<<"DNI:"<<dni<<endl; 
    arch<<left << setw(15)<<"Monto Total: "<<total<<endl; 
    //arch<<left << setw(15)<<"Descuento: "<<des<<endl; 
    
}


    