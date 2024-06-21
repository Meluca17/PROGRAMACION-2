
/* 
 * File:   Libro.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 13:46
 */
#include "Utils.h"
#include "Libro.h"
using namespace std; 

Libro::Libro() {
    nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
//    nombre = nullptr;
//    *this = orig;
}

Libro::~Libro() {
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre; 
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre, nombre); 
}

void Libro::GetNombre(char*c) const {
    if(this->nombre==nullptr)c[0] = 0; 
    else strcpy(c,this->nombre); 
}

void Libro::lee(ifstream &arch){
    char buffTit[100],c;
    arch.getline(buffTit,100,',');
    arch>>paginas>>c>>peso>>c;
    SetNombre(buffTit);
}

void Libro::imprime(ofstream &arch){
    char buff[100];
    GetNombre(buff);
    
    arch<<setw(10)<<" "<<left<<setw(15)<<"Titulo: "<<buff<<endl;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Peso: "<<peso<<endl;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Paginas: "<<paginas<<endl;
    
}

void Libro::eliminar(){
    if(nombre!=nullptr) delete nombre;
}