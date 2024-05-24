
/* 
 * File:   LibroSolicitado.cpp
 * Author: mell1
 * 
 * Created on 23 de mayo de 2024, 16:28
 */
#include <cstring>
#include <fstream>
using namespace std; 
#include "LibroSolicitado.h"

LibroSolicitado::LibroSolicitado() {
    //por defecto 
    atendido = false; 
    codigoDelLibro = nullptr; 
    numeroDePedido = 0 ; 
    precio = 0.0;
}

LibroSolicitado::LibroSolicitado(const LibroSolicitado& orig) {
}

LibroSolicitado::~LibroSolicitado() {
    if(codigoDelLibro) delete codigoDelLibro; 
}

void LibroSolicitado::SetAtendido(bool atendido) {
    this->atendido = atendido;
}

bool LibroSolicitado::IsAtendido() const {
    return atendido;
}

void LibroSolicitado::SetPrecio(double precio) {
    this->precio = precio;
}

double LibroSolicitado::GetPrecio() const {
    return precio;
}
void LibroSolicitado::SetNumeroDePedido(int numeroDePedido) {
    this->numeroDePedido = numeroDePedido;
}

int LibroSolicitado::GetNumeroDePedido() const {
    return numeroDePedido;
}

///////////////////////////// CADENA ////////////////////
void LibroSolicitado::SetCodigoDelLibro(const char* codigoDelLibro) {
    //si ya existe un nombre lo deleteamos 
    if(this->codigoDelLibro!=nullptr) delete this->codigoDelLibro; 
    //declaramos el nuevo nombre 
    this->codigoDelLibro = new char [strlen(codigoDelLibro)+1]; 
    strcpy(this->codigoDelLibro, codigoDelLibro);
}

void  LibroSolicitado::GetCodigoDelLibro(char *c) const {
    //si no existe el nombre retorna cad vacia 
    if(this->codigoDelLibro==nullptr) c[0] = 0; 
    else strcpy(c,this->codigoDelLibro); 
}

//////////////////////////// SOBRECARGAS ////////////////////////////////////
bool LibroSolicitado::operator>>(class Libro *arrLib){
    char codSol[12];
    int posLib, stockL;
    double prec;
    
    GetCodigoDelLibro(codSol);
    posLib = buscarLibro(codSol,arrLib);
    if(posLib!=-1){
        stockL =arrLib[posLib].GetStock();
        if(stockL>0){
            arrLib[posLib].SetStock(stockL-1);
            prec = arrLib[posLib].GetPrecio();
            SetPrecio(prec);
            SetAtendido(true);
            return true;
        }
        else{
            SetAtendido(false);
            return false;
        }
    }
    else{
        return false;
    }
    
}
//1. codSol
//2. buscar en arrLib
//3. verificar si se puede atender (stock)

int LibroSolicitado::buscarLibro(char *codSol,class Libro *arrLib){
    char buffC[15];
    int i=0;
    
    while(true){
        arrLib[i].GetCodigo(buffC);
        if(strcmp(buffC,"FIN")==0) break;
        if(strcmp(buffC,codSol)==0) return i;
        i++;
    }

    return -1;
}