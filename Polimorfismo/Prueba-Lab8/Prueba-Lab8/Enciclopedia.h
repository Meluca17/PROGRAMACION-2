/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 01:47 AM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H
#include "Libro.h"
class Enciclopedia:public Libro {
public:
    Enciclopedia();
    void SetPeso(double peso);
    double GetPeso() const;
private:
    double peso;
};

#endif /* ENCICLOPEDIA_H */

