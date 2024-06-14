

/* 
 * File:   Camion.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:16
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"


class Camion:public Vehiculo {
private:
    int ejes; //cantidad de ejes que tiene el vehiculo 
    int llantas; //cantidad de puertas del vehiculo 
public:
    Camion();
    virtual ~Camion();
    void SetEjes(int ejes);
    int GetEjes() const;
    void SetLlantas(int llantas);
    int GetLlantas() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* CAMION_H */

