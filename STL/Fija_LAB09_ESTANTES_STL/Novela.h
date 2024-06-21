

/* 
 * File:   Novela.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 21:53
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"


class Novela:public Libro {
private:
    char *autor;
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(const char* autor);
    void GetAutor(char*c) const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int anho){};
    void eliminar();
};

#endif /* NOVELA_H */

