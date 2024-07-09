
/* 
 * File:   Usuario.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:16 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Usuario.h"

Usuario::Usuario() {
    nombre = nullptr;
}
//
//Usuario::Usuario(const Usuario& orig) {
//}
//
//Usuario::~Usuario() {
//}

void Usuario::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    //espacio de mem y copiar 
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Usuario::GetNombre(char*c) const {
     if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

void Usuario::SetTipo(char tipo) {
    this->tipo = tipo;
}

char Usuario::GetTipo() const {
    return tipo;
}

void Usuario::SetCarne(int carne) {
    this->carne = carne;
}

int Usuario::GetCarne() const {
    return carne;
}

void Usuario::leer(ifstream &arch){
    char buff[100];
    
    arch.getline(buff,100,',');
    SetNombre(buff);
}

void Usuario::imprimir(ofstream &arch){
    char buff[100];
    GetNombre(buff);
    arch<<setw(15)<<"Nombre: "<<buff<<endl;
}

    