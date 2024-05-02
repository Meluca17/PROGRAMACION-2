/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   arreglos_genericos.h
 * Author: mell1
 *
 * Created on 1 de mayo de 2024, 20:37
 */

#ifndef ARREGLOS_GENERICOS_H
#define ARREGLOS_GENERICOS_H
using namespace std;

void  llenar_arreglo_heroes(void *&arreglo_heroes,int &cantidad_total_heroes,const char *filename);
char *leeCadDelim(ifstream &arch, char delim);
void *leeRegheroes(ifstream &arch);
int cmp_multicriterio_void(const void *a, const void *b);

#endif /* ARREGLOS_GENERICOS_H */

