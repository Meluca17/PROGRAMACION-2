
/* 
 * File:   AlmacenBib.cpp
 * Author: mell1
 * 
 * Created on 23 de mayo de 2024, 22:57
 */
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#define LINEAS 100
#include "AlmacenBib.h"
#include "LibroSolicitado.h"
#include "Cliente.h"
#include "Libro.h"

AlmacenBib::AlmacenBib() {
    cantidad_clientes = 0;
    cantidad_libros =0;
}

AlmacenBib::AlmacenBib(const AlmacenBib& orig) {
}

AlmacenBib::~AlmacenBib() {
}

void AlmacenBib::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int AlmacenBib::GetCantidad_libros() const {
    return cantidad_libros;
}

void AlmacenBib::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int AlmacenBib::GetCantidad_clientes() const {
    return cantidad_clientes;
}

/////////////////////////////////////////////////////////////////////
void AlmacenBib::cargar_clientes(){
    ifstream arch("Cientes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de clientes"<<endl;
        exit(1);
    }
    //lectura de clientes 
    while(arch>>arreglo_clientes[cantidad_clientes]){
        cantidad_clientes++;
    }
    arreglo_clientes[cantidad_clientes].SetDni(0);
}
void  AlmacenBib::cargar_libros(){
    ifstream arch("Libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de libros"<<endl;
        exit(1);
    }
    //lectura de clientes 
    while(arch>>arreglo_libros[cantidad_libros]){
        cantidad_libros++;
    }
    arreglo_libros[cantidad_libros].SetCodigo("FIN");
}

//Como es un metodo de AlmacenBib:: ya tengo sus atributos -> arrCli , arrProd
void AlmacenBib::cargar_pedidos(){
    ifstream arch("Pedidos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"Error:No se pudo abrir el archivo de ped"<<endl;
        exit(1);
    }
    
    int numPed,dniPed, posCli;
    char buffCod[10],c;
    
    while(true){
        class LibroSolicitado pedido;
        arch>>numPed;
        if(arch.eof()) break;
        arch>>c>>dniPed>>c;
        pedido.SetNumeroDePedido(numPed);
        //LISTA DE PEDIDOS 
        posCli = buscarCliente(dniPed);
        if(posCli!=-1){
           while(true){
//               cout<<"HOLA"<<endl;
               arch>>buffCod;
               pedido.SetCodigoDelLibro(buffCod);
               
               if(pedido>>arreglo_libros){
                   arreglo_clientes[posCli]<<pedido;
                   ++arreglo_clientes[posCli];
               }
              
               if(arch.get()=='\n') break;
            }    
        }
        //DESCARTO LA LINEA 
        else{
            while(arch.get()!='\n');
        }
    }
}


int AlmacenBib::buscarCliente(int dniBus){
    for(int i=0; i<cantidad_clientes;i++){
        if(dniBus == arreglo_clientes[i].GetDni()) return i;
    }
    return -1;
}

void AlmacenBib::mostrar_datos(){
    ofstream archRep("RepFinal.txt",ios::out);
    
    archRep<<setw(60)<<" "<<"REPORTE DE LIBROS"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    ////////////////////////// imprime libro ////////////////////////
    archRep<<setw(3)<<" "<<"CODIGO"<<setw(8)<<" "<<"NOMBRE DEL LIBRO"<<setw(62)<<" "<<"AUTOR"<<
            setw(20)<<" "<<"STOCK"<<setw(8)<<" "<<"PRECIO"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    
    char buffC[15];
    int k=0;
    while(true){
        arreglo_libros[k].GetCodigo(buffC);
        if(strcmp(buffC,"FIN")==0) break;
        archRep<<arreglo_libros[k];
        k++;
    }
    
    imprimeLinea(archRep,LINEAS,'=');
    imprimeLinea(archRep,LINEAS,'/');
    imprimeLinea(archRep,LINEAS,'=');
    archRep<<setw(60)<<" "<<"REPORTE DE CLIENTES"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    ////////////////////////// imprime cliente ////////////////////////
    archRep<<setw(3)<<" "<<"DNI"<<setw(8)<<" "<<"NOMBRE DEL CLIENTE"<<endl;
    imprimeLinea(archRep,LINEAS,'=');

    int i=0,dniC;
    while(true){
        dniC = arreglo_clientes[i].GetDni();
        if(dniC==0) break;
        //imprime :)
        archRep<<arreglo_clientes[i];
        ++arreglo_clientes[i];
        i++;
    }
    
}

void AlmacenBib::imprimeLinea(ofstream &arch,int n, char c){
    for(int i=0;i<n;i++) arch<<c;
    arch<<endl;
}