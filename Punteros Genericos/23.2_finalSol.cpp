
#include "MuestraPunteros.h"
#include "utils.h"
#include "func.h"
#define NOT_FOUND -1
using namespace std;
enum Pro{COD,DESC,PRECIO,TIPO};
enum Cli{DNI,NOMBRE,LISTA,LINEA};
enum Ped{CODIGO,CANT,TOTAL};

 void cargaProductos(void * &productos,const char *filename){
     ifstream arch(filename,ios::in);
     if(not arch.is_open()){
         cout <<"oeoeo";
         exit(1);
     }
     void *registro, *buff[200]{};
     
     int numDat=0;
     while(true){
         registro = leeRegLib(arch);
         if(registro==nullptr) break;
         
         buff[numDat] = registro;
         numDat++;
     }
     
     void **aux_exacto = new void*[numDat+1]{};
     for(int i=0;i<numDat;i++){
         aux_exacto[i] = buff[i];
         
     }
     productos = aux_exacto;
     imprimeproductos(productos);
 }

 char *leeCadDelim(ifstream  &arch, char delim){
     char *str, aux[200];
     arch.getline(aux,200,delim);
     str = new char[strlen(aux)+1]{};
     strcpy(str,aux);
     return str;
 }
 void *leeRegLib(ifstream &arch){
     char *cod, *desc, *nomb, *tipo = new char,c;
     double *precio = new double;
     
     cod = leeCadDelim(arch,',');
     if(arch.eof()) return nullptr;
     desc = leeCadDelim(arch,',');
     arch>>*precio>>c>>*tipo;
     arch.get(); //salto de linea
     
     void **registro = new void*[4];\
     registro[COD] = cod;
     registro[DESC] = desc;
     registro[PRECIO] = precio;
     registro[TIPO] = tipo; 
     
     return registro;
 }

  void cargaClientes(void * &clientes,const char *filename){
     ifstream arch(filename,ios::in);
     if(not arch.is_open()){
         cout <<"oeoeo";
         exit(1);
     }
     void *registro, *buff[200]{};
     
     int numDat=0;
     while(true){
         registro = leeRegCli(arch);
         if(registro==nullptr) break;
         
         buff[numDat] = registro;
         numDat++;
     }
     
     void **aux_exacto = new void*[numDat+1]{};
     for(int i=0;i<numDat;i++){
         aux_exacto[i] = buff[i];
         
     }
     clientes = aux_exacto;
     imprimeclientes(clientes);
 }
  //enum Cli{DNI,NOMBRE,LISTA,LINEA};
   void *leeRegCli(ifstream &arch){
    void **registro = new void*[4];
    char *nombre, aux;
    int *dni = new int, telefono;
    double *lineaCredito = new double;
    
    arch >> *dni >> aux;
    if (arch.eof())
        return nullptr;
    nombre = leeCadDelim(arch,',');
    arch >> telefono >> aux >> *lineaCredito;
    arch.get();
    // Llenar el puntero genérico
    registro[DNI] = dni;
    registro[NOMBRE] = nombre;
    registro[LISTA] = nullptr;
    registro[LINEA] = lineaCredito;
    
     
     return registro;
 }
   
   void *cargaPedidos(void *productos,void *clientes){
       ifstream arch("Pedidos2.csv",ios::in);
     if(not arch.is_open()){
         cout <<"oeoeo";
         exit(1);
     }
       //aux lectura
       char *codLeid,c;
       int dniLeid,cant,posCli,posProd;
       //acceder a campos
       void **aux_productos = (void **)productos;
       void **aux_clientes = (void **)clientes;
       int cantPedCli[200]{}; //cant de pedidos por cliente 
       
       while(true){
           codLeid = leeCadDelim(arch,',');
           if(arch.eof()) break;
           arch>>dniLeid>>c>>cant;
           arch.get();
           
           posCli = buscarCli(dniLeid,clientes);
           
           
           if(posCli!=NOT_FOUND){
               posProd = buscarProducto(codLeid,productos);
               if(posProd!=NOT_FOUND){
                   agregaPedidos(aux_productos[posProd],aux_clientes[posCli],cantPedCli[posCli],cant,dniLeid,codLeid);
               }
           }
       }
       //TIJERITAAAAAAAAA -> cortamos el buffer de pedidos en cada cliente 
       for(int i=0;aux_clientes[i];i++){
           recortaPedidos(aux_clientes[i],cantPedCli[i]);
       }
   }
   
   void recortaPedidos(void *cliente,int cantPedCli){
       void **aux_cli = (void **)cliente; //accede campos cliente 
       recortaExtraPedsCli(aux_cli[LISTA],cantPedCli);
   }
   
   void recortaExtraPedsCli(void *&arrListaped,int cantPedCli){
       void **aux_pedCli = (void **)arrListaped; //accedo a los campos de la lista de pedidos (PED 1 PED 2 PED 3...)
       
       if(cantPedCli>0){
           void **aux = new void*[cantPedCli+1]{}; //guarda los exactos
           for(int i=0;i<cantPedCli;i++){
               aux[i] = aux_pedCli[i]; 
           }
           delete aux_pedCli;
           aux_pedCli = aux;
           arrListaped = aux_pedCli;
       }else{
           delete aux_pedCli;
           arrListaped = nullptr;
       }
   }
//   enum Pro{COD,DESC,PRECIO,TIPO};
//enum Cli{DNI,NOMBRE,LISTA,LINEA};
   void agregaPedidos(void *producto,void *cliente, int &cantPedCli,int cant,int dniLeid,char *codLeid){
       //acceder a campos de un cliente y de un pedido 
       void **aux_cli = (void **)cliente;
       void **aux_prod = (void **)producto;
       
       //1. DARLE ESPACIO A PEDIDOS SI  ES LA PRIMERA VEZ QUE EL CLIENTE COMPRA 
       if(cantPedCli==0){
           aux_cli[LISTA] = new void *[200]{}; //puede tener 200 pedidos
       }
       
       char *tipoProd = (char *)aux_prod[TIPO];
       double *lineaCred = (double *)aux_cli[LINEA];
       double *precio = (double *)aux_prod[PRECIO],total;
       
       if(*tipoProd == 'S'){
           total = (*precio)*cant;
           if(*lineaCred >=total){
               //AÑADIMOS EL PEDIDO AL CLIENTE 
               agregaUnPedido(aux_cli[LISTA],cantPedCli,codLeid,cant,total);
               //descuenta en linea de cred
               *lineaCred= *lineaCred - total;
               cantPedCli++;
           }
       }else{
           //AÑADIMOS EL PEDIDO AL CLIENTE 
            agregaUnPedido(aux_cli[LISTA],cantPedCli,codLeid,cant,total);
           cantPedCli++;
       }
   }

   void agregaUnPedido(void *arrPedidos,int cantPedCli,char *codLeid,int cant,double total){
       void **aux_arrPed = (void **)arrPedidos; // para acceder al indice segun el numero de pedido 0 1 2 3..
       void **registro = new void *[3]{};
       int *cantidad = new int;
       double *totalPedido = new double;
       
       *cantidad = cant;
       *totalPedido = total;
       
       registro[CODIGO] = codLeid;
       registro[CANT] = cantidad;
       registro[TOTAL] = totalPedido;
       
       aux_arrPed[cantPedCli] = registro;
   }
   
   int buscarCli(int dniLeid,void *clientes){
       void **arr_Cli = (void **)clientes; //podemos acceder a cliente 1 2 3 ...
       
       for(int i=0; arr_Cli[i];i++){
           void **cliente = (void **)arr_Cli[i]; //campos del cliente
           int *dni = (int *)cliente[DNI];
           if(*dni ==dniLeid ) return i;
       }
       
       return NOT_FOUND;
   }
   
      int buscarProducto(char *codLeid,void *productos){
       void **arr_Prod = (void **)productos; //podemos acceder a cliente 1 2 3 ...
       
       for(int i=0; arr_Prod[i];i++){
           void **producto = (void **)arr_Prod[i]; //campos del cliente
           char *cod = (char *)producto[COD];
           if(strcmp(cod,codLeid)==0) return i;
       }
       
       return NOT_FOUND;
   }
