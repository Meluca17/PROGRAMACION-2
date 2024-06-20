

/* 
 * File:   PedidoUsual.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:35
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include "Pedido.h"
using namespace std; 

class PedidoUsual:public Pedido {
private:
    double descuento;
    double flete; // recargo por gastos de transporte 
public:
    PedidoUsual();
    virtual ~PedidoUsual();
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //
    void lee(ifstream &arch); 
    void imprime(ofstream &arch); 
    void actualizaMonto();
};

#endif /* PEDIDOUSUAL_H */

