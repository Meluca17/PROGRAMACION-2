
/* 
 * File:   PedidoEventual.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:38
 */
#include "Utils.h"
#include "PedidoEventual.h"
using namespace std;

PedidoEventual::PedidoEventual() {
}


PedidoEventual::~PedidoEventual() {
}

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}


void PedidoEventual::lee(ifstream &arch){
    arch>>flete;
    arch.get(); 
    Pedido::lee(arch); 
    
    double nuevoTot = GetTotal();
    SetTotal(nuevoTot*(1+(flete/100.0)));
}

void PedidoEventual::imprime(ofstream &arch){
    Pedido::imprime(arch); 
    arch<<left << setw(15)<<"Flete: "<<flete<<"%"<<endl<<endl; 
}

void PedidoEventual::actualizaMonto(){
    int total = GetTotal();
    SetTotal(total*(1-(flete/100.0)));
    SetFlete(0);
}