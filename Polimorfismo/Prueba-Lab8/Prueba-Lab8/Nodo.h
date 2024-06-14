/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 02:07 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Lista.h"
#include "Estante.h"

class Nodo {
public:
    Nodo();
    friend class Lista;
private:
    class Nodo *sig;
    class Estante *est;
    
};

#endif /* NODO_H */

