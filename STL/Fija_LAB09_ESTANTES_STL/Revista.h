

/* 
 * File:   Revista.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 21:55
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"


class Revista:public Libro {
private:
    int ISSN; // codigo de  la publicacin 
    int anho; 
    int numero;
    int vigencia;
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int );
    void eliminar();
};

#endif /* REVISTA_H */

