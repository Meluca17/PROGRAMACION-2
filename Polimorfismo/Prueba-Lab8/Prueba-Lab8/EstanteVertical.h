/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteVertical.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 02:00 AM
 */

#ifndef ESTANTEVERTICAL_H
#define ESTANTEVERTICAL_H
#include "Estante.h"
class EstanteVertical:public Estante {
public:
    void lee(ifstream &arch);
    void SetInicioLetra(char inicioLetra);
    char GetInicioLetra() const;
    void imprime(ofstream& arch);
private:
    char inicioLetra;
};

#endif /* ESTANTEVERTICAL_H */

