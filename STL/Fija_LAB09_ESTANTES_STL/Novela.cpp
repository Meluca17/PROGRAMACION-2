
/* 
 * File:   Novela.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 21:53
 */
#include "Utils.h"
#include "Novela.h"
using namespace std;

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const Novela& orig) {
//    autor = nullptr;
//    *this = orig;
}

Novela::~Novela() {
}

void Novela::SetAutor(const char* autor) {
    if(this->autor!=nullptr) delete this->autor;
    this->autor = new char [strlen(autor)+1];
    strcpy(this->autor,autor);
}

void Novela::GetAutor(char *c) const {
    if(autor==nullptr) c[0]=0;
    strcpy(c,autor);
}

void Novela::lee(ifstream &arch){
    char c,buffAut[100];
    Libro::lee(arch);
    arch.getline(buffAut,100);
    SetAutor(buffAut);
}

void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    char buff[100];
    GetAutor(buff);
    arch<<setw(10)<<" "<<left<<setw(10)<<"Autor: "<<buff<<endl<<endl;
}

void Novela::eliminar(){
    Libro::eliminar();
    if(autor!=nullptr) delete autor;
}