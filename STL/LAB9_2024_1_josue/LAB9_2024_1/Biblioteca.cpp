/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Josue
 * 
 * Created on 21 de junio de 2024, 12:35 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

void Biblioteca::carga(){
    ifstream arch("Estantes2.csv",ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo Estantes2.csv"<<endl;
        exit(1);
    }
    lestantes.leeEstantes(arch);
}

void Biblioteca::llena(){
    ifstream arch("Libros3.csv",ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo Libros3.csv"<<endl;
        exit(1);
    }
    lestantes.leeLibros(arch);
}

void Biblioteca::muestra(){
    ofstream arch("reporte.txt",ios::out);
    if(!arch){
        cout<<"No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    arch<<"Estantes:"<<endl;
    for(int i=0;i<100;i++)arch.put('=');
    arch<<endl;
    lestantes.imprimeEstantes(arch);
}

void Biblioteca::actualiza(){
    lestantes.actualizaEstante();
}
 

