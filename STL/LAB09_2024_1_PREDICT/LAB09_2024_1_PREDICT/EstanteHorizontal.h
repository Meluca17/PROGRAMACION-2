/* 
 * File:   EstanteHorizontal.h
 * Author: ramir
 *
 * Created on 21 de junio de 2024, 12:23 AM
 */

#ifndef ESTANTEHORIZONTAL_H
#define ESTANTEHORIZONTAL_H

#include "Estante.h"

class EstanteHorizontal:public Estante {
public:
    EstanteHorizontal();
    EstanteHorizontal(const EstanteHorizontal& orig);
    virtual ~EstanteHorizontal();
    void lee(ifstream &);
private:
    
};

#endif /* ESTANTEHORIZONTAL_H */

