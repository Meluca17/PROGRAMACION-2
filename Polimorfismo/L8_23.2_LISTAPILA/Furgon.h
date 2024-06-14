

/* 
 * File:   Furgon.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:17
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"
using namespace std;

class Furgon:public Vehiculo {
private:
    int filas; //filas del ve
    int puertas; //puertas del vehiculo
public:
    Furgon();
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* FURGON_H */

