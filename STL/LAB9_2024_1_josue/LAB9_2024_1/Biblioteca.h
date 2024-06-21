/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Josue
 *
 * Created on 21 de junio de 2024, 12:35 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "ListaEstante.h"

class Biblioteca {
public:
    void carga();
    void llena();
    void muestra();
    void actualiza();
private:
    class ListaEstante lestantes ;
};

#endif /* BIBLIOTECA_H */

