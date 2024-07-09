/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Josue
 * 
 * Created on July 2, 2024, 8:07 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <iterator>
#include <string>

using namespace std;
#include "Flota.h"
#include "Vehiculo.h"
#include "Furgon.h"
#include "Camion.h"
#include "Pedido.h"

void Flota::cargar_vehiculos(){
    ifstream arch("Vehiculos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo Vehiculos.csv"<<endl;
        exit(1);
    }
    
    class Vehiculo *dato;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        reservaMemoria(dato,tipo);
        arch.get();
        dato->lee(arch);
        //EL MAP INICIALIZA SU VALUE EN 0 CUANDO LLEGA UNA NUEVA KEY 
        vehiculos[dato->GetPlaca()]=dato;
    }
    
}

void Flota::carga_pedidos(){
    ifstream arch("Pedidos4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo Vehiculos.csv"<<endl;
        exit(1);
    }
    class Pedido ped;

    string cod;
    while(true){
        getline(arch,cod,',');
        if(arch.eof())break;
        if(buscarVehiculo(cod)){
            ped.leePedido(arch);
            vehiculos[cod]->insertar(ped);
        }
        else{
            while(arch.get()!='\n');
        }
    }
}

bool Flota::buscarVehiculo(string cod){
    map <string,Vehiculo *>::iterator it;
    for(it=vehiculos.begin();it!=vehiculos.end();it++){
        if(it->second->GetPlaca().compare(cod)==0)return true;
    }
    return false;
}
void Flota::mostrar_vehiculos(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch<<fixed;
    arch.precision(2);
    arch<<setw(60)<<" "<<"REPORTE DE FLOTA"<<endl;
    imprimeLinea(arch,'=');
    vehiculos["A1Q-612"]->imprime(arch);
    imprimeLinea(arch,'=');
    vehiculos["D9A-711"]->imprime(arch);
    imprimeLinea(arch,'=');
    vehiculos["O8J-848"]->imprime(arch);
    imprimeLinea(arch,'=');
    vehiculos["Q5S-871"]->imprime(arch);
    imprimeLinea(arch,'=');
    vehiculos["Z4L-514"]->imprime(arch);
//    map <string,Vehiculo *>::iterator it;
//    for(it=vehiculos.begin();it!=vehiculos.end();it++){
//        it->second->imprime(arch);
//    }
    
}

void Flota::reservaMemoria(class Vehiculo *&vehiculo,char tipo){
    if(tipo=='F'){
        vehiculo=new class Furgon;
    }
    else{
        vehiculo=new class Camion;
    }
}

void Flota::imprimeLinea(ofstream &arch,char car){
    for(int i=0;i<150;i++)arch.put(car);
    
    arch<<endl;
}


