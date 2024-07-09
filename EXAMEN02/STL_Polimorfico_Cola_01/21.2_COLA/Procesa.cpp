
/* 
 * File:   Procesa.cpp
 * Author: mell1
 * 
 * Created on 7 de julio de 2024, 11:44 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Libro.h"
#include "Usuario.h"
#include "NUsuario.h"
#include "Procesa.h"
#include <algorithm>

//list < Libro> llibros;
//    class ColaSol cola;
//    vector < NUsuario> vusuarios;
Procesa::Procesa() {
    
}
//Procesa::Procesa(const Procesa& orig) {
//}
//
//Procesa::~Procesa() {
//}
void Procesa::Carga(){
    //llama a los metodos de carga 
    CargaLibros("Libros2.csv");
    CargaUsuarios("Usuarios2.csv");
    LeeSolicitudes("SolicitudDePrestamos2.csv");
}

void Procesa::CargaLibros(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch){
        cout << "No se abrio"<<filename<<endl;
        exit(1);
    }
    char buff[100];
    
    class Libro lib;
    while(true){
        if(lib.leeDatos(arch)==false) break;
//        lib.GetCodigo(buff);
//        cout <<buff<<endl;
        //agregamos el libr al list 
        llibros.push_back(lib);
    }
}
void Procesa::CargaUsuarios(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch){
        cout << "No se abrio"<<filename<<endl;
        exit(1);
    }
    
    while(true){
        NUsuario nusuario;
        nusuario.leerUsuario(arch);
        if(arch.eof()) break;
        //push back en el vector
        vusuarios.push_back(nusuario);
    }
}

void Procesa::LeeSolicitudes(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch){
        cout << "No se abrio"<<filename<<endl;
        exit(1);
    }
    
    cola.leeSolicitudes(arch);
}

void Procesa::Atiende(){
    //Atiende las N solicitudes
    for(int i=0; i<cola.getN();i++){
        //1. dsesencolar una solicitud
        NodoCola *solicitud = cola.desencolar();
        bool atendido = false;
        //2. verficiar STL - list llibros si aun hay stock del libro solicitado 
        for(Libro &lib:llibros){
            char codLib[100], codSol[100];
            lib.GetCodigo(codLib);
            solicitud->SetLibsol(codSol);
            if(strcmp(codLib,codSol)==0){
                if(lib.GetStock()>0){
                    atendido=true;
                    lib.SetStock(lib.GetStock()-1);
                }
                break;
            }
        }
        //OTRA FORMA: el it es un PUNTERO
//        for(list<Libro>::iterator it=llibros.begin(); it!=llibros.end();it++){
//            char codLib[100], codSol[100];
//            (*it).GetCodigo(codLib);
//            solicitud->GetLibsol(codSol);
//            if(strcmp(codLib,codSol)==0){
//                if((*it).GetStock()>0){
//                    atendido=true;
//                    (*it).SetStock((*it).GetStock()-1);
//                }
//                break;
//            }
//        }
        
        if(atendido==false) cola.encolar(solicitud);
    }
}

void Procesa::Imprime(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout << "No se abrio"<<endl;
        exit(1);
    }
    arch<<setw(60)<<"REPORTE DE LIBROS"<<endl;
    imprimeLinea(arch,'=',100);
    for(Libro &lib: llibros){
        lib.imprimeDatos(arch);
    }
    imprimeLinea(arch,'=',100);
    arch<<setw(60)<<"REPORTE DE SOLICITUDES PENDIENTES"<<endl;
    imprimeLinea(arch,'=',100);
    imprimeCola(arch);
}

void Procesa::imprimeCola(ofstream &arch){
    cola.imprimeDatos(arch,vusuarios);
}

void Procesa::imprimeLinea(ofstream &arch,char c, int n){
    for(int i=0;i<n;i++){
        arch.put(c);
    }
    arch<<endl;
}

//void Procesa::ImprimeCola(ofstream &arch){
//    char cad[80];
//    int carne;
//    while(cola.notEmpty()){
//        cola.desencola(cad,carne);
//        arch<<setw(10)<<left<<"Libro:"<<left<<cad<<endl;
//        imprimeUsuario(carne,arch);
//        arch<<endl;
//    }
//}
//
//void Procesa::imprimeUsuario(int carne,ofstream &arch){
//    for(vector<class NUsuario>::iterator it=vusuarios.begin();it!=vusuarios.end();it++){
//        if((*it).carne()==carne){
//            (*it).imprime(arch);
//        }
//    }
//}