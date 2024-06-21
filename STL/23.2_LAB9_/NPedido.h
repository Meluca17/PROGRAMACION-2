

/* 
 * File:   NPedido.h
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:14
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H
using namespace std;

class NPedido {
private:
    char *codigo; //cod prod
    int cantidad; //cant de prod solicitados
    double peso; // peso de todo el pedido
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*c) const;
    
    void operator =(const class NPedido &);
    void leePed(ifstream &arch);
};

// CLIETNE CODPROD CANT PESO

#endif /* NPEDIDO_H */

