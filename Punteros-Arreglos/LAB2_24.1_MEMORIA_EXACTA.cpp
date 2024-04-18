
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
#define LINEAS 200
#define NO_ENCONTRO -1
enum libros{COD,TIT,AUT};
enum clientes{DNI,CANT};
void lecturaDeLibros(const char *nombaArch,char ***&libros,int **&stock){
    ifstream archLibros(nombaArch,ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DE "<<nombaArch<<endl;
        exit(1);
    }
    int *buffStock[300],cantLibros=0, stockInicial;
    char **buffLibros[300],*titulo,*codigo,*autor,car;
    double precio;
    while(true){
        codigo=leerCadena(archLibros,',');
        if(archLibros.eof())break;
        titulo=leerCadena(archLibros,',');
        autor=leerCadena(archLibros,',');
        archLibros>>stockInicial>>car>>precio>>ws;
        asignarDatosDelLibro(codigo,titulo,autor,stockInicial,buffStock[cantLibros],buffLibros[cantLibros]);
        cantLibros++;
    }
//    cout<<buffLibros[0][0];
    libros=new char **[cantLibros+1]{};
    stock=new int *[cantLibros+1]{};
    for(int i=0;i<cantLibros;i++){
        libros[i]=buffLibros[i];
        stock[i]=buffStock[i];
    }
}
void  asignarDatosDelLibro(char *codigo,char *titulo,char *autor,int stockInicial,
        int *&buffStock,char **&buffLibros){//CUANDO PASAMOS UNA POSICION EXACTA Y SOBRE ELLA QUEREMOS HACER UN NEW EN OTRA FUNCION, DEBEMOS PASARLA POR REFERENCIA
    //EN CASO PASEMOS LA CANT DE DATOS COMO PARAMETRO DE LA FUNCION, YA NO DEBEMOS PASAR POR REFERENCIA YA QUE EL ARREGLO COMPLETO YA ESTA TRABAJANDO
    //COMO REFERENCIA
    buffLibros=new char *[3]{};
    buffLibros[0]=codigo;
    buffLibros[1]=titulo;
    buffLibros[2]=autor;
    buffStock=new int [2]{};
    buffStock[0]=stockInicial;
    buffStock[1]=0;
}
char *leerCadena(ifstream &arch, char limitador){
    char *nuevaCadena,cadena[60];
    arch.getline(cadena,60,limitador);
    if(arch.eof())return nullptr;
    int longitud=strlen(cadena);
    nuevaCadena=new char [longitud+1];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}

void pruebaDeLecturaDeLibros(const char *nombaArch,char ***libros,int **stock){
    ofstream archRep(nombaArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo"<<nombaArch<<endl;
        exit(1);
    }
    archRep<<setw(70)<<" "<<"REPORTE DE LIBROS"<<endl;
    imprimeLineas(archRep,LINEAS,'-');
    archRep<<"CODIGO"<<setw(10)<<" "<<"NOMBRE DEL LIBRO"<<setw(40)<<" "<<
            "AUTOR DEL LIBRO"<<setw(34)<<" "<<"STOCK"<<setw(5)<<" "<<"NO ATENDIDOS"<<endl;
        imprimeLineas(archRep,LINEAS,'-');
        int *aux;
    for(int i=0;libros[i];i++){
        aux=stock[i];
        imprimirNombreLibros(archRep,libros[i]);
        archRep<<setw(3)<<aux[0]<<setw(10)<<" "<<aux[1]<<endl;
    }
}
void imprimirNombreLibros(ofstream &archRep,char **libros){
    archRep<<setw(7)<<libros[COD]<<setw(9)<<" "<<left<<setw(50)<<libros[TIT]<<setw(6)<<" "<<
            setw(50)<<libros[AUT]<<right;
}
void imprimeLineas(ofstream &archRep,int lineas, char car){
    for(int i=0;i<lineas;i++)archRep.put(car);
    archRep<<endl;
}

void atencionDePedidos(const char *nombaArch,char ***libros,int **stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arcPedidos(nombaArch,ios::in);
    if(not arcPedidos.is_open()){
        cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO DE "<<nombaArch<<endl;
        exit(1);
    } 
    int *buffClientes[200]{},numPedido,cantClientes=0,cantPedidos=0,cantSolicitados[200]{},
            dni,posCliente;
    char codigo[8],*cod,car,**buffPedLibros[200]{};
    bool *buffAtendidos[200]{};
    while(true){
        arcPedidos>>numPedido;
        if(arcPedidos.eof())break;
        arcPedidos>>car>>dni;
        posCliente=buscarCliente(cantClientes,buffClientes,dni);
        if(posCliente==NO_ENCONTRO)asignarMemoriaCliente(buffClientes[cantClientes],dni,posCliente,cantClientes);//PRIMERA VEZ QUE LO ENCUENTRA Y DEBEMOS RESERVAR MEMORIA
        agregarNumPedido(buffClientes[posCliente],numPedido);
        buffPedLibros[numPedido-1]=new char*[200]{};
        buffAtendidos[numPedido-1]=new bool [200]{};
        while(true){
            if(arcPedidos.get()=='\n')break;
            arcPedidos>>codigo;
            cod=new char[strlen(codigo)+1];
            strcpy(cod,codigo);
            agregarMemoriaLibros(cod,numPedido,cantPedidos,cantSolicitados[numPedido-1],buffPedLibros[numPedido-1],buffAtendidos[numPedido-1],
                    libros,stock);
        }
        cantPedidos++;
    }
//    cout<<buffClientes[0][3];
    recortaBuffers(buffAtendidos,buffClientes,buffPedLibros,cantClientes,cantPedidos,cantSolicitados);
    asignarMemoriaBuffers(buffAtendidos,buffClientes,buffPedLibros,cantClientes,cantPedidos,
            pedidosClientes,pedidosLibros,pedidosAtendidos);
}
void asignarMemoriaBuffers(bool **buffAtendidos,int **buffClientes,char ***buffPedLibros,
        int cantClientes,int cantPedidos,int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    pedidosClientes=new int*[cantClientes+1]{};
    pedidosLibros=new char ** [cantPedidos+1]{};
    pedidosAtendidos=new bool * [cantPedidos+1]{};
    for(int i=0;i<cantClientes;i++){
        pedidosClientes[i]=buffClientes[i];
    }
    for(int i=0;i<cantPedidos;i++){
        pedidosLibros[i]=buffPedLibros[i];
        pedidosAtendidos[i]=buffAtendidos[i];
    }
}
void recortaBuffers(bool **buffAtendidos,int **buffClientes,char ***buffPedLibros,
        int cantClientes,int cantPedidos,int *cantSolicitados){
    
    for(int i=0;i<cantClientes;i++){
        recortarCliente(buffClientes[i]);
    }
    for(int i=0;i<cantPedidos;i++){
        recortarPedidos(buffPedLibros[i],buffAtendidos[i],cantSolicitados[i]);
    }
    
}
void recortarPedidos(char **&buffPedLibros,bool *&buffAtendidos,int cantSolicitados){
    char **auxLibros=new char *[cantSolicitados+1]{};
    bool *auxAtendidos=new bool [cantSolicitados+1]{};
    if(cantSolicitados>0){
        for(int i=0;i<cantSolicitados;i++){
            auxLibros[i]=buffPedLibros[i];
            auxAtendidos[i]=buffAtendidos[i];
        }
        delete buffAtendidos;
        delete buffPedLibros;
        buffAtendidos=auxAtendidos;
        buffPedLibros=auxLibros;
    }
    else{
        delete buffAtendidos;
        delete buffPedLibros;
        buffAtendidos=nullptr;
        buffPedLibros=nullptr;
    }

}
void recortarCliente(int *&buffClientes){
    int cant=buffClientes[CANT]+2,*aux;
    aux=new int[cant+1]{};
    for(int i=0;i<cant;i++){
        aux[i]=buffClientes[i];
    }
    delete buffClientes;
    buffClientes=aux;
}

void agregarMemoriaLibros(char *codigo,int numPedido,int cantPedidos,int &cantSolicitados,
        char **buffPedLibros,bool *buffAtendidos,char ***libros,int **stock){
//    buffPedLibros=new char*[200]{};
//    buffAtendidos=new bool [200]{};
    int posLibros=buscarLibro(libros,codigo), *auxStock;
    if(posLibros!=NO_ENCONTRO){
        auxStock=stock[posLibros];
        
        buffPedLibros[cantSolicitados]=codigo;
        
        if(auxStock[0]>0){
            buffAtendidos[cantSolicitados]=true;
            auxStock[0]--;
        }
        else{
            buffAtendidos[cantSolicitados]=false;
            auxStock[1]++;
        }
        cantSolicitados++;
    }
}
int buscarLibro(char ***libros,char *codigo){
    char **auxLibro;
    for(int i=0;libros[i];i++){
        auxLibro=libros[i];
        if(strcmp(auxLibro[COD],codigo)==0)return i;
    }
    return NO_ENCONTRO;
}
void agregarNumPedido(int *buffClientes,int numPedido){
    int cant=buffClientes[CANT];
    buffClientes[cant+2]=numPedido;
    buffClientes[CANT]++;
}

void asignarMemoriaCliente(int *&buffClientes,int dni,int &posCliente,int &cantClientes){
    buffClientes=new int [200]{};
    buffClientes[DNI]=dni;
    buffClientes[CANT]=0;
    posCliente=cantClientes;
    cantClientes++;
}
int buscarCliente(int cant,int **buffClientes,int dni){
    int *aux;
    for(int i=0;i<cant;i++){
        aux=buffClientes[i];
        if(aux[DNI]==dni)return i;
    }
    return NO_ENCONTRO;
}


void reporteDeEntregaDePedidos(const char*nombArch,int **pedidosClientes,
            char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(70)<<" "<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    imprimeLineas(archRep,LINEAS,'=');
    int *auxClientes;
    for(int i=0;pedidosClientes[i];i++){
        auxClientes=pedidosClientes[i];
        int dni=auxClientes[DNI];
        archRep<<"CLIENTE: "<<setw(8)<<auxClientes[DNI]<<endl;
        imprimeLineas(archRep,LINEAS,'=');
        imprimirLibros(pedidosAtendidos,pedidosLibros,pedidosClientes[i],archRep);
                imprimeLineas(archRep,LINEAS,'=');
        
    }
}

void imprimirLibros(bool **pedidosAtendidos,char ***pedidosLibros,
        int *pedidosClientes ,ofstream &archRep){

    int codPed;
    for(int i=2;pedidosClientes[i];i++){
        codPed=pedidosClientes[i]-1;
        archRep<<setw(10)<<" "<<"Pedido No."<<setw(15)<<" "<<"CODIGO DEL LIBRO"<<
        setw(21)<<" "<<"OBSERVACION"<<endl;
      
        archRep<<setw(12)<<" "<<setfill('0')<<setw(6)<<codPed+1<<setfill(' ')<<setw(22)<<
                " ";
        if(pedidosLibros[codPed]!=nullptr){
            imprimeAtendido(pedidosAtendidos[codPed],pedidosLibros[codPed],archRep);
            archRep<<endl;
            imprimeLineas(archRep,LINEAS,'-'); 
        }

    }
}

void imprimeAtendido(bool *pedidosAtendidos,char **pedidosLibros,ofstream &arcRep){
    int k;
   
    for(int i=0;pedidosLibros[i];i++){
        k=i;
        arcRep<<setw(7)<<pedidosLibros[i]<<setw(15)<<" ";
        if(pedidosAtendidos[i]==true){
            arcRep<<setw(20)<<"ATENDIDO"<<endl;
        }
        else{
            arcRep<<setw(20)<<"NO ATENDIDO"<<endl;
        }
        arcRep<<setw(40)<<" ";
    }    
    
}
