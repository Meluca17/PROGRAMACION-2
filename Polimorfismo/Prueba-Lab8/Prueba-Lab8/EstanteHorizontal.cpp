/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteHorizontal.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 02:00 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() {
    idioma=nullptr;
}

EstanteHorizontal::~EstanteHorizontal() {
    if(idioma!=nullptr)delete idioma;
}

void EstanteHorizontal::SetIdioma(const char *cad) {
    if(idioma!=nullptr)delete idioma;
    idioma=new char[strlen(cad)+1];
    strcpy(idioma,cad);
}

void EstanteHorizontal::GetIdioma(char *cad) const {
    if(idioma==nullptr)cad[0]=0;
    else strcpy(cad,idioma);
}

void EstanteHorizontal::lee(ifstream &arch){
    Estante::lee(arch);
    char idi[20];
    arch.getline(idi,20,'\n');
    SetIdioma(idi);
}

void EstanteHorizontal::imprime(ofstream& arch) {
    Estante::imprime(arch);
    arch<<left<<"   Tipo: Horizontal"<<endl;
    arch<<left<<"Idioma: "<<idioma<<endl;
    imprimeLib(arch);
    arch<<endl;
}
