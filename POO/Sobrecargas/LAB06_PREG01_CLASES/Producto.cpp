
/* 
 * File:   Producto.cpp
 * Author: mell1
 * 
 * Created on 22 de mayo de 2024, 18:10
 */

#define COD_LEN 10
#define DESC_LEN 500
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Producto.h"
#include "Pedido.h"

Producto::Producto() {
    // CONSTRUCTOR POR DEFECTO 
    codigo = nullptr;
    descripcion=nullptr;
    precio=0.0;
    stock=0;
    cantidad_clientes_servidos=0;
    cantidad_clientes_no_servidos=0;
}

Producto::Producto(const Producto& orig) {
    
}

Producto::~Producto() {
    if(codigo) delete codigo;
    if(descripcion) delete descripcion;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

//void Producto::SetClientes_no_servidos(int[] clientes_no_servidos) {
//    this->clientes_no_servidos = clientes_no_servidos;
//}
//
//int[] Producto::GetClientes_no_servidos() const {
//    return clientes_no_servidos;
//}
//
//void Producto::SetClientes_servidos(int[] clientes_servidos) {
//    this->clientes_servidos = clientes_servidos;
//}
//
//int[] Producto::GetClientes_servidos() const {
//    return clientes_servidos;
//}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

////////////////// CADENAS 
void Producto::SetDescripcion(const char* d) {
    if(this->descripcion) delete this->descripcion;
    //asigna nuevo nombre 
    this->descripcion = new char[strlen(d)+1];
    strcpy(this->descripcion,d);
}

void Producto::GetDescripcion(char *c) const {
    if(this->descripcion==nullptr) c[0]=0; //devuelve cad vacia
    else strcpy(c,this->descripcion);
}

void Producto::SetCodigo(const char* c) {
    if(this->codigo) delete this->codigo;
    //asigna nuevo nombre 
    this->codigo = new char[strlen(c)+1];
    strcpy(this->codigo,c);
}

void Producto::GetCodigo(char *c) const {
    //si no hay codigo
    if(this->codigo==0) c[0] = 0; //cad vacia
    else strcpy(c,this->codigo);
}

//////////// SOBRECARGA //////////
//dentro de esto tengo la informacion de producto
//  char *codigo;
//    char *descripcion;
//    double precio;
//    int stock;
//    int clientes_servidos[500];
//    int clientes_no_servidos[500];
//    int cantidad_clientes_servidos;
//    int cantidad_clientes_no_servidos;

void Producto::imprimeAtendidos(ofstream &arch) const{
    arch<<"Clientes atendidos: "<<endl; 
    for(int i=0; i<cantidad_clientes_servidos; i++){
        //como es un arreglo de ints y no de una clase
        arch<<left<< setw(12)<<clientes_servidos[i];
    }
    arch<<endl; 
}

void Producto::imprimeNoAtendidos(ofstream &arch) const{
    if(cantidad_clientes_no_servidos ==0){
        arch<<" NO HAY CLIENTES SIN ATENDER "<<endl; 
        return; 
    }
    
    arch<<"Clientes no atendidos: "<<endl; 
    for(int i=0; i<cantidad_clientes_no_servidos; i++){
        //como es un arreglo de ints y no de una clase
        arch<<left<< setw(12)<<clientes_no_servidos[i];
    }
    arch<<endl; 
}

bool Producto::operator+=(class Pedido &p){
    p.SetPrecio_producto(precio); 
    int dniC = p.GetDni_cliente();
    if(stock>0){
        clientes_servidos[cantidad_clientes_servidos] = dniC; 
        cantidad_clientes_servidos++;
        stock--; 
        return true;
    }
    else{
        clientes_no_servidos[cantidad_clientes_no_servidos] = dniC; 
        cantidad_clientes_no_servidos++; 
        return false; 
    }
}

//Lectura de un producto
bool operator>>(ifstream &arch,class Producto &p){
    char cod[COD_LEN],desc[DESC_LEN],c;
    int stockF;
    double prec;
    
    arch.getline(cod,COD_LEN,',');
    if(arch.eof()) return false;
    arch.getline(desc,DESC_LEN,',');
    arch>>prec>>c>>stockF;
    
    //asignacion
    p.SetCodigo(cod);
    p.SetDescripcion(desc);
    p.SetPrecio(prec);
    p.SetStock(stockF);
    
    return true;
}

ofstream & operator<<(ofstream &arch, const class Producto &p ){
    char buffCod[500], buffDesc[500];
    
    //impresion de UN producto
    arch.precision(2);
    arch<<fixed;
    
    p.GetCodigo(buffCod);
    p.GetDescripcion(buffDesc);
    arch<<left<<setw(15)<<buffCod<<setw(50)<<buffDesc<<right<<setw(15)<<
            p.GetPrecio()<<setw(15)<<p.GetStock()<<endl;
    if(p.GetCantidad_clientes_servidos()==0){
        arch << left<<setw(50)<< "NO SE ATENDIERON PEDIDOS" << endl;
    }
    else{ 
        //impresion de clientes atendidos y no atendidos
        p.imprimeAtendidos(arch); 
        p.imprimeNoAtendidos(arch); 
    }
}