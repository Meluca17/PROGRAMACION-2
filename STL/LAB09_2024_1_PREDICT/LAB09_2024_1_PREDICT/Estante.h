/* 
 * File:   Estante.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:20 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <vector>

#include "NodoLibro.h"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetActcapacidad(double actcapacidad);
    double GetActcapacidad() const;
    void SetMaxcapacidad(double maxcapacidad);
    double GetMaxcapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    virtual void lee(ifstream &);
    void agregarLibro(class NodoLibro);
    void actualizaLibros();
    void muestraEstantes(ofstream &);
private:
    char clase;
    int id;
    double maxcapacidad;
    double actcapacidad;
    vector<class NodoLibro>vlibros;
    void imprimirLinea(ofstream &,char);
};

#endif /* ESTANTE_H */

