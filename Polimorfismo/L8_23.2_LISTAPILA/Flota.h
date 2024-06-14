

/* 
 * File:   Flota.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:21
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "LVehiculos.h"
class Flota {
private:
    class LVehiculos lista; //aca se guardan todos los vehiculos -> cada cliente tiene un VEH tenga o no pedidos
public:
    Flota();
    virtual ~Flota();
    
    void cargaflota();
    void muestracarga();
    void cargapedidos();
};

#endif /* FLOTA_H */

