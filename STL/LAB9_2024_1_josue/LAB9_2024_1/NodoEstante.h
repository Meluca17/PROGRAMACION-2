/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoEstante.h
 * Author: Josue
 *
 * Created on 21 de junio de 2024, 12:02 AM
 */

#ifndef NODOESTANTE_H
#define NODOESTANTE_H
#include <fstream>
using namespace std;
#include "Estante.h"
#include "ListaEstante.h"
class NodoEstante {
public:
    NodoEstante();
    friend class ListaEstante;
     
private:
    class Estante *estante;
    
    class NodoEstante *sig;
    class NodoEstante *ant;
};

#endif /* NODOESTANTE_H */

