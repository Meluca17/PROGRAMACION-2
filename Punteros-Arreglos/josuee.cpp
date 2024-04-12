/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#define LINEAS 200
#define NO_ENCONTRO -1
void lecturaDeProductos(const char* nombArch,char ***&productos,
        int *&stock,double *&precios){
    ifstream archProd(nombArch,ios::in);
    if(not archProd.is_open()){
        cout<<"No se pudo abrir el archivo de producots"<<endl;
        exit(1);
    }
    char **buffProductos[200]{};
    int buffStock[200]{},i=0;
    double buffPrecios[200]{};
    while(true){
        buffProductos[i]=leerProductos(archProd);
        if(archProd.eof())break;
        archProd>>buffPrecios[i];
        archProd.get();
        archProd>>buffStock[i];
        archProd.get();
        i++;
    }
    productos=new char **[i+1]{};
    stock=new int [i+1]{};
    precios=new double [i+1]{};
    for(int k=0;k<i;k++){
        productos[k]=buffProductos[k];
        stock[k]=buffStock[k];
        precios[k]=buffPrecios[k];
    }
}

char **leerProductos(ifstream &arch){
    char **buff;
    char *producto,*codigo;
    codigo=leerCadenaExacta(arch,',');
    if(arch.eof())return nullptr;
    producto=leerCadenaExacta(arch,',');
    buff=new char*[2];
    buff[0]=codigo;
    buff[1]=producto;
    return buff;
}
char *leerCadenaExacta(ifstream &arch,char limitador){
    char cadena[60],*nuevaCadena;
    arch.getline(cadena,60,limitador);
    if(arch.eof())return nullptr;
    int longitud=strlen(cadena);
    nuevaCadena=new char[longitud+1];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}
void pruebaDeLecturaDeProductos(const char* nombArch,
        char ***&productos, int *&stock,double *&precios){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"No se pudo abrir el archivo de producots"<<endl;
        exit(1);
    }
    archRep<<fixed;
    archRep.precision(2);
    cabeceraDeProductos(archRep);
    
    for(int i=0;productos[i];i++){
        imprimeCodigoNombre(archRep,productos[i]);
        archRep<<right<<setw(3)<<stock[i]<<setw(10)<<" "<<setw(8)<<precios[i]<<endl;
    }
}

void imprimeCodigoNombre(ofstream &archRep,char **productos){
    archRep<<setw(3)<<" "<<setw(7)<<productos[0]<<setw(5)<<" "<<left<<setw(60)<<
            productos[1];
}

void lecturaDePedidos(const char* nombArch,int *&fechaPedidos,
        char ***&codigoPedidos,int ***&dniCantPedidos){
    int buffFechas[600],**buffCantPedidos[600] ,cantPed[600],cant,dni,dd,mm,
            aa,i=0,fecha,pos;
    char **buffCodigoPedidos[600], *cod,c;
    ifstream archPed(nombArch,ios::in);
    if(not archPed.is_open()){
        cout<<"No se pudo abrir el archivo de producots"<<endl;
        exit(1);
    }
    while (true){
        cod=leerCadenaExacta(archPed,',');
        if(archPed.eof())break;
        archPed>>dni>>c>>cant>>c>>dd>>c>>mm>>c>>aa;
        fecha=aa*10000+mm*100+dd;
        archPed.get();
        pos=tbuscarFecha(buffFechas,fecha,i);
        if(pos==NO_ENCONTRO){//LA FECHA ES NUEVA Y DEBEMOS CREAR UN NUEVO ESPACIO
            agregarFecha(fecha,buffFechas,buffCantPedidos,buffCodigoPedidos,
                    i,pos,cantPed);
        }
        agregarPedido(buffCantPedidos[pos],buffCodigoPedidos[pos],cantPed[pos],
                dni,cant,cod);
    }
    recortarPedidos(buffCantPedidos,buffCodigoPedidos,cantPed,i);
    asignarMemoriaExactaPedidos(buffFechas,buffCantPedidos,buffCodigoPedidos,i,fechaPedidos,
            codigoPedidos,dniCantPedidos);
}

void asignarMemoriaExactaPedidos(int *buffFechas,int ***buffCantPedidos,char ***buffCodigoPedidos,
                int numDatos,int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos){
    fechaPedidos=new int [numDatos+1]{};
    codigoPedidos=new char **[numDatos+1]{};
    dniCantPedidos=new int **[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        fechaPedidos[i]=buffFechas[i];
        codigoPedidos[i]=buffCodigoPedidos[i];
        dniCantPedidos[i]=buffCantPedidos[i];
    }
}
void recortarPedidos(int ***buffCantPedidos,char ***buffCodigoPedidos,int *cantPed,int cantDatos){
    for(int i=0;i<cantDatos;i++){
        asignarMemoriaPedidosCantidad(buffCantPedidos[i],buffCodigoPedidos[i],cantPed[i],i);
    }
    
}
void asignarMemoriaPedidosCantidad(int **&buffCantPedidos,char **&buffCodigoPedidos,int cantPed,int cantDatos){
    if(cantPed!=0){
        char **miniBuffCodigo=new char *[cantPed+1]{};
        int **miniBuffCant=new int *[cantPed+1]{};
        for(int i=0;i<cantPed;i++){
            miniBuffCodigo[i]=buffCodigoPedidos[i];
            miniBuffCant[i]=buffCantPedidos[i];
        }
        delete buffCantPedidos;
        delete buffCodigoPedidos;
        buffCantPedidos=miniBuffCant;
        buffCodigoPedidos=miniBuffCodigo;
    }
}
void agregarPedido(int **buffCantPedido,char **buffCodigoPedidos,int &cantPed,
                int dni,int cant,char *cod){
    buffCodigoPedidos[cantPed]=cod;
    int *aux;
    buffCantPedido[cantPed]=new int [2];
    aux=buffCantPedido[cantPed];
    aux[0]=dni;
    aux[1]=cant;
    cantPed++;
}

void agregarFecha(int fecha,int *buffFechas,int ***buffCantPedidos,char ***buffCodigoPedidos,
                    int &cantDatos,int &pos,int *cantPed){
    buffFechas[cantDatos]=fecha;
    buffCantPedidos[cantDatos]=new int *[600];
    buffCodigoPedidos[cantDatos]=new char *[600];
    cantPed[cantDatos]=0;
    pos=cantDatos;
    cantDatos++;
}
int tbuscarFecha(int *buffFechas,int fecha,int cant){
    for(int k=0;k<cant;k++){
        if(buffFechas[k]==fecha)return k;
    }
    return NO_ENCONTRO;
}
void pruebaDeLecturaDePedidos(const char* nombArch,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"No se pudo abrir el archivo de producots"<<endl;
        exit(1);
    }
    archRep<<setw(60)<<" "<<"REPORTE DE PEDIDOS"<<endl;
    imprimeLinea(archRep,LINEAS,'-');
    int dd,mm,aa;
    for(int i=0;fechaPedidos[i];i++){
        aa=(fechaPedidos[i]/10000);
        mm=(fechaPedidos[i]%10000)/100;
        dd=(fechaPedidos[i]%10000)%100;

        archRep<<setw(5)<<" "<<"FECHA:"<<setfill('0')<<setw(2)<<dd<<"/"<<
                setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        archRep<<setw(5)<<" "<<"CODIGO"<<setw(13)<<" "<<"DNI"<<setw(11)<<" "<<"CANTIDAD"<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        imprimePedidos(archRep, codigoPedidos[i], dniCantPedidos[i]);
        imprimeLinea(archRep,LINEAS,'-');
    }
}

void  reporteDeEnvioDePedidos(const char* nombArch,char ***productos,
        int *stock,double *precios,int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"No se pudo abrir el archivo de producots"<<endl;
        exit(1);
    }
    int dd,mm,aa;
    archRep<<fixed;
    archRep.precision(2);
    double totalFinal=0, perdidoFinal=0, totalResumen=0,perdidoResumen=0;
    archRep<<setw(70)<<" "<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    for(int i=0;fechaPedidos[i];i++){
        imprimeFecha(archRep,fechaPedidos[i]);
        archRep<<"No."<<setw(3)<<" "<<"DNI"<<setw(14)<<" "<<"Producto"<<
                setw(61)<<" "<<"Cantidad"<<setw(4)<<" "<<"Precio"<<setw(7)<<" "<<
                "Total de ingresos"<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        imprimePedidosPorFecha(archRep,productos,stock,precios,codigoPedidos[i],
                dniCantPedidos[i],totalFinal,perdidoFinal);
        archRep<<"Total ingresado: "<<totalFinal<<endl;
        archRep<<"Total perdido: "<<perdidoFinal<<endl;
       imprimeLinea(archRep,LINEAS,'=');
        totalResumen+=totalFinal;
        perdidoResumen+=perdidoFinal;
        totalFinal=perdidoFinal=0;
    }
    
}

void imprimePedidosPorFecha(ofstream &archRep,char ***productos,int *stock,double *precios,
    char **codigoPedidos,int **dniCantPedidos,double &total,double &perdido ){
    int posProducto,*auxDniCant;
    double variable;
    char **auxCodigo;
    for(int i=0;codigoPedidos[i];i++){
        auxDniCant=dniCantPedidos[i];
        posProducto=buscarProducto(productos,codigoPedidos[i]);
        if(posProducto!=NO_ENCONTRO){
            auxCodigo=productos[posProducto]; 
            archRep<<setw(2)<<i+1<<")  "<<setw(8)<<auxDniCant[0]<<setw(10)<<" "<<
                    setw(7)<<auxCodigo[0]<<setw(5)<<" "<<left<<setw(60)<<
                    auxCodigo[1]<<right<<setw(2)<<auxDniCant[1]<<setw(5)<<" "<<
                    setw(8)<<precios[posProducto]<<setw(12)<<" ";
            if(stock[posProducto]-auxDniCant[1]>0){
                variable=precios[posProducto]*auxDniCant[1];
                total+=variable;
                archRep<<setw(9)<<variable<<endl;
                stock[posProducto]-=auxDniCant[1];
            }
            else{
                archRep<<"SIN STOCK"<<endl;
                perdido+=precios[posProducto]*auxDniCant[1];
            }
        }
    }
}

int buscarProducto(char ***productos,char *codigoPedidos){
    char **aux;
    for(int i=0;productos[i];i++){
        aux=productos[i];
        if(strcmp(aux[0],codigoPedidos)==0)return i;
    }
    return NO_ENCONTRO;
}

void imprimeFecha(ofstream &archRep,int fecha){
     int dd,mm,aa;
    aa=(fecha/10000);
    mm=(fecha%10000)/100;
    dd=(fecha%10000)%100;

    archRep<<setw(5)<<" "<<"FECHA:"<<setfill('0')<<setw(2)<<dd<<"/"<<
            setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<endl;
    imprimeLinea(archRep,LINEAS,'=');
}
void imprimePedidos(ofstream &archRep, char **codigoPedidos,int** dniCantPedidos){
    int *aux,a,b;
 
  
    for(int i=0;codigoPedidos[i];i++){
        aux=dniCantPedidos[i];
        archRep<<setw(5)<<" "<<setw(7)<<codigoPedidos[i]<<setw(10)<<" "<<setw(8)<<aux[0]<<
                setw(10)<<" "<<setw(3)<<aux[1]<<endl;
    }
}
void cabeceraDeProductos(ofstream &archRep){
    archRep<<setw(60)<<" "<<"REPORTE DE PRODUCTOS"<<endl;
    imprimeLinea(archRep,LINEAS,'-');
    archRep<<setw(3)<<" "<<"CODIGO"<<setw(6)<<" "<<"NOMBRE"<<setw(53)<<" "<<
            "STOCK"<<setw(10)<<" "<<"PRECIO"<<endl;
    imprimeLinea(archRep,LINEAS,'-');
}

void imprimeLinea(ofstream &archRep,int lineas, char car){
    for(int i=0;i<lineas;i++){
        archRep.put(car);
    }
    archRep<<endl;
}
