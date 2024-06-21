/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Josue
 *
 * Created on 20 de junio de 2024, 11:57 PM
 */

#ifndef NOVELA_H
#define NOVELA_H

using namespace std;
#include "Libro.h"
class Novela:public Libro {
public:
    Novela();
    
    virtual ~Novela();
    void SetAutor(const char *cad);
    void GetAutor(char *cad) const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
private:
    char *autor;
};

#endif /* NOVELA_H */

