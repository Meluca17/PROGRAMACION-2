/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta01Examen01PunterosMultiples.h
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 10:21 AM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

void cargarPedidos(int **&fecha,char **&codigo,const char *nombArch);
char * leerCadena(ifstream &arch);
void leerFecha(int &fecha,ifstream &archPedidos);
void aumentarEspacios(int **&fecha,char **&codigo,int &cantDatos,int &capacidad);
void asignarDatos(char *&codigo,int *&fecha,char *codProducto,int fechaCompleta,
        int dni,int cantidad);
void quicksort(int **&fecha,char **&codigo,int izq,int der);
void cambiar(int *&fechaIzq,int *&fechaPos,char *&codigoIzq,char *&codigoPos);
int comparar(int *fechaI,int *fechaK);
void pruebaCargaDePedidos(int **fechaClienteCantidad,char **codigoDelProducto,
        const char *nombArch);
void imprimeLinea(ofstream &arch,char car);


#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */

