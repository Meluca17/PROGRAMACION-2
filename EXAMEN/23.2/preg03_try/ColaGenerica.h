/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaGenerica.h
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 10:37 AM
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

void generacola(void *&cola);
void encola(void *&cola,void *dato);
bool colavacia (void *cola);
void *desencola(void *&cola);


#endif /* COLAGENERICA_H */

