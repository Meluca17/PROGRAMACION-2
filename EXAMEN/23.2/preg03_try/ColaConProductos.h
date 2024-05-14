/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConProductos.h
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 11:50 AM
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaGenerica.h"
#include "ColaConProductos.h"

void procesarPedidos(int **fechaCli,char **codigoPedido,void *productos);
int buscarPedido(char *codigoPedido,void *productos);
bool compara(char *codigoPedido,void *producto);
void agregarPedido(int *fechaCli,void *prod);
void crearColaProductos(void *productos);
void reporteDePedidos(void *productos,const char *nombArch);
void imprimeProductos(void *productos,ofstream &archRep);
void imprimePedido(void *datos,ofstream &archRep);
#endif /* COLACONPRODUCTOS_H */

