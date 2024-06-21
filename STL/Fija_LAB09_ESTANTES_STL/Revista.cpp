
/* 
 * File:   Revista.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 21:55
 */
#include "Utils.h"
#include "Revista.h"
using namespace std;

Revista::Revista() {
    vigencia = 1;
}

Revista::Revista(const Revista& orig) {
   // *this = orig;
}

Revista::~Revista() {
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream &arch){
    char c;
    Libro::lee(arch);
    arch>>ISSN>>c>>anho>>c>>numero;
}

void Revista::imprime(ofstream &arch){
    Libro::imprime(arch);
    
    arch<<setw(10)<<" "<<left<<setw(10)<<"SKUU: "<<ISSN;
    arch<<setw(5)<<" "<<left<<setw(10)<<"Anho: "<<anho;
    arch<<setw(5)<<" "<<left<<setw(10)<<"Numero: "<<anho;
    arch<<setw(5)<<" "<<left<<setw(10)<<"Vigencia: "<<vigencia<<endl<<endl;
}

void Revista::actualiza(int anhoMax){
    if(anho<=anhoMax) vigencia=0;
}

void Revista::eliminar(){
    Libro::eliminar();
}