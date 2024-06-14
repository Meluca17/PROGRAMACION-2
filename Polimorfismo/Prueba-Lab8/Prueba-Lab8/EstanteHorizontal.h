/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteHorizontal.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 02:00 AM
 */

#ifndef ESTANTEHORIZONTAL_H
#define ESTANTEHORIZONTAL_H
#include "Estante.h"
class EstanteHorizontal:public Estante {
public:
    EstanteHorizontal();
    void lee(ifstream &arch);
    virtual ~EstanteHorizontal();
    void SetIdioma(const char *cad);
    void GetIdioma(char *cad) const;
    void imprime(ofstream& arch);
private:
    char *idioma;
};

#endif /* ESTANTEHORIZONTAL_H */

