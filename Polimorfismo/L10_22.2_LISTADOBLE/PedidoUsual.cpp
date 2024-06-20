
/* 
 * File:   PedidoUsual.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:35
 */
#include "Utils.h"
#include "PedidoUsual.h"
using namespace std;

PedidoUsual::PedidoUsual() {
}


PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::lee(ifstream &arch){
    arch>>descuento;
    arch.get(); 
    arch>>flete; 
    arch.get(); 
    Pedido::lee(arch); 
    
    double nuevoTot = GetTotal();
    SetTotal(nuevoTot*(1-(descuento/100.0))*(1+(flete/100.0)));
}

void PedidoUsual::imprime(ofstream &arch){
    Pedido::imprime(arch); 
    arch<<left << setw(15)<<"Descuento: "<<descuento<<"%"<<endl; 
    arch<<left << setw(15)<<"Flete: "<<flete<<"%"<<endl<<endl; 
}

void PedidoUsual::actualizaMonto(){
    int total = GetTotal();
    SetTotal(total*(1-(flete/100.0)));
    SetFlete(0);
}