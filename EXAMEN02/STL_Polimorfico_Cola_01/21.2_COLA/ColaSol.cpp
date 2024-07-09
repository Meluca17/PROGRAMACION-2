
/* 
 * File:   ColaSol.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:42 p. m.
 */


#include "Utils.h"
using namespace std;
#include "ColaSol.h"
#include "NUsuario.h"
#include "Libro.h"
#include <vector>

ColaSol::ColaSol() {
    fincola = nullptr;
    inicola = nullptr;
    n = 0;
}

ColaSol::ColaSol(const ColaSol& orig) {
    fincola = nullptr;
    inicola = nullptr;
    *this = orig;
}
//
//ColaSol::~ColaSol() {
//}
//
void ColaSol::setN(int n) {
    this->n = n;
}

int ColaSol::getN() const {
    return n;
}
void ColaSol::leeSolicitudes(ifstream &arch){
    //lectura de un nodo 
    NodoCola *dato;
    while(true){
        dato = new NodoCola;
        dato->leeSolicitud(arch);
        if(arch.eof()) return;
        //añadimos a la cola 
        encolar(dato);
    }
}

void ColaSol::encolar(NodoCola *dato){
    //reserva de espacio para el nodo 
    NodoCola* nuevo = new NodoCola;
    nuevo = dato;
    //revisamos la cola 
    if (fincola != nullptr) {
        fincola->sig = nuevo;
    } else { //cola vacia
        inicola = nuevo;
    }
    fincola = nuevo; //el fin siempre se actualza

    n++;
}

NodoCola * ColaSol::desencolar(){
    if(inicola==nullptr) return nullptr;
    
    //desencola un elemento de la cola 
    NodoCola *desencolado=inicola;
    inicola = inicola->sig;
    
    if(inicola ==nullptr){//solo queda un elemento en la cola
        fincola = nullptr;
    }
    
    n--;// ajusta la nueva longitud 
    desencolado->sig = nullptr; //desconecta el nodo 
    
    return desencolado;
}

void ColaSol::desencola2(char *codLib,int &carne){
    NodoCola *aux;
    if(inicola==nullptr){
        carne=0;
        return;
    }
    n--;
    aux=inicola;
    strcpy(codLib,inicola->libsol);
    carne=inicola->carne;
    if(inicola==fincola){
        inicola=nullptr;
        fincola=nullptr;
    }else inicola=inicola->sig;
    delete aux;
}

bool ColaSol::esColaVacia(){
    if(inicola ==nullptr and fincola==nullptr){
        return true;
    }
    else return false;
}

void ColaSol::imprimeDatos(ofstream &arch,vector <NUsuario> vusuarios){
    
    char tipo;
    int posUsu,carne;
    arch<<"EXISTEN "<<n<<" SOLICITUDES PENDIENTES: "<<endl;
    while(!esColaVacia()){
        char buffNombre[100]{},buffArea[100]{},libsol[100];
        
        
//        NodoCola *desencolado = desencolar();
//        desencolado->imprimeSolicitud(arch);
        desencola2(libsol,carne);
        arch<<setw(15)<<"Libro: "<<libsol<<endl;
        arch<<setw(15)<<"Carnet: "<<carne<<endl;
       //desencolado->GetLibsol(buffNombre);
        
        //posicion del usuario
//        posUsu = buscarUsuario(carne,vusuarios);
//        if(posUsu!=-1){
//            //imprimimos los datos extra
//            vusuarios[posUsu].imprimirUsuario(arch);
//            arch<<endl;
//        }
//        
        //delete desencolado;
    }
}


int ColaSol::buscarUsuario(int carnet,vector <NUsuario> vusuarios){
    int i=0;
    for(NUsuario &usu: vusuarios){
        if(carnet == usu.getCarneUsuario()) return i;
        i++;
    }
    return -1;
}

void ColaSol::getDatosUsuario( class NUsuario &usu,char &tipo,
        char *buffarea,char *buffNombre, int &anex, int &cel){
    usu.getDatosUsuario(tipo,buffarea,buffNombre,anex,cel);
}