
/* 
 * File:   Biblioteca.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 5:15 p. m.
 */
#include "Utils.h"
#include "Biblioteca.h"
using namespace std;

Biblioteca::Biblioteca() {
}

//Biblioteca::Biblioteca(const Biblioteca& orig) {
//}
//
//Biblioteca::~Biblioteca() {
//}



void Biblioteca::leeLibros(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    
    Libro lib;
    while(true){
        lib.leerDatos(arch);
        if(arch.eof()) return;
        libros.push_back(lib);
    }
}

void Biblioteca::imprimeLibros(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    
    arch<<left<<setw(15)<<"Codigo"<<setw(60)<<"Titulo"<<setw(60)
            <<"Autor"<<setw(10)<<"Edicion"<<setw(10)<<"Stock"<<setw(10)
            <<"Precio"<<endl;
    for(const Libro &lib:libros){
        lib.imprimeDatos(arch);
    }
}
//list <Libro> libros;
//    vector <RegistroUsuario> usuarios;
void Biblioteca::leeUsuarios(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    //REGISTRO USUARIO: 
    // class Usuario usuario;
    //list <RegistroPrestamo> prestamos;
    while(true){
        RegistroUsuario regUsu;
        //
        if(!regUsu.leeDatos(arch)) break;
        //push al vector
        usuarios.push_back(regUsu);
    }
}
    
void Biblioteca::imprimeUsuarios(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    
    arch<<left<<setw(10)<<"Tipo"<<setw(15)<<"Carnet"<<setw(60)<<"Nombre"
            <<setw(5)<<" "<<"Cel|Anexo|Area"<<endl;
    
    for(const RegistroUsuario &reg:usuarios){
        reg.imprimeDatos(arch);
        arch<<endl<<endl;
    }
    
    
    
}
//BIBLIOTECA: vector <RegistroUsuario> usuarios;
//            list <Libro> libros;
void Biblioteca::leerPrestamos(const char *filename){
    ifstream arch(filename,ios::in);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    
    while(true){
        RegistroPrestamo regPrest;
        char buff[100];
        regPrest.leePrestamo(arch);
        if(arch.eof())break;
        // buscamos al usuario 
        for(RegistroUsuario &regUsuario:usuarios){
            //cout<<"chi"<<endl;
            if(regUsuario.anhadePrestamo(regPrest)){
                //actualiza stock "prestados en libros"
                regPrest.GetLibPrest(buff);
                actualizaLibros(buff);
                break;
            }
        }
    }
    
}

void Biblioteca::actualizaLibros(char *libPres){
    char buff[100];
    
    for(Libro &lib: libros){
        lib.GetCodigo(buff);
        if(strcmp(buff,libPres)==0){
            lib.SetStock(lib.GetStock()-1);
            cout<<"chi"<<endl;
        }
    }
}
void Biblioteca::imprimirSuspendidos(const char *filename,int dia,int mes,
        int anho){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()){
        cout <<" nooo pipi"<<filename<<endl;
        exit(1);
    }
    
    arch << setw(60)<<"REPORTE DE USUARIOS SUSPENDIDOS"<<endl;
    int fechaProceso =anho*100000 + mes*100 + dia;
    //imprime usuarios con mas de 7 dias de retraso 
    for(const RegistroUsuario &regUsu: usuarios){
        if(regUsu.tieneLibrosAtrasados(fechaProceso)){
            regUsu.imprimeUsuario(arch);
        }
    }
}
