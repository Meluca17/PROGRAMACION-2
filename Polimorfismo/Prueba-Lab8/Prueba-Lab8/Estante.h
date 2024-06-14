/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Josue
 *
 * Created on 14 de junio de 2024, 01:55 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "ContenedorLibro.h"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantLib(int cantLib);
    int GetCantLib() const;
    void SetVolumenAct(double volumenAct);
    double GetVolumenAct() const;
    void SetVolumenSop(double volumenSop);
    double GetVolumenSop() const;
    void SetCodigo(const char* cod );
    void GetCodigo(char* cod ) const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream& arch);
    void imprimeLib(ofstream& arch) ;
private:
    char *codigo;
    double volumenSop;
    double volumenAct;
    class ContenedorLibro arrLib[50];
    int cantLib;
};

#endif /* ESTANTE_H */

