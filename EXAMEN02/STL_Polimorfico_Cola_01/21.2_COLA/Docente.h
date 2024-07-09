

/* 
 * File:   Docente.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:23 p. m.
 */

#ifndef DOCENTE_H
#define DOCENTE_H

#include "Usuario.h"
using namespace std;

class Docente: public Usuario {
private:
    int anexo;
public:
    Docente();
//    Docente(const Docente& orig);
//    virtual ~Docente();
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream &arch);
    void getDatos(char &tipo,
        char *buffarea,char *buffNombre,  int &anex, int &cel);
    void imprimir(ofstream &arch);
};

#endif /* DOCENTE_H */

