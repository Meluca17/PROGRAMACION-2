/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 14:33
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void cargacamiones(void *&flota,int numcamiones,int pesomaximo,void *(*leenumero)(ifstream &),
        double (*calculanumero)(void *),const char *filename); 
void cargaCamExacto(void *&flota,int numcamiones);
void cargaFlotaExacta(void *&camion);
 void push(void *&camionActual,void *dato,double peso);
void muestracamiones(void *flota,int numcamiones,void (*imprimenumero)(void *, ofstream&arch), const char *filename);
void imprimeCamiones(void *camion,ofstream &arch,void (*imprimenumero)(void *, ofstream&arch));
bool pilaVacia(void *cima);
#endif /* FLOTAGENERICA_H */

