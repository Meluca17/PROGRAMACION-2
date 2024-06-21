/* 
 * File:   Biblioteca.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:28 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
#define MAX_LINEA 70
Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga(){
    ifstream archEst("Estantes2.csv",ios::in);
    if(not archEst.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Estantes2.csv"<<endl;
        exit(1);
    }
    LDEstantes.creaLista(archEst);
}

void Biblioteca::llena(){
    ifstream archLib("Libros3.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros3.csv"<<endl;
        exit(1);
    }
    LDEstantes.llenaLibros(archLib);
}

void Biblioteca::baja(){
    LDEstantes.actualizaVigencia();
}

void Biblioteca::muestra(){
    ofstream archRep("Reporte.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archRep<<"Estantes:"<<endl;
    imprimirLinea(archRep,'=');
    archRep<<endl;
    LDEstantes.imprimeEstantes(archRep);
}

void Biblioteca::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}