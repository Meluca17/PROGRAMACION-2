
/* 
 * File:   NPedido.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:13
 */
#include "Utils.h"
#include "NPedido.h"
using namespace std;

NPedido::NPedido() {
    codigo = nullptr;
    sig=nullptr;
}
//NPedido::~NPedido() {
//    if(codigo) delete codigo;
//}


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

void NPedido::GetCodigo(char*c) const {
    if(this->codigo==nullptr) c[0]= 0;
    else strcpy(c,this->codigo);
}

void NPedido::lee(ifstream &arch){
    char buff[50],c;
    
    arch.getline(buff,50,',');
    arch>>cantidad>>c>>peso;
    arch.get();
    
    SetCodigo(buff);
}

void NPedido::imprimePedido(ofstream &arch){
    char buff[50];
    GetCodigo(buff);
    arch.precision(2);
    arch<<fixed;
    
    arch<<setw(15)<<" "<<left<<setw(10)<<buff<<right<<setw(10)<<cantidad
            <<setw(10)<<peso<<endl;
}