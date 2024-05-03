/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PilaConRegistro.h"
enum reg{COD,NOM,PES};
void *leeregistro (ifstream &arch){
    void **datos=new void*[3];
    int *cod=new int;
    double *peso=new double;
    char nombre[60],*nuevonomb;
    arch>>*cod;
    if(arch.eof())return nullptr;
    arch.get();
    arch.getline(nombre,60,',');
    nuevonomb=new char[strlen(nombre)+1];
    strcpy(nuevonomb,nombre);
    arch>>*peso;
    datos[COD]=cod;
    datos[NOM]=nuevonomb;
    datos[PES]=peso;
    return datos;
}

int cmpregistro (const void *a,const void *b){
    void **ai=(void **)a,**bi=(void **)b;
    void **regA=(void **)(*ai),**regB=(void **)(*bi);
    double *pesoA=(double *)regA[PES],*pesoB=(double *)regB[PES];
    return *pesoB-*pesoA;
}

void imprimeregistro(void *dato,ofstream &arch){
    void **dat=(void**)dato;
    int *cod=(int*)dat[COD];
    char *cadena=(char*)dat[NOM];
    double*peso=(double*)dat[PES];
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(10)<<*cod<<setw(60)<<cadena<<right<<setw(5)<<*peso<<endl;
}