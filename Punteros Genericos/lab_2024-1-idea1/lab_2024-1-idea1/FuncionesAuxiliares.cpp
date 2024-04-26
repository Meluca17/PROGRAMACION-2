/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#define NO_ENCONTRO -1

enum libro{COD,TIT,AUT,PRE};
enum cliente{DNI,NOM,PED,CAN};
void lecturaDeLibros(void *&libros,const char* nombrArch){
    ifstream archLibros(nombrArch,ios::in);
    if(not archLibros.is_open()){
        cout<<"Error: archivo "<<nombrArch<<endl;
        exit(1);
    }
    void *buffLibros[300]{},*datos,**nuevoBuff;
    int cantDatos=0;
    while(true){
        datos=leeLibros(archLibros);
        if(archLibros.eof())break;
        buffLibros[cantDatos]=datos;
        cantDatos++;
    }
    nuevoBuff=new void *[cantDatos+1]{};
    for(int i=0;i<cantDatos;i++){
        nuevoBuff[i]=buffLibros[i];
    }
    libros=nuevoBuff;
}

void *leeLibros(ifstream &archLibros){
    char *codigo,*titulo,*autor;
    int stock;
    double *precio=new double;
    codigo=leeCadena(archLibros);
    if(codigo==nullptr)return nullptr;
    titulo=leeCadena(archLibros);
    autor=leeCadena(archLibros);
    archLibros>>stock;
    archLibros.get();
    archLibros>>*precio;
    archLibros.get();
    void **datos=new void *[4];
    datos[COD]=codigo;
    datos[TIT]=titulo;
    datos[AUT]=autor;
    datos[PRE]=precio;
    return datos;
}
char *leeCadena(ifstream &arch){
    char cadena[60],*exacta;
    arch.getline(cadena,60,',');
    if(arch.eof())return nullptr;
    exacta=new char[strlen(cadena)+1];
    strcpy(exacta,cadena);
    return exacta;
}

void imprimeLibro(void *libros){
    ofstream archRep("reportelibros.txt",ios::out);
    if(not archRep.is_open()){
        cout<<"Error: archivo "<<"reportelibros.txt"<<endl;
        exit(1);
    }
    archRep<<setw(60)<<" "<<"REPORTE DE LIBROS"<<endl;
    imprimeLineas(archRep,'=');
    archRep<<setw(5)<<" "<<"Codigo"<<setw(10)<<" "<<"TITULO"<<setw(50)<<" "<<
            "AUTOR"<<setw(55)<<" "<<"PRECIO"<<endl;
    imprimeLineas(archRep,'-');
    void **auxLibros=(void **)libros;
    archRep<<fixed;
    archRep.precision(2);
    for(int i=0;auxLibros[i];i++){
        imprimeInfoLibro(auxLibros[i],archRep);
    }
}
void imprimeInfoLibro(void *libro,ofstream &archRep){
    void **auxLibro=(void **)libro;
    char *codigo,*autor,
            *titulo;
    double *precio;
    codigo=(char *)auxLibro[COD];
    autor=(char *)auxLibro[AUT];
    titulo=(char *)auxLibro[TIT];
    precio=(double *)auxLibro[PRE];
   
    archRep<<setw(3)<<" "<<setw(7)<<codigo<<setw(7)<<" "<<
            left<<setw(60)<<titulo<<setw(45)<<autor<<right<<setw(10)<<" "<<
            setw(10)<<*precio<<endl;
}
void imprimeLineas(ofstream &archRep,char car){
    for(int i=0;i<200;i++)archRep.put(car);
    archRep<<endl;
}

void lecturaDeClientes(void *&clientes,const char *nombArch){
    ifstream archClientes(nombArch,ios::in);
    if(not archClientes.is_open()){
        cout<<"Error: archivo "<<nombArch<<endl;
        exit(1);
    }
    void *buff[10]{},*datos,**nuevoBuff;
    int cantDatos=0,dni,telefono;
    char *nombre;
    while(true){
        datos=leeCliente(archClientes);
        if(archClientes.eof())break;
        archClientes.get();
        buff[cantDatos]=datos;
        cantDatos++;
    }
    nuevoBuff=new void *[cantDatos+1]{};
    for(int i=0;i<cantDatos;i++){
        nuevoBuff[i]=buff[i];
    }
    clientes=nuevoBuff;
}

void *leeCliente(ifstream &archCliente){
    char *nombre;
    int *dni=new int,telefono;
    archCliente>>*dni;
    if(archCliente.eof())return nullptr;
    archCliente.get();
    nombre=leeCadena(archCliente);
    archCliente>>telefono;
//    cout<<*dni<<" "<<nombre<<" "<<telefono<<endl;
    void **datos=new void *[4];
    int *cant=new int;
    *cant=0;
    datos[DNI]=dni;
    datos[NOM]=nombre;
    datos[PED]=nullptr;
    datos[CAN]=cant;
    return datos;
}

void imprimeCliente(void *clientes,const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"Error: no se pudo abrir "<<nombArch<<endl;
        exit(1);
    }
    void **aux=(void **)clientes;
    archRep<<setw(60)<<" "<<"REPORTE DE CLIENTES"<<endl;
    imprimeLineas(archRep,'=');
    archRep<<setw(5)<<" "<<"DNI"<<setw(8)<<" "<<"NOMBRE DEL CLIENTE"<<setw(15)<<" "<<
            "CANTIDAD DE LIBROS"<<endl;
    imprimeLineas(archRep,'-');
    for(int i=0;aux[i];i++){
        imprimeUnCliente(aux[i],archRep);
    }
}

void imprimeUnCliente(void *cliente,ofstream &archRep){
    void **auxCliente=(void **)cliente;
    int *dni=(int *)auxCliente[DNI],*cant=(int *)auxCliente[CAN];
    char *nombre=(char *)auxCliente[NOM];
    archRep<<setw(3)<<" "<<setw(8)<<*dni<<setw(5)<<" "<<left<<setw(40)<<
            nombre<<setw(5)<<right<<setw(1)<<cant<<endl;
}

void completarPedidos(void *&clientes,void *libros,const char *nombArch){
    ifstream arcPed(nombArch,ios::in);
    if(not arcPed.is_open()){
        cout<<"ERROR: archivo "<<nombArch<<endl;
        exit(1);
    }
    void **auxClientes=(void **)clientes,**auxLibros=(void **)libros;
    int dni,numPedido,cantPedidos[50]{},posCliente,posLibro;
    char *codLibro; 
    while(true){
        arcPed>>dni;
        if(arcPed.eof())break;
        arcPed.get();
        codLibro=leeCadena(arcPed);
        arcPed>>numPedido;
        posCliente=buscarCliente(clientes,dni);
        if(posCliente!=NO_ENCONTRO){
            posLibro=buscarLibro(codLibro,libros);
            agregarLibro(auxClientes[posCliente],auxLibros[posLibro],numPedido,codLibro,
                    cantPedidos[posCliente]);
        }
    }
    for(int i=0;auxClientes[i];i++){
        recortaPedidos(auxClientes[i],cantPedidos[i]);
    }
        
}
void recortaPedidos(void *&cliente,int cantPedidos){
    void **auxClientes=(void **)cliente;
    recortaBuffer(auxClientes[PED],cantPedidos);
}
void recortaBuffer(void *&pedidos,int cantPedidos){
    void **aux=(void **)pedidos,**nuevo;
    if(cantPedidos>0){
//        cout<<cantPedidos<<endl;
        nuevo=new void*[cantPedidos+1]{};
        for(int i=0;i<cantPedidos;i++){
            nuevo[i]=aux[i];
           
        }
        delete aux;
        pedidos=nuevo;
    }
    else{
        delete aux;
        pedidos=nullptr;
    }
}
void agregarLibro(void *&cliente,void *libro,int numPedido,char *codLibro,int &cant){
    void **auxClientes=(void **)cliente,**auxLibros=(void **)libro;
    char *titulo=(char *)auxLibros[TIT],*nuevoTitulo;
    nuevoTitulo=new char[strlen(titulo)+1];
    strcpy(nuevoTitulo,titulo);
    if(cant==0){
        auxClientes[PED]=new void *[200];
    }
    agregamosPedido(numPedido,codLibro,nuevoTitulo,auxClientes[PED],cant);
    int *cantLibros=(int *)(auxClientes[CAN]);
//    int valor;
    
    (*cantLibros)++;
//    cout<<*cantLibros<<endl;
   
    cant++;
}
void agregamosPedido(int numPedido,char *codLibro,char *nuevoTitulo,void *pedidos,int cant){
    void **auxPedido=(void **)pedidos,**datos;
    int *numPed=new int;
    *numPed=numPedido;
    datos=new void *[3];
    datos[0]=codLibro;
    datos[1]=nuevoTitulo;
    datos[2]=numPed;
    auxPedido[cant]=datos;
}
int buscarLibro(char *codLibro,void *libros){
    void **aux=(void **)libros;
    for(int i=0;aux[i];i++){
        if(compararLibros(aux[i],codLibro)==0)return i;
    }
    return NO_ENCONTRO;
}
int compararLibros(void *libro,char *codLibro){
    void **datos=(void **)libro;
    char *cod=(char *)datos[COD];
    return strcmp(cod,codLibro);
}
int buscarCliente(void *clientes,int dni){
    void **aux=(void **)clientes;
    for(int i=0;aux[i];i++){
        if(comparar(aux[i],dni))return i;
    }
    return NO_ENCONTRO;
}

bool comparar(void *cliente,int dni){
    void **datos=(void **)cliente;
    int *cod=(int *)datos[DNI];
    return dni==*cod;
}

void imprimeReporteFinal(void *clientes,const char*nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"Error: no se pudo abrir "<<nombArch<<endl;
        exit(1);
    }
    void **aux=(void **)clientes;
    archRep<<setw(60)<<" "<<"REPORTE DE CLIENTES"<<endl;
    imprimeLineas(archRep,'=');

    for(int i=0;aux[i];i++){
        archRep<<setw(5)<<" "<<"DNI"<<setw(8)<<" "<<"NOMBRE DEL CLIENTE"<<setw(15)<<" "<<
                "CANTIDAD DE LIBROS"<<endl;
        imprimeLineas(archRep,'-');
        imprimeInfoCompletaCliente(aux[i],archRep);
        
         imprimeLineas(archRep,'=');
    }
}
void imprimeInfoCompletaCliente(void *cliente,ofstream &archRep){
    void **auxCliente=(void **)cliente;
    int *dni=(int *)auxCliente[DNI],*cant=(int *)auxCliente[CAN];
    char *nombre=(char *)auxCliente[NOM];
    archRep<<setw(3)<<" "<<setw(8)<<*dni<<setw(5)<<" "<<left<<setw(40)<<
            nombre<<setw(5)<<right<<setw(1)<<*cant<<endl;
    imprimeLineas(archRep,'-');
    archRep<<"LIBROS SOLICITADOS:"<<endl;
    archRep<<"CODIGO"<<setw(10)<<" "<<"TITULO DEL LIBRO"<<" "<<setw(50)<<" "<<
            "NUM PEDIDO"<<endl;
    if(*cant>0){
        imprimePedidos(archRep,auxCliente[PED]);
    }
    
    
}

void imprimePedidos(ofstream &archRep,void *pedidos){
    void **pedido=(void**)pedidos;
    for(int i=0;pedido[i];i++){
        imprimeUnPedido(archRep,pedido[i]);
    }
}

void imprimeUnPedido(ofstream &archRep,void *pedido){
    void **aux=(void **)pedido;
    char *titulo,*codigo;
    int *numPedido;
    titulo=(char *)aux[1];
    codigo=(char *)aux[0];
    numPedido=(int *)aux[2];
    archRep<<setw(2)<<" "<<setw(7)<<codigo<<setw(10)<<" "<<left<<setw(60)<<
            titulo<<right<<setw(5)<<" "<<setw(3)<<*numPedido<<endl;
}