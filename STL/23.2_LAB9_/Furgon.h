

/* 
 * File:   Furgon.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:42
 */

#ifndef FURGON_H
#define FURGON_H
#include "Utils.h"
#include <vector>
using namespace std;
#include "NPedido.h"
#include "Vehiculo.h"

class Furgon:public Vehiculo {
private:
    int filas;
    int puertas;
    vector<class NPedido>mdeposito; 
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void insertaPed(class NPedido &ped);
};

#endif /* FURGON_H */

