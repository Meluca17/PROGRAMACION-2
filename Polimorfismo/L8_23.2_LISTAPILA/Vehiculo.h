

/* 
 * File:   Vehiculo.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:14
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "Utils.h"
#include "NPedido.h"
using namespace std;

// ACTUA COMO PILA PARA PEDIDOS 
class Vehiculo {
private:
    int cliente; 
    char *placa; 
    double maxcarga; 
    double actcarga; 
    class NPedido *ped; 
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char*c) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &arch);
    bool operator >(const class Vehiculo &); //*rec->unidad > *vehiculo
    virtual void imprime(ofstream &arch);
    void imprimePedido(ofstream &arch);
    void push(class NPedido *);
    double pesoSobrante();
    bool espilavacia();
    
};

#endif /* VEHICULO_H */

