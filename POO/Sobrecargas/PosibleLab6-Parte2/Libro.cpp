/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: julia
 * 
 * Created on 23 de mayo de 2024, 11:52
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    autor=nullptr;
    titulo=nullptr;
    codigo=nullptr;
}

Libro::~Libro() {
    if(autor!=nullptr) delete autor;
    if(titulo!=nullptr) delete titulo;
    if(codigo!=nullptr) delete codigo;
}

void Libro::SetPrecio(double precio) {
    this->precio = precio;
}

double Libro::GetPrecio() const {
    return precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(const char* aut) {
    if(autor!=nullptr) delete autor;
    autor=new char[strlen(aut)+1];
    strcpy(autor,aut);
}

void Libro::GetAutor(char *aut) const {
    if(autor==nullptr) aut[0]=0;
    else strcpy(aut,autor);
}

void Libro::SetTitulo(const char* tit) {
    if(titulo!=nullptr) delete autor;
    titulo=new char[strlen(tit)+1];
    strcpy(titulo,tit);
}

void Libro::GetTitulo(char *tit) const {
    if(titulo==nullptr) tit[0]=0;
    else strcpy(tit,titulo);
}

void Libro::SetCodigo(const char* cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

bool operator >>(ifstream &arch,Libro &libro){
    char codigo[8],titulo[80],autor[80];
    int stock;
    double precio;
    arch.getline(codigo,8,',');
    if(arch.eof()){
        libro.SetCodigo("FIN");
        return false;
    }
    arch.getline(titulo,80,',');
    arch.getline(autor,80,',');
    arch>>stock;
    arch.get(); //lee la coma
    arch>>precio;
    arch.get(); //lee el salto de linea
    libro.SetCodigo(codigo);
    libro.SetTitulo(titulo);
    libro.SetAutor(autor);
    libro.SetStock(stock);
    libro.SetPrecio(precio);
    return true;
}

int buscarLibro(char *codigoDelLibro,Libro *libros){
    int i=0;
    char codigo[8];
    while(true){
        libros[i].GetCodigo(codigo);
        if(strcmp(codigo,"FIN")==0) return -1;
        if(strcmp(codigo,codigoDelLibro)==0) return i;
        i++;
    }
}

void operator <<(ofstream &arch,Libro &libro){
    char codigo[8],titulo[60],autor[60];
    double precio=libro.GetPrecio();
    int stock=libro.GetStock();
    libro.GetCodigo(codigo);
    libro.GetAutor(autor);
    libro.GetTitulo(titulo);
    arch<<left<<setw(10)<<codigo<<setw(60)<<titulo<<setw(60)<<autor;
    arch<<right<<setw(5)<<stock<<setw(10)<<precio<<endl;
}