

/* 
 * File:   Procesa.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:44 p. m.
 */

#ifndef PROCESA_H
#define PROCESA_H
#include "Libro.h"
#include "NUsuario.h"
#include "ColaSol.h"
#include <list>
#include <vector>
using namespace std;

class Procesa {
private:
    list < Libro> llibros;
    class ColaSol cola;
    vector < NUsuario> vusuarios;
public:
    Procesa();
//    Procesa(const Procesa& orig);
//    virtual ~Procesa();
    
    void Carga();
    void CargaLibros(const char *filename);
    void CargaUsuarios(const char *filename);
    void LeeSolicitudes(const char *filename);
    void Atiende();
    void Imprime();
    void imprimeCola(ofstream &arch);
    void imprimeLinea(ofstream &arch,char c, int n);
};

#endif /* PROCESA_H */

