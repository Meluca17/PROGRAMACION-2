
/* 
 * File:   ProductoEntregado.cpp
 * Author: mell1
 * 
 * Created on 22 de mayo de 2024, 18:07
 */

#include <cstring>
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    //CONSTRUCTOR POR DEFECTO 
    codigo = nullptr; 
    precio = 0.0; 
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
}

ProductoEntregado::~ProductoEntregado() {
    //ESTOY EN EL DESTRUCTOR 
    if(codigo) delete codigo; 
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* codigo) {
    //si ya existe un cod antes 
    if(this->codigo!=nullptr) delete this->codigo; 
    //creamos el nuevo codigo
    this->codigo = new char[strlen(codigo)+1]; 
    strcpy(this->codigo,codigo);
}

void ProductoEntregado::GetCodigo(char *c) const {
    if(this->codigo==nullptr) c[0] = 0; //cadena vacia 
    else strcpy(c,this->codigo);  
}

