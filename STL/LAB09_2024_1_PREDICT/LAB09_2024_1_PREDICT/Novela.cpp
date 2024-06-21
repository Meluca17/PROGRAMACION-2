/* 
 * File:   Novela.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:15 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Novela.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetAutor(char *cad){
    if(autor) delete autor;
    autor = new char[strlen(cad)+1];
    strcpy(autor,cad);
}
    
void Novela::GetAutor(char *cad) const{
    if(autor) strcpy(cad,autor);
    else cad[0] = '\0';
}
//Diamantes y pedernales,120,0.4,Jose Maria Arguedas
void Novela::lee(ifstream &archLib){
    char aut[40];
    
    Libro::lee(archLib);    //Diamantes y pedernales,120,0.4,
    archLib.getline(aut,40);
    SetAutor(aut);
}

void Novela::imprime(ofstream &archRep){
    Libro::imprime(archRep);
    archRep<<"Autor:"<<autor<<endl;
}