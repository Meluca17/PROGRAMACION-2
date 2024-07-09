
/* 
 * File:   RegistroPrestamo.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 5:09 p. m.
 */
#include "Utils.h"
using namespace std;
#include "RegistroPrestamo.h"

RegistroPrestamo::RegistroPrestamo() {
    libPrest = nullptr;
    
}

RegistroPrestamo::RegistroPrestamo(const RegistroPrestamo& orig) {
    libPrest = nullptr;
    *this = orig;
}

bool RegistroPrestamo::operator <(const class RegistroPrestamo &reg){
    return cliente< reg.cliente;
}

void RegistroPrestamo::operator = (const class RegistroPrestamo &reg){
    char buff[100];
    reg.GetLibPrest(buff);
    SetLibPrest(buff);
    
    cliente = reg.cliente;
    fechaRetiro = reg.fechaRetiro;
    tipo = reg.tipo;
}
    

//RegistroPrestamo::~RegistroPrestamo() {
//}

void RegistroPrestamo::SetFechaRetiro(int fechaRetiro) {
    this->fechaRetiro = fechaRetiro;
}

int RegistroPrestamo::GetFechaRetiro() const {
    return fechaRetiro;
}

void RegistroPrestamo::SetLibPrest(const char* libPrest) {
    if(this->libPrest!=nullptr) delete this->libPrest;
    this->libPrest = new char [strlen(libPrest)+1];
    strcpy(this->libPrest,libPrest);
}

void RegistroPrestamo::GetLibPrest(char*c) const {
    if(this->libPrest==nullptr) c[0] = 0;
    else strcpy(c,this->libPrest);
}
void RegistroPrestamo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int RegistroPrestamo::GetCliente() const {
    return cliente;
}

void RegistroPrestamo::SetTipo(char tipo) {
    this->tipo = tipo;
}

char RegistroPrestamo::GetTipo() const {
    return tipo;
}

//
void RegistroPrestamo::leePrestamo(ifstream &arch){
    char buff[100],c;
    int dia,mes,anh;
    
    arch>>cliente;
    if(arch.eof()) return;
    arch>>tipo>>c;
    arch.getline(buff,100,',');
    SetLibPrest(buff);
    arch>>dia>>c>>mes>>c>>anh;
    SetFechaRetiro(anh*100000 + mes*100 + dia);
}

 
void RegistroPrestamo::imprimeDatos(ofstream &arch) const {
   arch.precision(2);
    arch<<fixed;
    cout <<cliente<<endl;
    arch<<left<<setw(5)<<" ";
    arch<<left<<setw(6)<<tipo<<setw(15)<<cliente<<setw(15)<<fechaRetiro<<endl;
}