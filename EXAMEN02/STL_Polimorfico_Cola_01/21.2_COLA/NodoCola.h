

/* 
 * File:   NodoCola.h
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:26 p. m.
 */

#ifndef NODOCOLA_H
#define NODOCOLA_H
using namespace std;

class NodoCola {
private:
    char *libsol;
    int carne; //id del usuario
    class NodoCola *sig;
public:
    NodoCola();
    NodoCola(const NodoCola& orig);
    //virtual ~NodoCola();
    void SetSig(NodoCola* sig);
    NodoCola* GetSig() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void SetLibsol(const char* libsol);
    void GetLibsol(char*c) const;
    void leeSolicitud(ifstream &arch);
    void imprimeSolicitud(ofstream &arch);
    
    friend class ColaSol;
};

#endif /* NODOCOLA_H */

