/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Josue
 *
 * Created on 20 de junio de 2024, 11:56 PM
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H


using namespace std;
#include "Libro.h"
class Enciclopedia :public Libro{
public:
    Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
private:
    int sku;
    int anho;
    int vigencia;
};

#endif /* ENCICLOPEDIA_H */

