
/* 
 * File:   Pedido.cpp
 * Author: mell1
 * 
 * Created on 22 de mayo de 2024, 18:12
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    //CONSTRUCTOR POR DEFECTO
    codigo = nullptr;
    dni_cliente=0;
    precio_producto=0.0;
}

Pedido::Pedido(const Pedido& orig) {
    //esta es la copia
}

Pedido::~Pedido() {
    if(codigo) delete codigo;
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* c){
    //verificamos si existe un codigo antes
    if(this->codigo) delete this->codigo;
    //asignamos el nuevo
    this->codigo = new char [strlen(c)+1];
    strcpy(this->codigo,c);
}

void Pedido::GetCodigo(char *c) const{
    //si la cadena q tenemos es vacia
    if(this->codigo==nullptr) c[0] = 0;
    else strcpy(c,this->codigo);
}
    
////////////////////// SOBRECARGA ////////////////////////////////////
//Lectura de un pedido
bool operator>>(ifstream &arch,class Pedido &p){
    char codP[10],c;
    int dniC;
    
    arch.getline(codP,10,',');
    if(arch.eof()) return false;
    arch>>dniC;
    
    p.SetCodigo(codP);
    p.SetDni_cliente(dniC);
    return true;
}

//PEDIDOS
//  codProdPedido  dni 
