/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Josue
 *
 * Created on 20 de junio de 2024, 11:53 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>
using namespace std;
class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* cad);
    void GetNombre(char* cad) const;
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza()=0;
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

