

/* 
 * File:   PedidoEspecial.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:33
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"
using namespace std; 

class PedidoEspecial:public Pedido {
private:
    double descuento;
public:
    PedidoEspecial();
    virtual ~PedidoEspecial();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualizaMonto(){};
};

#endif /* PEDIDOESPECIAL_H */

