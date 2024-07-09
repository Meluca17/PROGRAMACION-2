
/* 
 * File:   RegistroUsuario.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 5:11 p. m.
 */
#include "Utils.h"
using namespace std;
#include "RegistroUsuario.h"

RegistroUsuario::RegistroUsuario() {
    
}

RegistroUsuario::RegistroUsuario(const RegistroUsuario& orig) {
    *this = orig;
}

//RegistroUsuario::~RegistroUsuario() {
//}

bool RegistroUsuario::leeDatos(ifstream &arch){
    //solo llena el usuario 
    if(!usuario.leeUsuario(arch)) return false;
    return true;
}

void RegistroUsuario::imprimeDatos(ofstream &arch) const{
    
    usuario.imprimeUsuario(arch);
    //
    //libros prestados
    //impresion de sus libros prestados
    arch<<left<<setw(70)<<"Libros Prestados:"<<endl;
     for(const RegistroPrestamo  &prest:prestamos){
         //cout<<"ol"<<endl;
         prest.imprimeDatos(arch);
     }

}

bool RegistroUsuario::anhadePrestamo(const class RegistroPrestamo &regPrest){
    //cout<<usuario.GetCarne()<<" "<<regPrest.GetCliente()<<endl;
    if(usuario.GetCarne() == regPrest.GetCliente()){
        //anhadimos el prestamo a la lista de prestamos 
        prestamos.push_back(regPrest);
        return true;
    }else{
        return false;
    }
}

bool RegistroUsuario::tieneLibrosAtrasados(int fechaProceso) const {
    //recorremos los libros prestados del usuario 
    for(const RegistroPrestamo &regPres : prestamos){
        if( (regPres.GetFechaRetiro()+7 ) < fechaProceso ){
            return true;
        }
    }
    return false; 
}

void RegistroUsuario::imprimeUsuario(ofstream &arch) const{
    
    usuario.imprimeUsuario(arch);

}