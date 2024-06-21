

/* 
 * File:   Flota.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:46
 */

#ifndef FLOTA_H
#define FLOTA_H
#include <vector>
#include <algorithm>
using namespace std;
#include "NVehiculo.h"

class Flota {
private:
    vector<class NVehiculo>vflota;
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    
    void cargaflota();
    void muestracarga();
    void cargapedidos();
    int buscarCliente(int cliente);
};

#endif /* FLOTA_H */

