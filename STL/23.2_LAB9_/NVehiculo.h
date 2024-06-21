

/* 
 * File:   NVehiculo.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:45
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include "NPedido.h"
#include "Vehiculo.h"
using namespace std;

class NVehiculo {
private:
    class Vehiculo *unidad;
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    
    void asignamemoria(char tipo);
    void leeDatos(ifstream &arch);
    bool operator <(const class NVehiculo &);
    void imprimeDatos(ofstream &arch);
    int GetCliente ();
    void insertaPedidoVector(class NPedido &ped);
};
//sobrecarga del cout
ostream &operator<<(ostream &out, const class NVehiculo &nveh);
#endif /* NVEHICULO_H */

