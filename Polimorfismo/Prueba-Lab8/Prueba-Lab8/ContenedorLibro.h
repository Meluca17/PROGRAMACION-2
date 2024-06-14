/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ContenedorLibro.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 01:55 AM
 */

#ifndef CONTENEDORLIBRO_H
#define CONTENEDORLIBRO_H
#include <fstream>
#include <iostream>
using namespace std;
#include "Libro.h"

class ContenedorLibro {
public:
    ContenedorLibro();
    
    virtual ~ContenedorLibro();
private:
    class Libro *plib;
};

#endif /* CONTENEDORLIBRO_H */

