

/* 
 * File:   Camion.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:34
 */

#ifndef CAMION_H
#define CAMION_H
#include <vector>
using namespace std;
#include "NPedido.h"
#include "Vehiculo.h"

class Camion:public Vehiculo {
private:
    int ejes;
    int llantas;
    vector <class NPedido>mdeposito; //puede llevar 5 pedidos como max
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    
    void lee(ifstream &arch);
    void insertaPed(class NPedido &ped);
    void imprime(ofstream &arch);
};

#endif /* CAMION_H */

