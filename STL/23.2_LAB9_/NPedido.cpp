
/* 
 * File:   NPedido.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:14
 */
#include "Utils.h"
#include "NPedido.h"
using namespace std;

NPedido::NPedido() {
    codigo = nullptr;
    cantidad = 0;
    peso = 0;
}

// DEFINIR SOBRECARGA DEL = 
NPedido::NPedido(const NPedido& orig) {
    codigo = nullptr;
    *this = orig;
}

NPedido::~NPedido() {
    //if(codigo!=nullptr) delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo = new char [strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void NPedido::GetCodigo(char *c) const {
    if(codigo==nullptr) c[0] = 0;
    else strcpy(c,codigo);
}

void NPedido::operator =(const class NPedido &ped){
    char cod[50];
    
    peso = ped.peso;
    cantidad = ped.cantidad;
    
    ped.GetCodigo(cod);
    SetCodigo(cod);
}

void NPedido::leePed(ifstream &arch){
    char buff[50],c;
    
    arch.getline(buff,50,',');
    arch>>cantidad>>c>>peso;
}