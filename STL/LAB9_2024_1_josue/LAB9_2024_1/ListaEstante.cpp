/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ListaEstante.cpp
 * Author: Josue
 * 
 * Created on 21 de junio de 2024, 12:07 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaEstante.h"
#include "Estante.h" 
#include "NodoEstante.h"
ListaEstante::ListaEstante() {
    ini=nullptr;
}

void ListaEstante::leeEstantes(ifstream &arch){
    char tipo,car;
    int numero;
    double pesoMax;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch>>car>>numero>>car>>pesoMax;
        insertaEstante(tipo,numero,pesoMax);
    }
}

void ListaEstante::insertaEstante(char tipo, int num, double pesoMax){
    class NodoEstante *nuevoNodo=new class NodoEstante,*aux;
    nuevoNodo->estante=new class Estante;
    nuevoNodo->estante->agregaDatos(tipo,num,pesoMax);
    if(ini==nullptr){
        ini=nuevoNodo;
    }
    else{
        aux=ini;
        while(true){
            if(aux->sig==nullptr){
                break;
            }
            aux=aux->sig;
        }
        aux->sig=nuevoNodo;
        nuevoNodo->ant=aux;
    }
}

void ListaEstante::leeLibros(ifstream &arch){
    class Nodo libro;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        libro.leeDato(arch,tipo);
        if(!insertarLibros(libro)){
            libro.setNull();
        }
    }
}

bool ListaEstante::insertarLibros(class Nodo &libro){
    class NodoEstante *aux;
    aux=ini;
    while(aux){
        if(aux->estante->getSobrante()>=libro.getPeso()){
            aux->estante->insertaLibro(libro);
            return true;
        }
        aux=aux->sig;
    }
    return false;
}

void ListaEstante::imprimeEstantes(ofstream &arch){
    class NodoEstante *aux;
    aux=ini;
    while(aux){
        aux->estante->imprimeEstante(arch);
        for(int i=0;i<100;i++)arch.put('=');
        arch<<endl;
        aux=aux->sig;
    }
}

void ListaEstante::actualizaEstante(){
    class NodoEstante *aux;
    aux=ini;
    while(aux){
        aux->estante->actualizaLibros();
        aux=aux->sig;
    }
}
