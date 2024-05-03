/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConRegistro.h
 * Author: Josue
 *
 * Created on 2 de mayo de 2024, 11:18 AM
 */

#ifndef PILACONREGISTRO_H
#define PILACONREGISTRO_H

void *leeregistro (ifstream &arch);
int cmpregistro (const void *a,const void *b);
void imprimeregistro(void *dato,ofstream &arch);

#endif /* PILACONREGISTRO_H */

