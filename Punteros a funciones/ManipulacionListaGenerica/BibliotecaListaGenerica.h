/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: alulab14
 *
 * Created on 29 de abril de 2024, 06:18 PM
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

#include <list>
using namespace std; 

void crearLista(ifstream &arch,void *&lista, 
        void* (*)(ifstream &), int (*)(const void*, const void*)); 
//    imprimirLista(lista, imprimeEntero); 
void imprimirLista(void*, void (*)(void *));
//    eliminarLista(lista, eliminaEntero); 
void imprimirLista(void*, void (*)(void *)); 
void insertaLista(void *&lista,void * dato, int (*comp)(const void*, const void*)); 

#endif /* BIBLIOTECALISTAGENERICA_H */

