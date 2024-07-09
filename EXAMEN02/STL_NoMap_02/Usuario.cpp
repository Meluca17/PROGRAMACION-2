
/* 
 * File:   Usuario.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 5:06 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Usuario.h"

Usuario::Usuario() {
    nombre = nullptr;
}

Usuario::Usuario(const Usuario& orig) {
    nombre = nullptr;
    *this = orig;
}
void Usuario::operator = (const class Usuario &usu){
    char buff[100];
    usu.GetNombre(buff);
    SetNombre(usu.nombre);
     
    carne = usu.carne;
    tipo = usu.tipo;
}
bool Usuario::operator < (const class Usuario &usu){
    return carne<usu.carne;
}

//Usuario::~Usuario() {
//}

void Usuario::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
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

//

bool Usuario::leeUsuario(ifstream &arch){
    char c, buff[100];
    arch>>carne;
    //cout<<carne<<endl;
    if(arch.eof()) return false;
    tipo = arch.get();
    arch>>c;
    //cout<<tipo<<endl;
    arch.getline(buff,100,'\n');
    
    SetNombre(buff);
    return true;
}

 void  Usuario::imprimeUsuario(ofstream &arch)const {
     char buff[100];
     GetNombre(buff);
     arch<<left<<setw(7)<<tipo<<setw(15)<<carne<<setw(50)<<buff
            <<setw(20)<<" "<<"-"<<endl;
     
 }