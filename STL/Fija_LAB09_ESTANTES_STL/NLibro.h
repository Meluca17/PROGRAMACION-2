

/* 
 * File:   NLibro.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 23:01
 */

#ifndef NLIBRO_H
#define NLIBRO_H
#include "Libro.h"
using namespace std;

class NLibro {
private:
    class Libro *unidad;
public:
    NLibro();
    NLibro(const NLibro& orig);
    virtual ~NLibro();
    void asignaMemoria(char tipo);
    void leeLibro(ifstream &arch);
    double GetPesoLibro();
    void imprimeLibro(ofstream &arch);
    void actualizaLibro(int anho);
    void eliminar();
};

#endif /* NLIBRO_H */

