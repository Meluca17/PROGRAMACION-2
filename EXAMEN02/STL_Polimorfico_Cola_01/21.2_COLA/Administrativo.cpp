
/* 
 * File:   Administrativo.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:19 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Administrativo.h"

Administrativo::Administrativo() {
    area = nullptr;
}
//
//Administrativo::Administrativo(const Administrativo& orig) {
//}
//
//Administrativo::~Administrativo() {
//}

void Administrativo::SetArea(const char* area) {
    if(this->area!=nullptr) delete this->area;
    //espacio de mem y copiar 
    this->area = new char [strlen(area)+1];
    strcpy(this->area,area);
}

void Administrativo::GetArea(char*c) const {
    if(this->area==nullptr) c[0] = 0;
    else strcpy(c,this->area);
}

void Administrativo::leer(ifstream &arch){
    char buff[100];
    
    Usuario::leer(arch);
    arch.getline(buff,100);
    SetArea(buff);
}

void Administrativo::getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel){
    tipo = 'A';
    GetNombre(buffNombre);
    //cout<<buffNombre<<endl;
    //propio
    GetArea(buffarea);
}
    
void Administrativo::imprimir(ofstream &arch){
    Usuario::imprimir(arch);
    char buff[100];
    GetArea(buff);
    arch<<setw(15)<<"Area: "<<buff<<endl;
}