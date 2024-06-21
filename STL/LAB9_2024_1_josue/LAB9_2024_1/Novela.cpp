/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Josue
 * 
 * Created on 20 de junio de 2024, 11:57 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Novela.h"

Novela::Novela() {
    autor=nullptr;
}

Novela::~Novela() {
    if(autor!=nullptr)delete autor;
}

void Novela::SetAutor(const char *cad) {
    if(autor!=nullptr)delete autor;
    autor=new char[strlen(cad)+1];
    strcpy(autor,cad);
}

void Novela::GetAutor(char *cad) const {
    if(autor==nullptr)cad[0]=0;
    else strcpy(cad,autor);
}

void Novela::lee(ifstream &arch){
    Libro::lee(arch);
    char cad[60];
    arch.getline(cad,60,'\n');
    SetAutor(cad);
}


void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;

}

void Novela::actualiza(){
    
}