/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaConEnteros.h"
#include "ColaGenerica.h"
void cargaEnteros(void *&cola,void *(*leenum)(ifstream &),const char *nombArch){
    ifstream archNum(nombArch,ios::in);
    if(not archNum.is_open()){
        cout<<"ERROR CON EL ARCHIVO DE NUMEROS"<<endl;
        exit(1);
    }
    void *dato;
    generacola(cola);
    int *val;
    while(true){
        dato=leenum(archNum);
        if(archNum.eof())break;
        val=(int *)dato;
 
        encola(cola,dato);
    }   
        
}

void *leenumero(ifstream &arch){
    int *dato=new int;
    arch>>*dato;
    if(arch.eof())return nullptr;
    return dato;
}

void mostrarEnteros(void *&cola,void (*imprimenum)(ofstream &,void *),const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    void **aux=(void **)cola;
   
    while(!colavacia(cola)){
        dato=desencola(cola);
        imprimenum(archRep,dato);
    }
}

void imprimenumero(ofstream &archRep,void *dato){
    int *numero=(int *)dato;
    archRep<<"Numero: "<<*numero<<endl;
}