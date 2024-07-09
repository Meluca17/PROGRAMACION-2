

/* 
 * File:   Estudiante.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:24 p. m.
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
using namespace std;

class Estudiante : public Usuario{
private:
    int celular;
public:
    Estudiante();
//    Estudiante(const Estudiante& orig);
//    virtual ~Estudiante();
    void SetCelular(int celular);
    int GetCelular() const;
    void leer(ifstream &arch);
    void getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel);
    void imprimir(ofstream &arch);
};

#endif /* ESTUDIANTE_H */

