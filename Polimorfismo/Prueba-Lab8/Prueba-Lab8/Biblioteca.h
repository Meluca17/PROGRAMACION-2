/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 02:08 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Lista.h"

class Biblioteca {
public:
    void cargaEstantes();
    void muestraDatos();
    void posicionarLib();
    
private:
    class Lista lestantes;
};

#endif /* BIBLIOTECA_H */

