
/* 
 * File:   Docente.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:23 p. m.
 */

#include "Docente.h"

Docente::Docente() {
}

//Docente::Docente(const Docente& orig) {
//}
//
//Docente::~Docente() {
//}

void Docente::SetAnexo(int anexo) {
    this->anexo = anexo;
}

int Docente::GetAnexo() const {
    return anexo;
}

void Docente::leer(ifstream &arch){
    
    Usuario::leer(arch);
    arch>>anexo;
}

void Docente::getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel){
    tipo = 'D';
    GetNombre(buffNombre);
    //propio
    anex = anexo;
}

void Docente::imprimir(ofstream &arch){
    Usuario::imprimir(arch);
    arch<<setw(15)<<"Anexo: "<<anexo<<endl;
}