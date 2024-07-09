
/* 
 * File:   NodoCola.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:26 p. m.
 */
#include "Utils.h"
using namespace std;
#include "NodoCola.h"

NodoCola::NodoCola() {
    carne =0;
    libsol = nullptr;
    sig = nullptr;
}

NodoCola::NodoCola(const NodoCola& orig) {
    libsol = nullptr;
    sig = nullptr;
    (*this) = orig;
}

//NodoCola::~NodoCola() {
//}

void NodoCola::SetSig(NodoCola* sig) {
    this->sig = sig;
}

NodoCola* NodoCola::GetSig() const {
    return sig;
}

void NodoCola::SetCarne(int carne) {
    this->carne = carne;
}

int NodoCola::GetCarne() const {
    return carne;
}

void NodoCola::SetLibsol(const char* libsol) {
    if(this->libsol!=nullptr) delete this->libsol;
    this->libsol = new char [strlen(libsol)+1];
    strcpy(this->libsol,libsol);
}
void NodoCola::GetLibsol(char *c) const {
    if(this->libsol==nullptr) c[0] = 0;
    else strcpy(c,this->libsol);
}


void NodoCola::leeSolicitud(ifstream &arch){
    char c,tipo,codLib[100]{};
    
    arch>>carne;
    if(arch.eof()) return;
    arch>>tipo>>c;
    arch.getline(codLib,100);
    
    SetLibsol(codLib);
    //cout<<codLib<<endl;
}

void NodoCola::imprimeSolicitud(ofstream &arch){
    char buff[100]{};
    GetLibsol(buff);
    //cout<<buff<<endl;
    
    arch<<setw(15)<<"Libro: "<<buff<<endl;
    arch<<setw(15)<<"Carnet: "<<carne<<endl;
    
}