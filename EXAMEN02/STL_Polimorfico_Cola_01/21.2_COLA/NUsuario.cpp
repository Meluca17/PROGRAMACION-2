
/* 
 * File:   NUsuario.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:25 p. m.
 */
#include "Utils.h"
using namespace std;
#include "NUsuario.h"
#include "Docente.h"
#include "Administrativo.h"
#include "Estudiante.h"

NUsuario::NUsuario() {
    pusuario = nullptr;
}

NUsuario::NUsuario(const NUsuario& orig) {
    pusuario = nullptr;
    *this = orig;
}

NUsuario::~NUsuario() {
}

void NUsuario::leerUsuario(ifstream &arch){
    int carnet;
    char tipo;
    
    arch>>carnet;
    //cout<<carnet<<endl;
    if(arch.eof())return;
    arch>>tipo;
    //cout<<tipo<<endl;
    arch.get(); //lee cola -> Nmbre,extra
    
    if(tipo=='D'){
         pusuario = new Docente;
    }
    else if(tipo == 'A'){
        pusuario = new Administrativo;
    }
    else{
        pusuario = new Estudiante;
    }

    pusuario->SetCarne(carnet);//seteamos el carnet
    pusuario->SetTipo(tipo);
    //while(arch.get()!='\n');
    pusuario->leer(arch);
}

int NUsuario::getCarneUsuario(){
    return pusuario->GetCarne();
}

void NUsuario::getDatosUsuario(char &tipo,
        char *buffarea,char *buffNombre, int &anex, int &cel){
    //int carne=GetCarne();
    pusuario->getDatos(tipo,buffarea,buffNombre,anex,cel);
}

void NUsuario::imprimirUsuario(ofstream &arch){
    pusuario->imprimir(arch);
}

