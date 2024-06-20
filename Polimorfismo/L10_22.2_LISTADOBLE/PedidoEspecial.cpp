
/* 
 * File:   PedidoEspecial.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:33
 */
#include "Utils.h"
#include "PedidoEspecial.h"
using namespace std;

PedidoEspecial::PedidoEspecial() {
}


PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(ifstream &arch){
    arch>>descuento;
    arch.get(); 
    Pedido::lee(arch); 
    
    double nuevoTot = GetTotal();
    SetTotal(nuevoTot*(1-(descuento/100.0)));
}

void PedidoEspecial::imprime(ofstream &arch){
    Pedido::imprime(arch); 
    arch<<left << setw(15)<<"Descuento: "<<descuento<<"%"<<endl<<endl; 
}