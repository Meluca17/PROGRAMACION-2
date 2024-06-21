/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Josue
 * 
 * Created on 21 de junio de 2024, 12:01 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    id=0;
    capacidad=0;
     
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

void Estante::agregaDatos(char tipo, int numero, double peso){
    SetId(numero);
    SetCapacidad(peso);
    SetClase(tipo);
}

double Estante::getSobrante(){
    int cantLibros=nLibros.size();
    double pesoAcumulado=0;
    for(int i=0;i<cantLibros;i++){
        pesoAcumulado+=nLibros[i].getPeso();
    }
    
    return capacidad-pesoAcumulado;
}

void Estante::insertaLibro(class Nodo &libro){
    nLibros.push_back(libro);
}

void Estante::imprimeEstante(ofstream &arch){
    arch<<"Id: "<<id<<endl;
    if(clase=='H'){
        arch<<"Tipo: Horizontal"<<endl;
    }
    else{
        arch<<"Tipo: Vertical"<<endl;
    }
    arch<<"Capacida: "<<capacidad<<endl;
    int cantLibros=nLibros.size();
    if(cantLibros==0){
        arch<<"El estante no tiene libros"<<endl;
    }
    else{
        arch<<"Libros Contenidos"<<endl;
        for(int i=0;i<100;i++)arch.put('=');
        arch<<endl;
        for(int i=0;i<cantLibros;i++){
            nLibros[i].imprimeLibro(arch);
            for(int i=0;i<100;i++)arch.put('_');
            arch<<endl;
        }
    }
}

void Estante::actualizaLibros(){
    int cantLibros=nLibros.size();
    for(int i=0;i<cantLibros;i++){
        nLibros[i].actualiza();
    }
}