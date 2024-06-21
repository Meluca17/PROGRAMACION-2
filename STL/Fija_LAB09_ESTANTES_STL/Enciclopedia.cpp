
/* 
 * File:   Enciclopedia.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 21:51
 */
#include "Utils.h"
#include "Enciclopedia.h"
using namespace std;

Enciclopedia::Enciclopedia() {
    
    vigencia = 1;
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
    //*this = orig;
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream &arch){
    char c;
    Libro::lee(arch);
    arch>>sku>>c>>anho;
}

void Enciclopedia::imprime(ofstream &arch){
    Libro::imprime(arch);
    
    arch<<setw(10)<<" "<<left<<setw(10)<<"SKUU: "<<sku;
    arch<<setw(5)<<" "<<left<<setw(10)<<"Anho: "<<anho;
    arch<<setw(5)<<" "<<left<<setw(10)<<"Vigencia: "<<vigencia<<endl<<endl;
}

void Enciclopedia::actualiza(int anhoMax){
    if(anho<=anhoMax) vigencia=0;
}

void Enciclopedia::eliminar(){
    Libro::eliminar();
}