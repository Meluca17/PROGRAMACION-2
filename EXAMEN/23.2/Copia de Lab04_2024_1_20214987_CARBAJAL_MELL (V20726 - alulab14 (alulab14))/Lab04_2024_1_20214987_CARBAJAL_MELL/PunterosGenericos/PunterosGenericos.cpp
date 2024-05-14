/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//Author: MELL ALESSANDRA CARBAJAL ROMAN 20214987
#include <algorithm>

#include "Utils.h"
#include "AperturaDeArchivos.h"
#include "MuestraPunteroGenerico.h"
#include "PunterosGenericos.h"
#define NOT_FOUND -1
using namespace std;
enum Cli{DNI,NOM}; 
enum Reserva{CODLIB, TIT, AUT,PEDIDOS, STOCK}; 
enum Ped{DNICLI,NOMBCLI};
void cargaclientes(void *&clientes){
   ifstream archCli; 
   AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
   
   void *registro, *buff[200]{}; //METODO MEMORIA EXACTA 
   int numDat=0; 
   while(true){
       registro = leeRegCli(archCli); 
       if(registro==nullptr) break; 
       
       buff[numDat] = registro;
       numDat++;
   }
   void **exacto = new void*[numDat+1]{}; //CREAMOS UNA VARIABLE EXACTA Y LE PASAMOS EL BUFF
   for(int i=0; i<numDat; i++){
       exacto[i] = buff[i]; 
   }
   exacto[numDat] = nullptr; 
   
   clientes = exacto; //ASIGNAMOS LA VARIABLE EXACTA A CLIENTES 
   muestraclientes(clientes);
}

char *leeCadDelim(ifstream &arch,char delim){
    char *str, buff[200]{}; 
    arch.getline(buff,200,delim); 
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff); 
    
    return str; 
}
void *leeRegCli(ifstream &arch){
    void **registro; 
    int *dni = new int; 
    char *nomb;
    
    arch>>*dni; 
    if(arch.eof()) return nullptr; 
    arch.get(); 
    nomb = leeCadDelim(arch,'\n'); 
    
    registro = new void*[2]; 
    registro[DNI] = dni;
    registro[NOM] = nomb; 
    
    return registro; 
}

////////////LIBROS//////////////////
void creareserva(void *&reserva){
    ifstream arch; 
   AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
   
   void *registro, *buff[300]{}; //METODO MEMORIA EXACTA
   int numDat=0; 
   while(true){
       registro = leeRegLib(arch); 
       if(registro==nullptr) break; 
       
       buff[numDat] = registro;
       numDat++;
   }
   
   void **exacto = new void*[numDat+1]{}; //CREAMOS UNA VARIABLE EXACTA Y LE PASAMOS EL BUFF
   for(int i=0; i<numDat; i++){
       exacto[i] = buff[i]; 
   }
   exacto[numDat] = nullptr; 
   
   reserva = exacto; //ASIGNAMOS LA VARIABLE EXACTA A RESERVA 
   muestrareservas(reserva);
}
//enum Reserva{CODLIB, TIT, AUT,PEDIDOS, STOCK}; 
void *leeRegLib(ifstream &arch){
    void **registro; 
    char *codLib,*titulo,*autor,c; 
    int *stock = new int, aux_stock; 
    double *precio = new double; 
    
    codLib = leeCadDelim(arch,','); 
    if(arch.eof()) return nullptr; 
    titulo = leeCadDelim(arch,','); 
    autor = leeCadDelim(arch,','); 
    arch>>*stock>>c>>*precio; 
    arch.get(); 
    aux_stock = *stock;
    
    registro = new void*[5]{}; 
    registro[CODLIB] = codLib;
    registro[TIT] = titulo;
    registro[AUT] = autor;
    //RESERVAMOS EL ESPACIO DE MEMORIA SEGUN SU STOCK (POR CADA LIBRO)
    void **aux_ped = (void **)registro[PEDIDOS];
    //+1 por si la funcion de impresion corre hasta el null
    // si la func de impresion corre segun la cant de stock seria [aux_stock] solamente
    aux_ped = new void*[aux_stock+1]{}; //TODOS LOS ESPACIOS NO TENDRAN NADA (NULLPTR)
    registro[PEDIDOS] = aux_ped; 
    
    registro[STOCK] = stock; 
    return registro; 
}


void cargareserva(void *clientes,void *&reserva){
    ifstream arch; 
   AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos2.csv");
   int dniLeid,posCli, posLib, cantPedPorLib[400]{}; 
   char *codLibroLeid; 
   void **aux_reser = (void **)reserva, **aux_cli = (void **)clientes; 
   
   while(true){
       arch>>dniLeid; 
       if(arch.eof()) break; 
       arch.get(); 
       codLibroLeid = leeCadDelim(arch,'\n'); 
       posCli = buscarCliente(dniLeid,clientes); //BUSQUEDA DEL CLIENTE PARA EL NOMB
       if(posCli!=NOT_FOUND){   
           posLib = buscarLibro(codLibroLeid,reserva); //BUSQUEDA DEL LIBRO PARA SABER EN QUE PEDIDOS DE LISTA INSERTAR
           if(posLib!=NOT_FOUND){ //INSERTAMOS EL PEDIDO LEIDO EN POSLIB DE LA RESERVA
               agregaPedDeCliente(aux_reser[posLib],aux_cli[posCli],
                       cantPedPorLib[posLib],dniLeid);
           }
       }
   }
   //SEGUN EL ENUNCIADO NO ES NECESARIO CORTAR EL ARREGLO DE PEDIDOS DE CLIENTE 
}

//PEDIDOS: DNI CODLIB
void agregaPedDeCliente(void *&reservaLibro,void *cliente,int &cantPedPorLib,
                       int dniLeid){
    void **aux_cliente = (void **)cliente; 
    void **auxReserLib = (void **)reservaLibro; //accede a los campos de la reser de un libro
    int *stockLib = (int *)auxReserLib[STOCK], stockIni; //RESERVAMOS UNA NUEVA MEMORIA PARA ALMACENARLO EN EL PEDIDO
    char *nombCliente = (char *)aux_cliente[NOM], *nombreNuevo; 
    nombreNuevo = new char[strlen(nombCliente)+1]; //RESERVAMOS UNA NUEVA MEMORIA PARA ALMACENARLO EN EL PEDIDO
    strcpy(nombreNuevo,nombCliente); 
    
    //pos en el arrPed: 0 1 2 3 ... 19 
    //stock ini: 20 
    stockIni = *stockLib;
    if(*stockLib >0 and cantPedPorLib<stockIni){ //se agrega si hay aun stock
        //AGREGAMOS UN PEDIDO A LA LISTA DE PEDIDOS
        agregaUnPed(auxReserLib[PEDIDOS], cantPedPorLib,dniLeid,nombreNuevo); 
        //cout << nombreNuevo<<endl;      
        //aumentar cantPedPorLib
        cantPedPorLib++;
    }
}


void agregaUnPed(void *pedidosReserLib,int cantPedPorLib,int dniLeid,char *nombreNuevo){
    void **registro = new void *[2]{};
    void **auxPed = (void **)pedidosReserLib; 
    int *dni = new int;
    *dni = dniLeid; 
    
    registro[DNICLI] = dni;
    registro[NOMBCLI] = nombreNuevo; 
    
    auxPed[cantPedPorLib] = registro; 
}
int buscarCliente(int dniLeid,void *clientes){
   void **arrCli = (void **)clientes;  //ACCEDE A INDICES DE CLIENTES
   for(int i=0; arrCli[i]; i++){
       void **client = (void **)arrCli[i]; //ACCEDE A CAMPOS DE CLIENTES 
       int *dni = (int *)client[DNI];
       if(*dni == dniLeid) return i; 
   }
   return NOT_FOUND; 
}

int buscarLibro(char * codLibroLeid,void *reserva){
   void **arrReser = (void **)reserva; //ACCEDE A INDICES DE RESERVAS
   for(int i=0; arrReser[i]; i++){
       void **libro = (void **)arrReser[i]; //ACCEDE A CAMPOS DE LIBROS
       char *codLib = (char *)libro[CODLIB];
       if(strcmp(codLib,codLibroLeid)==0) return i; 
   }
   return NOT_FOUND; 
}