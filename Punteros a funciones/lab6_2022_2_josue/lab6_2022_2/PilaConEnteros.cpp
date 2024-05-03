/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "PilaConEnteros.h"



void *leenumero (ifstream &arch){
    int *numero=new int;
    arch>>*numero;
    if(arch.eof())return nullptr;
    return numero;
}


int cmpnumero (const void *a,const void *b){
    void **ai=(void **)a,**bi=(void **)b;
    void **regA=(void **)(*ai),**regB=(void **)(*bi);
    int *pesoA=(int *)regA,*pesoB=(int *)regB;
    return *pesoB-*pesoA;
}

void imprimenumero(void *dato, ofstream &arch){

    int *dat=(int*)dato;
    arch<<*dat<<endl;

}