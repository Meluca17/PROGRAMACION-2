
/*/ 
 * Projecto:  AsignacionDinamicaMemoriaExacta-2023-2
 * Nombre del Archivo:  AsignacionDinamicaMemoriaExacta.cpp
 * Autor: new Candy ****[sizeof(urMom)]{};
/*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define XD -1
#define MAXTEXTO 60
#define TAMLINEA 136
#define MAXPROD 200
#define MAXFECHAS 600
#define MAXPED_FECHA 100

                         /* / [ - Pregunta #1 - ] / */

// Modulo de Carga de Datos de Producto
void lecturaDeProducto(const char *nombArch,char ***&productos,int *&stock,
                       double *&precios){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archProd = abrirArchivo_IFS(nombArch);
    int numProd = 0,arrStock[MAXPROD];
    double arrPrecios[MAXPROD];
    char **buff,**arrProdBuff[MAXPROD];
    // Iterativa del Proceso de Carga de Datos de Producto
    while(1){
        buff = obtenerBuff_Prod(archProd);
        if(buff == nullptr) break;
        arrProdBuff[numProd] = buff;
        archProd>>arrPrecios[numProd];
        archProd.get();
        archProd>>arrStock[numProd];
        archProd.get();
        numProd++;
    }
    // Inicializacion de Elementos
    stock = new int[numProd + 1]{};
    precios = new double[numProd + 1]{};
    productos = new char**[numProd + 1]{};
    // Compresion de Elementos Hacia Medida Exacta
    for(int i = 0;i < numProd;i++){
        productos[i] = arrProdBuff[i];
        stock[i] = arrStock[i];
        precios[i] = arrPrecios[i];
    }
}
// Modulo de Carga de Buff de 'Producto' [Codigo && Nombre]
char **obtenerBuff_Prod(ifstream &archEntrada){
    // Declaracion de Variables
    char *cadAux,**buff;
    // Proceso de Lectura & Carga de Buff
    cadAux = obtenerCadenaExacta(archEntrada,',');
    if(cadAux == nullptr) return nullptr;                                       // Validacion de Fin de Archivo
    buff = new char*[2];
    buff[PROD_COD] = cadAux;
    cadAux = obtenerCadenaExacta(archEntrada,',');
    buff[PROD_NOMB] = cadAux;
    return buff;
}
// Modulo de Impresion de Datos en Formato PREDETERMINADO del Estado de Registros de 'Producto'
void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,
                                int *stock,double *precios){
    // Apertura de Archivos
    ofstream archSalida = abrirArchivo_OFS(nombArch);    
    // Proceso de Impresion de Registros de 'Producto'
    imprimirEncabezado(archSalida,'A',101);
    for(int i = 0;productos[i];i++){
        archSalida<<setw(11)<<(productos[i])[PROD_COD]<<setw(4)<<' ';
        archSalida<<left<<setw(MAXTEXTO)<<(productos[i])[PROD_NOMB]<<right;
        archSalida<<setw(6)<<stock[i]<<setw(16)<<precios[i]<<endl;
    }
    imprimirLinea(archSalida,101,'=');
}

                         /* / [ - Pregunta #2 - ] / */

// Modulo de Carga de Datos de Pedido
void lecturaDePedidos(const char *nombArch,int *&fechaPedidos,
                      char ***&codigoPedidos,int ***&dniCantPedidos){
    // Apertura de Archivos && Declaracion de Variables
    ifstream archPed = abrirArchivo_IFS(nombArch);
    int numFechas = 0,dd,mm,aa,fecha,posFecha;
    int **arrBuffs_Fecha[MAXFECHAS]{},arrFechas[MAXFECHAS]{},*buff;
    char **arrProdIDs_Fecha[MAXFECHAS]{},*prodID,simbolo;
    // Iterativa del Proceso de Carga de Datos de Pedido
    while(1){
        prodID = obtenerCadenaExacta(archPed,',');
        if(prodID == nullptr) break;                                            // Validacion de Fin de Archivo
        buff = obtenerBuff_Ped(archPed);
        archPed>>dd>>simbolo>>mm>>simbolo>>aa>>ws;
        fecha = compactarFecha(dd,mm,aa);
        posFecha = obtenerPosFecha(fecha,arrFechas,numFechas);
        // Validacion de Insercion de Nueva Fecha
        if(posFecha == XD){
            posFecha = numFechas;
            arrFechas[posFecha] = fecha;
            numFechas++;
        }
        // Insercion de Datos por Fecha
        insertarDatosPorFecha(arrProdIDs_Fecha[posFecha],
                              arrBuffs_Fecha[posFecha],prodID,buff);
    }
    // Almacenamiento Exacto de Datos Cargados
    almacenarDatosComprimidos(arrProdIDs_Fecha,arrBuffs_Fecha,arrFechas,
                              codigoPedidos,dniCantPedidos,fechaPedidos,
                              numFechas);
}
// Modulo de Carga de Buff de Doble Parametro
int *obtenerBuff_Ped(ifstream &archEntrada){
    // Declaracion de Variables
    int dni,cantidad,*buff;
    // Proceso de Lectura & Carga de Buff
    archEntrada>>dni;
    archEntrada.get();
    archEntrada>>cantidad;
    archEntrada.get();
    buff = new int[2];
    buff[PED_DNI] = dni;
    buff[PED_CANT] = cantidad;
    return buff;
}
// Modulo de Insercion de Datos por Fecha
void insertarDatosPorFecha(char **&prodIDs,int **&buffs,char *prodID,int *buff){
    // Declaracion de Variables
    int numPedidos = 0;
    // Validacion de Existencia de Elementos
    if(!buffs){
        prodIDs = new char*[MAXPED_FECHA]{};
        buffs = new int*[MAXPED_FECHA]{};
    }
    // Proceso de Insercion de Datos
    while(buffs[numPedidos]) numPedidos++;
    prodIDs[numPedidos] = prodID;
    buffs[numPedidos] = buff;
}
// Modulo de Almacenamiento & Compresion de Datos Cargados a Medida Exacta
void almacenarDatosComprimidos(char ***arrProdIDs_Fecha,int ***arrBuffs_Fecha,
                               int *arrFechas,char ***&codigoPedidos,
                               int ***&dniCantPedidos,int *&fechaPedidos,
                               int numFechas){
    // Iterativa del Proceso de Compresion de Datos de Pedidos por Fecha
    for(int i = 0;arrProdIDs_Fecha[i];i++)
        comprimirPedidosDeFecha(arrProdIDs_Fecha[i],arrBuffs_Fecha[i]);
    // Inicializacion de Elementos
    codigoPedidos = new char**[numFechas+1]{};
    dniCantPedidos = new int**[numFechas+1]{};
    fechaPedidos = new int[numFechas+1]{};
    // Compresion de Elementos Hacia Medida Exacta
    for (int i = 0;i < numFechas;i++) {
        codigoPedidos[i] = arrProdIDs_Fecha[i];
        dniCantPedidos[i] = arrBuffs_Fecha[i];
        fechaPedidos[i] = arrFechas[i];
    }
}
// Modulo de Compresion de Datos de Pedidos por Fecha
void comprimirPedidosDeFecha(char **&prodIDs,int **&buffs){
    // Declaracion de Variables
    int numPedidos,**comp_buffs; char **comp_prodIDs;
    // Inicializacion de Elementos Exactos
    for (numPedidos = 0;prodIDs[numPedidos];numPedidos++);
    comp_prodIDs = new char*[numPedidos+1]{};
    comp_buffs = new int*[numPedidos+1]{};
    // Proceso de Compresion de Datos
    for(int i = 0;i < numPedidos;i++){
        comp_prodIDs[i] = prodIDs[i];
        comp_buffs[i] = buffs[i];
    }
    delete prodIDs;
    delete buffs;
    prodIDs = comp_prodIDs;
    buffs = comp_buffs;
}
// Modulo de Impresion de Datos en Formato PREDETERMINADO de Estado de Datos de Pedido
void pruebaDeLecturaDePedidos(const char *nombArch,int *fechaPedidos,
                              char ***codigoPedidos,int ***dniCantPedidos){
    // Apertura de Archivos && Declaracion de Variables
    ofstream archSalida = abrirArchivo_OFS(nombArch);
    int dd,mm,aa;
    // Proceso de Impresion de Datos de Estado de Pedido
    imprimirEncabezado(archSalida,'B',40);
    for(int i = 0;codigoPedidos[i];i++){
        archSalida<<setw(10)<<"FECHA:  ";
        descompactarFecha(fechaPedidos[i],dd,mm,aa);
        imprimirFecha(archSalida,dd,mm,aa);
        archSalida<<endl;
        imprimirEncabezado(archSalida,'C',40);
        for(int j = 0;(codigoPedidos[i])[j];j++){
            archSalida<<setw(11)<<(codigoPedidos[i])[j];
            archSalida<<setw(12)<<((dniCantPedidos[i])[j])[PED_DNI];
            archSalida<<setw(10)<<((dniCantPedidos[i])[j])[PED_CANT];
            archSalida<<endl;
        }
        imprimirLinea(archSalida,40,'=');
    }
}

                         /* / [ - Pregunta #3 - ] / */

// Modulo de Emision de Reporte de Envios de Pedidos
void reporteDeEnvioDePedidos(const char *nombArch,char ***productos,int *stock,
                             double *precios,int *fechaPedidos,
                             char ***codigoPedidos,int ***dniCantPedidos){
    // Apertura de Archivos && Declaracion de Variables && Inicializacion de Elementos
    ofstream archRep = abrirArchivo_OFS(nombArch);
    int dd,mm,aa;
    double ingresoParcial,perdidaParcial,ingresoTotal = 0,perdidaTotal = 0;
    archRep<<fixed; archRep.precision(2);
    // Proceso de Emision de Reporte [Agrupado por Fechas]
    imprimirEncabezado(archRep,'D',TAMLINEA);
    for(int posFecha = 0;fechaPedidos[posFecha];posFecha++){
        archRep<<setw(10)<<"FECHA:  ";
        descompactarFecha(fechaPedidos[posFecha],dd,mm,aa);
        imprimirFecha(archRep,dd,mm,aa);
        archRep<<endl;
        // Procesamiento de Pedidos
        procesarPedidos(archRep,productos,stock,precios,codigoPedidos[posFecha],
                        dniCantPedidos[posFecha],ingresoParcial,perdidaParcial);
        ingresoTotal += ingresoParcial;
        perdidaTotal += perdidaParcial;
        imprimirLinea(archRep,TAMLINEA,'=');
    }
    // Emision de Resumen Total
    procesarResumenTotal(archRep,ingresoTotal,perdidaTotal);
}
// Modulo de Procesamiento de Pedidos de Fecha
void procesarPedidos(ofstream &archRep,char ***productos,int *stock,
                     double *precios,char **prodIDs,int **buffs,
                     double &ingresoParcial,double &perdidaParcial){
    // Declaracion & Inicializacion de Elementos
    int posProd,numPedido = 0; double monto;
    ingresoParcial = 0; perdidaParcial = 0;
    // Proceso de Impresion y Filtracion de Pedidos por Posicion de Pedido y Producto
    imprimirEncabezado(archRep,'E',TAMLINEA);
    for(int posPed = 0;prodIDs[posPed];posPed++){
        posProd = obtenerPosProd(prodIDs[posPed],productos);
        // Validacion de Existencia de Producto
        if(posProd != XD){
            archRep<<setw(5)<<++numPedido<<')';
            archRep<<setw(10)<<(buffs[posPed])[PED_DNI];
            archRep<<setw(15)<<(productos[posProd])[PROD_COD]<<setw(2)<<' ';
            archRep<<left<<setw(MAXTEXTO)<<(productos[posProd])[PROD_NOMB];
            archRep<<right<<setw(6)<<(buffs[posPed])[PED_CANT];
            archRep<<setw(14)<<precios[posProd];
            // Validacion por Stock Restante && Actualizacion de Stock
            if((buffs[posPed])[PED_CANT] <= stock[posProd]){
                stock[posProd] -= (buffs[posPed])[PED_CANT];
                monto = precios[posProd]*(buffs[posPed])[PED_CANT];
                ingresoParcial += monto;
                archRep<<setw(15)<<monto<<endl;
            }else{
                monto = precios[posProd]*(buffs[posPed])[PED_CANT];
                perdidaParcial += monto;
                archRep<<setw(16)<<"SIN STOCK"<<endl;
            }
        }
    }
    // Emision de Resumen Parcial
    procesarResumenParcial(archRep,ingresoParcial,perdidaParcial);
}
// Modulo de Emision de Resumen Parcial de Datos [Por Fecha]
void procesarResumenParcial(ofstream &archSalida,double ingreso,double perdida){
    imprimirLinea(archSalida,TAMLINEA,'-');
    archSalida<<setw(18)<<"Total ingresado:"<<setw(TAMLINEA - 26)<<ingreso;
    archSalida<<endl<<setw(35)<<"Total perdido por falta de stock:";
    archSalida<<setw(TAMLINEA - 43)<<perdida<<endl;
}
// Modulo de Emision de Resumen Total de Datos [Por Periodo]
void procesarResumenTotal(ofstream &archSalida,double ingreso,double perdida){
    archSalida<<setw(22)<<"Resumen de ingresos:"<<endl;
    archSalida<<setw(35)<<"Total de ingresos en el perdiodo:";
    archSalida<<setw(TAMLINEA - 43)<<ingreso<<endl;
    archSalida<<setw(35)<<"Total perdido por falta de stock:";
    archSalida<<setw(TAMLINEA - 43)<<perdida<<endl;
    imprimirLinea(archSalida,TAMLINEA,'=');
}

                     /* - / [ Funciones Auxiliares ] / - */

// Modulo de Apertura de Archivos IFSTREAM
ifstream abrirArchivo_IFS(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
    exit(1);
}
// Modulo de Apertura de Archivos OFSTREAM
ofstream abrirArchivo_OFS(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(arch.is_open()) return arch;
    cout<<"ERROR DE APERTURA: Archivo "<<nombArch<<endl;
    exit(1);
}
// Modulo de Lectura de Cadena Exacta
char *obtenerCadenaExacta(ifstream &archEntrada,char delimitador){
    char texto[MAXTEXTO]{},*cadena;
    if(delimitador == ' ') archEntrada>>texto;
    else archEntrada.getline(texto,MAXTEXTO,delimitador);
    if(archEntrada.eof()) return nullptr;
    cadena = new char[strlen(texto) + 1];
    strcpy(cadena,texto);
    return cadena;
}
// Modulo de Compactacion de Dato Temporal [Fecha]
int compactarFecha(int dd,int mm,int aa){
    return dd+100*mm+10000*aa;
}
// Modulo de Descompactacion de Dato Temporal [Fecha]
void descompactarFecha(int fecha,int &dd,int &mm,int &aa){
    aa = fecha/10000;
    mm = (fecha - aa*10000)/100;
    dd = fecha - aa*10000 - mm*100;
}
// Modulo de Impresion de Dato Temporal [Fecha]
void imprimirFecha(ofstream &archSalida,int dd,int mm,int aa){
    archSalida.fill('0');
    archSalida<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa;
    archSalida.fill(' ');
}
// Modulo de Busqueda de 'Fecha' en Arreglo 'int' con Medida
int obtenerPosFecha(int fecha,int *arrFechas,int medida){
    for(int i = 0;i < medida;i++)
        if(arrFechas[i] == fecha) return i;
    return XD;
}
// Modulo de Busqueda de 'ID de Producto' en Arreglo 'char **' con SubCampo de Enumeracion & Delimitador
int obtenerPosProd(char *prodID,char ***productos){
    for(int i = 0;productos[i];i++)
        if(strcmp((productos[i])[PROD_COD],prodID) == 0) return i;
    return XD;
}
// Modulo de Impresion de Encabezados PREDETERMINADOS de Reporte
void imprimirEncabezado(ofstream &archSalida,char seleccion,int dimension){
    if(seleccion == 'A'){
        archSalida<<setw((dimension + 30)/2)<<"REPORTE DE ESTADO DE PRODUCTOS";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'=');
        archSalida<<setw(10)<<"CODIGO";
        archSalida<<setw(5)<<' '<<left<<setw(MAXTEXTO)<<"NOMBRE"<<right;
        archSalida<<setw(8)<<"STOCK";
        archSalida<<setw(14)<<"PRECIO"<<endl;
        imprimirLinea(archSalida,dimension,'-');
    } else if(seleccion == 'B'){
        archSalida<<setw((dimension + 26)/2)<<"REPORTE PEDIDOS REALIZADOS POR ";
        archSalida<<"FECHA"<<endl;
        imprimirLinea(archSalida,dimension,'=');
    }else if(seleccion == 'C'){
        imprimirLinea(archSalida,dimension,'-');
        archSalida<<setw(12)<<"PRODUCTO";
        archSalida<<setw(8)<<"DNI";
        archSalida<<setw(16)<<"CANTIDAD"<<endl;
        imprimirLinea(archSalida,dimension,'-');
    }else if(seleccion == 'D'){
        archSalida<<setw((dimension + 29)/2)<<"REPORTE DE ENTREGA DE PEDIDOS";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'=');
    } else{
        imprimirLinea(archSalida,dimension,'=');
        archSalida<<setw(6)<<"No."<<setw(5)<<"DNI"<<setw(17)<<' ';
        archSalida<<left<<setw(MAXTEXTO - 3)<<"Producto"<<right;
        archSalida<<setw(17)<<"Cantidad"<<setw(11)<<"Precio";
        archSalida<<setw(21)<<"Total de ingresos";
        archSalida<<endl;
        imprimirLinea(archSalida,dimension,'-');
    }
}
// Modulo de Impresion de Simbolos en Linea
void imprimirLinea(ofstream &archSalida,int medida,char simbolo){
    for(int i = 0;i < medida;i++) archSalida.put(simbolo);
    archSalida<<endl;
}
