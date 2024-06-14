/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 01:51 AM
 */

#ifndef NOVELA_H
#define NOVELA_H
#include "Libro.h"
class Novela:public Libro {
public:
    Novela();
    
    virtual ~Novela();
    void SetTipo(const char* cad);
    void  GetTipo(char* cad) const;
private:
    char *tipo;
};

#endif /* NOVELA_H */

