

/* 
 * File:   Cliente.h
 * Author: BlueCod (mell1)
 *
 * Created on 23 de mayo de 2024, 16:25
 */

using namespace std; 
#include "LibroSolicitado.h"

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int dni; 
    char *nombre; 
    class LibroSolicitado librosSolicitados[30];
    int cantDeLibros; 
    double paagoTotal; //ptrm me equivoque de nombre :v
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetPaagoTotal(double paagoTotal);
    double GetPaagoTotal() const;
    void SetCantDeLibros(int cantDeLibros);
    int GetCantDeLibros() const;
    void SetDni(int dni);
    int GetDni() const;
    //cadena
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    //extras
    void imprimirLibrosNoEnt(ofstream &) const;
    void imprimirLibrosEnt(ofstream &arch) const;
    bool operator<<(class LibroSolicitado &);
    void operator++();
};
bool operator>>(ifstream &,class Cliente &);
ofstream& operator<<(ofstream &arch, const class Cliente &);

#endif /* CLIENTE_H */

