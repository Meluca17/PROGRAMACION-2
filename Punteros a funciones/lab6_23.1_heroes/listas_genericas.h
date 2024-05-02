/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   listas_genericas.h
 * Author: mell1
 *
 * Created on 1 de mayo de 2024, 22:41
 */

#ifndef LISTAS_GENERICAS_H
#define LISTAS_GENERICAS_H

using namespace std;
void crear_lista_heroes(void *arreglo_heroes,void *&lista_heroes,void* (*leer_heroe)( void*));
void* leer_heroe(void *);
void construyeListaCola(void *&lista_heroes);
bool esColaVacia(void *lista);
void insertarListaFinal(void *&lista_heroes,void *datoHeroe);
void imprimir_lista_heroes(const char *filename,void *lista_heroes,void (*imprimir_registro_heroes)(void *, ofstream &));
void imprimir_registro_heroes(void *registro, ofstream &arch);

#endif /* LISTAS_GENERICAS_H */

