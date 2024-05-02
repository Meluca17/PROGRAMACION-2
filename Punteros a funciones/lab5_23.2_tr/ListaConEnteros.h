/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 14:08
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H
using namespace std; 

void* leenumero(ifstream &arch);
 double calculanumero(void*); //puntero a funcion que devuelve un entero
 //
 void inicializaListaEntero(void *&flota);
 int cmpnumero(const void* ,const void*);
 void imprimenumero(void *camion, ofstream &arch);
 
#endif /* LISTACONENTEROS_H */

