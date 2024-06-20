/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#include "NPedido.h"

NPedido::NPedido() {
    codigo = nullptr;
}

NPedido::NPedido(const NPedido& orig) {
}

NPedido::~NPedido() {
    if (codigo != nullptr) delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char [strlen(cod)+1];
    strcpy(codigo, cod);
}

void NPedido::GetCodigo(char* cod) const {
    if (codigo == nullptr) cod[0]= 0;
    else strcpy(cod, codigo);
}

