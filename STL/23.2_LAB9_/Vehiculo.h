

/* 
 * File:   Vehiculo.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:31
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "Utils.h"
#include "NPedido.h"
using namespace std;

class Vehiculo {
private:
    int cliente;
    char *placa;
    double maxcarga; // peso max del vehic
    double actcarga; //carga actual 
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
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
    virtual void imprime(ofstream &arch);
    virtual void insertaPed(class NPedido &ped)=0;
};

#endif /* VEHICULO_H */

