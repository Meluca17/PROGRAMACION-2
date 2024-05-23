
/* 
 * File:   Cliente.cpp
 * Author: mell1
 * 
 * Created on 22 de mayo de 2024, 18:08
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ProductoEntregado.h"
#include "Cliente.h"


Cliente::Cliente() {
    // ESTOY EN EL CONSTRUCTOR POR DEFECTO 
    dni = 0;
    nombre = nullptr;
    telefono=0;
    cantidad_productos_entregados=0;
    monto_total=0.0;
    //class ProductoEntregado productos_entregados[500];
}
//
//Cliente::Cliente(const Cliente& orig) {
//}

Cliente::~Cliente() {
    // ESTOY EN EL DESTRUCTOR 
    if(nombre!=nullptr) delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

//void Cliente::SetProductos_entregados(ProductoEntregado[] productos_entregados) {
//    this->productos_entregados = productos_entregados;
//}

//class ProductoEntregado Cliente::GetProducto_entregado(int i)const{
//     
//    return this->productos_entregados[i];
//}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}


void Cliente::SetNombre(const char* cad){
    if(this->nombre!=nullptr) delete this->nombre; //si ya habia un nombre antes, se deletea 
    
    //asignamos el nuevo nombre
    this->nombre = new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

void  Cliente::GetNombre(char *c) const{
    if(this->nombre==nullptr) c[0]=0; //Si no hay nombre, devolvemos cadena vacia
    else strcpy(c,this->nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

//////////////////////// SOBRECARGAS /////////////////////////////////////
//agrega un pedido a un cliente 
void Cliente::operator+=(class Pedido &p){
    char codP[10];
    double prec; 
    
    p.GetCodigo(codP);
    prec = p.GetPrecio_producto(); 
    
    //Agregamos a cliente 
    // se convierte en un ProductoEntregado
    productos_entregados[cantidad_productos_entregados].SetCodigo(codP); 
    productos_entregados[cantidad_productos_entregados].SetPrecio(prec); 
    cantidad_productos_entregados++; 
    monto_total+= prec;
}

bool operator>>(ifstream &arch, class Cliente &cli){
    int dni, telef;
    char nomb[500],c;
    
    //lectura de UN cliente 
    arch>>dni;
    if(arch.eof()) return false;
    arch.get(); //lee coma
    arch.getline(nomb,500,',');
    arch>>telef;
    
    // seteamos la clase cliente
    cli.SetDni(dni);
    cli.SetTelefono(telef);
    cli.SetNombre(nomb);
    
    return true;
}

ofstream & operator<<(ofstream &arch, const class Cliente &c ){
    char buffNomb[500];
    
    //impresion de UN cliente
    arch.precision(2);
    arch<<fixed;
    
    c.GetNombre(buffNomb);
    arch<<left<<setw(10)<<c.GetDni()<<setw(50)<<buffNomb<<setw(15)<<
            c.GetTelefono()<<setw(15)<<right<<c.GetMonto_total();
    if(c.GetCantidad_productos_entregados()==0){
        arch << setw(50)<< "NO SE LE ENTREGARON PRODUCTOS" << endl;
    }
    else{ 
        //IMPRIME LA LISTA DE PRODUCTOS ENTREGADOS 
        c.imprimirProductos(arch); 
    }
}
//se le coloca CONST -> para usar los metodos 
void Cliente::imprimirProductos(ofstream &arch) const{
    char buffCod[15];
    
    for(int i=0; i<cantidad_productos_entregados; i++){
        productos_entregados[i].GetCodigo(buffCod); 
        arch<<left<<setw(12)<<buffCod;
    }
}
