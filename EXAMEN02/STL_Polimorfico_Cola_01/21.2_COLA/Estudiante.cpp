
/* 
 * File:   Estudiante.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:24 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Estudiante.h"
#include "Administrativo.h"

Estudiante::Estudiante() {
    celular = 0;
}

//Estudiante::Estudiante(const Estudiante& orig) {
//}
//
//Estudiante::~Estudiante() {
//}

void Estudiante::SetCelular(int celular) {
    this->celular = celular;
}

int Estudiante::GetCelular() const {
    return celular;
}

void Estudiante::leer(ifstream &arch){
    Usuario::leer(arch);
    arch>>celular;
    arch.get();
}

void Estudiante::getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel){
    tipo = 'E';
    GetNombre(buffNombre);
    //propio
    cel = celular;
}


void Estudiante::imprimir(ofstream &arch){
    Usuario::imprimir(arch);
    arch<<setw(15)<<"Area: "<<celular<<endl;
}