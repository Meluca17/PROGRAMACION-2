/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   LibroSolicitado.cpp
 * Author: julia
 * 
 * Created on 23 de mayo de 2024, 11:42
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Libro.h"
#include "LibroSolicitado.h"

LibroSolicitado::LibroSolicitado() {
    codigoDelLibro=nullptr;
}

LibroSolicitado::LibroSolicitado(int numPed,const char *codigo,double precio,bool atendido){
    numeroDelPedido=numPed;
    SetCodigoDelLibro(codigo);
    SetPrecio(precio);
    SetAtendido(atendido);
}

LibroSolicitado::~LibroSolicitado() {
    if(codigoDelLibro!=nullptr) delete codigoDelLibro;
}

void LibroSolicitado::SetAtendido(bool atendido) {
    this->atendido = atendido;
}

bool LibroSolicitado::IsAtendido() const {
    return atendido;
}

void LibroSolicitado::SetPrecio(double precio) {
    this->precio = precio;
}

double LibroSolicitado::GetPrecio() const {
    return precio;
}

void LibroSolicitado::SetCodigoDelLibro(const char *cod) {
    if(codigoDelLibro!=nullptr) delete codigoDelLibro;
    codigoDelLibro=new char[strlen(cod)+1];
    strcpy(codigoDelLibro,cod);
}

void LibroSolicitado::GetCodigoDelLibro(char *cod) const {
    if(codigoDelLibro==nullptr) cod[0]=0;
    else strcpy(cod,codigoDelLibro);
}

void LibroSolicitado::SetNumeroDelPedido(int numeroDelPedido) {
    this->numeroDelPedido = numeroDelPedido;
}

int LibroSolicitado::GetNumeroDelPedido() const {
    return numeroDelPedido;
}

void LibroSolicitado::operator =(const LibroSolicitado &libro){
    char codigo[8];
    libro.GetCodigoDelLibro(codigo);
    SetCodigoDelLibro(codigo);
    SetNumeroDelPedido(libro.GetNumeroDelPedido());
    SetPrecio(libro.GetPrecio());
    SetAtendido(libro.IsAtendido());
}

bool LibroSolicitado::operator >>(Libro *libros){
    int pos=buscarLibro(codigoDelLibro,libros);
    int stock;
    if(pos!=-1){
        stock=libros[pos].GetStock();
        if(stock>0){
            SetPrecio(libros[pos].GetPrecio());
            SetAtendido(true);
            stock--;
            libros[pos].SetStock(stock);
            return true;
        }else{
            SetAtendido(false);
            return false;
        }
    }
}