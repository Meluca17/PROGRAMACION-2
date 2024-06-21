

/* 
 * File:   Enciclopedia.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 21:51
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H

#include "Libro.h"


class Enciclopedia :public Libro{
private:
    int sku;//cod 
    int anho; //publicacion
    int vigencia; // si el libro aun tiene vigencia 
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza(int anhoMax);
    void eliminar();
};

#endif /* ENCICLOPEDIA_H */

