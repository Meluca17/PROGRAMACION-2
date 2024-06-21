/* 
 * File:   EstanteVertical.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:23 AM
 */

#ifndef ESTANTEVERTICAL_H
#define ESTANTEVERTICAL_H

#include "Estante.h"

class EstanteVertical:public Estante {
public:
    EstanteVertical();
    EstanteVertical(const EstanteVertical& orig);
    virtual ~EstanteVertical();
    void lee(ifstream &);
private:
    
};

#endif /* ESTANTEVERTICAL_H */

