/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: mell1
 *
 * Created on 1 de mayo de 2024, 18:42
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

using namespace std;
char *leeCadDelim(ifstream &arch,char delim);
double calcularregistro(void *reg);
void *leeregistro(ifstream &arch);
void imprimeregistro(void *dato, ofstream &arch);
int cmpregistro(const void *a, const void *b);
#endif /* PILACONREGISTROS_H */

