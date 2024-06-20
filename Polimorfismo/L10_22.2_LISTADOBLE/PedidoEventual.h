

/* 
 * File:   PedidoEventual.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:38
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H

#include "Pedido.h"
using namespace std; 

class PedidoEventual:public Pedido {
private:
    double flete;
public:
    PedidoEventual();
    virtual ~PedidoEventual();
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch); 
    void imprime(ofstream &arch); 
    void actualizaMonto();
};

#endif /* PEDIDOEVENTUAL_H */

