/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta02Examen01PunterosGenericos.h
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 10:18 AM
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H
#define PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;



void cargaProductos(void *&productos,const char *nombArch);
void pruebaDeCargaDeProductos(void *productos);
void *leeRegistroProductos(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char limitador);
void aumentarEspacios(void *&productos,int &numDat,int &capacidad);
void asignarDatos(void *&productos,void *datos,int pos);
void imprimeLinea2(ofstream &arch,char lineas);
void imprimirProducto(void *producto,ofstream &archRep);
int compara(const void *a,const void *b);

#endif /* PREGUNTA02EXAMEN01PUNTEROSGENERICOS_H */

