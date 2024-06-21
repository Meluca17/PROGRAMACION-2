/* 
 * File:   Novela.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:15 AM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela:public Libro {
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(char *cad);
    void GetAutor(char *cad) const;
    void lee(ifstream &);
    void actualiza(){};
    void imprime(ofstream &);
private:
    char *autor;
};

#endif /* NOVELA_H */

