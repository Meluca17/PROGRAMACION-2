/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConEnteros.h
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 10:37 AM
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaGenerica.h"
void cargaEnteros(void *&cola,void *(*leenum)(ifstream &),const char *nombArch);
void *leenumero(ifstream &arch);
void mostrarEnteros(void *&cola,void (*imprimenumero)(ofstream &,void *),const char *nombArch);
void imprimenumero(ofstream &archRep,void *dato);
#endif /* COLACONENTEROS_H */

