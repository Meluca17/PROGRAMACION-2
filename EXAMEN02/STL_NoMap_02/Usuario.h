

/* 
 * File:   Usuario.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 5:06 p. m.
 */

#ifndef USUARIO_H
#define USUARIO_H
using namespace std;

class Usuario {
private:
    int carne;
    char tipo;
    char *nombre;
public:
    Usuario();
    Usuario(const Usuario& orig);
    //virtual ~Usuario();
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    //
    bool leeUsuario(ifstream &arch);
    void imprimeUsuario(ofstream &arch)const ;
    void operator = (const class Usuario &);
    bool operator < (const class Usuario &);
};

#endif /* USUARIO_H */

