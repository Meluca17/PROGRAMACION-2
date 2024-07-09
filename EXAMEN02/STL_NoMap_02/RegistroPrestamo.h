

/* 
 * File:   RegistroPrestamo.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 5:09 p. m.
 */

#ifndef REGISTROPRESTAMO_H
#define REGISTROPRESTAMO_H
using namespace std;

class RegistroPrestamo {
private:
    int cliente;
    char tipo;
    char *libPrest;
    int fechaRetiro;
public: 
    RegistroPrestamo();
    RegistroPrestamo(const RegistroPrestamo& orig);
    //virtual ~RegistroPrestamo();
    void SetFechaRetiro(int fechaRetiro);
    int GetFechaRetiro() const;
    void SetLibPrest(const char* libPrest);
    void GetLibPrest(char*c) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    void SetTipo(char tipo);
    char GetTipo() const;
    //
    void leePrestamo(ifstream &arch);
    bool operator <(const class RegistroPrestamo &);
    void operator = (const class RegistroPrestamo &);
    void imprimeDatos(ofstream &arch) const ;
};

#endif /* REGISTROPRESTAMO_H */

