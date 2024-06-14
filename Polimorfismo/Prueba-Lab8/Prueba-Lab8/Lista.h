/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 02:07 AM
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Estante.h"
#include "Libro.h"

class Lista {
public:
    Lista();
    void leeEstantes(const char*nombArch);
    void imprime(const char*nombArc);
    void posicionarLib(const char *nomb);
private:
    class Nodo *lini;
    class Nodo *lfin;
    void asignaMemoria(char tipo,class Estante *&nuevoNodo);
    void insertaNodo(class Estante *dato);
};

#endif /* LISTA_H */

