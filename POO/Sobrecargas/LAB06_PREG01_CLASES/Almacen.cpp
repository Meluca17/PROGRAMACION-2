
/* 
 * File:   Almacen.cpp
 * Author: mell1
 * 
 * Created on 22 de mayo de 2024, 18:13
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Cliente.h"
#include "Producto.h"
#include "Almacen.h"

Almacen::Almacen() {
    cantidad_clientes = 0; 
    cantidad_productos = 0;
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

///////////////////// FUNCIONES ///////////////////////
void Almacen::cargar_clientes(){
    ifstream arch("Clientes.csv",ios::in); 
    if(!arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    
    while(arch>>arreglo_clientes[cantidad_clientes]){
        cantidad_clientes++; 
    }
}
void Almacen::cargar_productos() {
    ifstream arch("Productos.csv",ios::in); 
    if(!arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    //mientras sea true se lee
    while(arch>>arreglo_productos[cantidad_productos]){
        cantidad_productos++; 
    }
}
//PEDIDOS
// codProd dniC 
void Almacen::cargar_pedidos() {
    ifstream arch("Pedidos.csv",ios::in); 
    if(!arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    
    class Pedido pedido;
    int posCliente, posProducto;
    char codProd[12];
    
    while(arch>>pedido){
        posCliente = buscarCliente(pedido.GetDni_cliente());
        //se encuentra el cliente
        if(posCliente!=-1){
            pedido.GetCodigo(codProd);
            posProducto = buscarProducto(codProd);
            if(posProducto!=-1){
                //agregamos un pedido a un producto -> bool
                if(arreglo_productos[posProducto]+=pedido){
                    arreglo_clientes[posCliente]+=pedido;
                }
            }
        }
        
    }
}

int Almacen::buscarProducto(const char *codBus){
    char buffCod[12];
    
    for(int i=0; i<cantidad_productos; i++){
        arreglo_productos[i].GetCodigo(buffCod);
        if(strcmp(codBus,buffCod)==0) return i;
    }
    
    return -1; 
}

int Almacen::buscarCliente(int dniBus){
    for(int i=0; i<cantidad_clientes; i++){
        if(arreglo_clientes[i].GetDni()== dniBus) return i;
    }
    return -1; 
}
    
void Almacen::mostrar_datos(){
    ofstream arch("ReporteFinal.txt",ios::out); 
    if(!arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1); 
    }
    arch<<setprecision(2)<<fixed;
    arch<<"REPORTE FINAL"<<endl; 
    arch<<"PRODUCTOS: "<<endl; 
    arch<<left<<setw(15)<<"COD.PROD"<<setw(69)<<"DESC."<<setw(12)<<"PRECIO"
            <<setw(12)<<"STOCK"<<endl; 
    for(int i=0; i<cantidad_productos;i++){
        arch<<arreglo_productos[i]; //sobrecarga que imprime un producto
        imprimelinea('-',arch); 
    }
    imprimelinea('=',arch); 
    arch<<endl<<"CLIENTES: "<<endl; 
    arch<<left<<setw(15)<<"DNI"<<setw(69)<<"NOMBRE"<<setw(12)<<"TELEFONO"
            <<setw(12)<<"MONTO TOTAL"<<endl; 
    for(int i=0; i<cantidad_clientes; i++){
        arch<<arreglo_clientes[i]; 
        imprimelinea('-',arch); 
    }
}

void Almacen::imprimelinea(char c, ofstream &arch){
    for(int i=0; i<100; i++) arch<<c; 
    arch<<endl;
}