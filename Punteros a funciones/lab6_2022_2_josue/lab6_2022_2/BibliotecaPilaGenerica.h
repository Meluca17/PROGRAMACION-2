/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: Josue
 *
 * Created on 2 de mayo de 2024, 11:17 AM
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

void cargaarrelo(void *&arreglo,int (*cmpnumero)(const void*,const void*),
        void *(*leenumero)(ifstream &),const char *nombArch);
void cargapila(void *&pilaini,void *arreglo);
void construyePila(void *&pilaini);
void push(void *&pilaini,void *dato);
bool pilavacia(void *pila);
void muevepila(void *&pilaini,void *&pilafin);
void hanoi(int cantDatos,void *pilaini,void *aux,void *pilafin);
void *pop(void *pila);
void imprimepila(void *pilafin,void (*imp)(void *,ofstream &),const char *nombArch);
#endif /* BIBLIOTECAPILAGENERICA_H */

