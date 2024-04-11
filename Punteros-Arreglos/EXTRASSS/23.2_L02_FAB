#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define  ANCHO 150
void lecturaDeProductos(const char *nomArch, char***&productos, int*&stock, double*&precios) {
  ifstream arch(nomArch, ios::in);
  if (not arch.is_open()) {
    cout << "Error no se pudo abrir " << nomArch;
    exit(1);
  }
  char **buffProd[200]{};
  int buffStock[200]{};
  double buffPrec[200]{};
  char cod[8], desc[60], c;
  int numDat = 0;
  while (true) {
    arch.getline(cod, 8, ',');
    if (arch.eof())break;
    arch.getline(desc, 60, ',');
    arch >> buffPrec[numDat] >> c >> buffStock[numDat] >> ws;
    buffProd[numDat] = asignaMemoria(cod, desc);
    numDat++;
  }
  numDat++;
  productos = new char**[numDat] {
  };
  stock = new int[numDat] {
  };
  precios = new double[numDat] {
  };
  for (int i = 0; buffProd[i]; i++) {
    productos[i] = buffProd[i];
    stock[i] = buffStock[i];
    precios[i] = buffPrec[i];
  }
}

char*asignaCadenaExacta(const char*cad) {
  int len = strlen(cad);
  char *p = new char[len + 1] {
  };
  strcpy(p, cad);
  return p;
}

char **asignaMemoria(const char*cod, const char*desc) {
  char **p = new char*[2];
  p[0] = asignaCadenaExacta(cod);
  p[1] = asignaCadenaExacta(desc);
  return p;
}

void pruebaDeLecturaDeProductos(const char*nomArch, char***productos, int*stock, double*precios) {
  ofstream arch(nomArch, ios::out);
  if (not arch.is_open()) {
    cout << "Error no se pudo abrir " << nomArch;
    exit(1);
  }
  arch << setprecision(2) << fixed;
  arch << setw(60) << "EMPRESA COMERCIALIZADORA" << endl;
  arch << setw(55) << "Reporte de productos" << endl;
  for (int i = 0; productos[i]; i++) {
    arch << left << setw(10);
    imprimeCodYDesc(arch, productos[i]);
    arch << right << setw(5) << stock[i] << setw(10) << precios[i] << endl;
  }

}

void imprimeCodYDesc(ofstream&arch, char **producto) {
  arch << producto[0] << setw(60) << producto[1];
}

void lecturaDePedidos(const char*nomArch, int*&fechaPedidos, char***&codigoPedidos, int***&dniCantPedidos) {
  ifstream arch(nomArch, ios::in);
  if (not arch.is_open()) {
    cout << "Error no se pudo abrir " << nomArch;
    exit(1);
  }


  int buffFec[200]{}, **buffDniCant[200]{},
  numDat = 0, arrNum[200]{}, d, m, a, fecha;
  int posFec;
  char cod[8], c, **buffCodPed[200]{};
  int dni, cant, pos;
  while (true) {
    arch.getline(cod, 8, ',');
    if (arch.eof())break;
    arch >> dni >> c >> cant >> c >> d >> c >> m >> c >> a >> ws;
    fecha = a * 10000 + m * 100 + d;
    pos = busca(buffFec, fecha);
    if (pos == -1) {
      buffFec[numDat] = fecha;
      buffCodPed[numDat] = new char*[100] {
      };
      buffDniCant[numDat] = new int*[100] {
      };
      pos = numDat;
      numDat++;
    }
    asignaCodigos(buffCodPed[pos], cod, arrNum[pos]);
    asignaDniCant(buffDniCant[pos], dni, cant, arrNum[pos]);
    arrNum[pos]++;
  }
  numDat++;
  fechaPedidos = new int[numDat] {
  };
  codigoPedidos = new char**[numDat] {
  };
  dniCantPedidos = new int**[numDat] {
  };
  for (int i = 0; i < numDat; i++) {
    fechaPedidos[i] = buffFec[i];
    codigoPedidos[i] = buffCodPed[i];
    dniCantPedidos[i] = buffDniCant[i];
  }
  //for (int i = 0; i < numDat-1; i++) {
  //  asignaMemoriaExacta(codigoPedidos[i], dniCantPedidos[i], arrNum[i]);
 // }
}

int busca(int*buffFec, int fecha) {
  for (int i = 0; buffFec[i]; i++) {
    if (buffFec[i] == fecha)
      return i;
  }
  return -1;
}

void asignaCodigos(char**buffCodPed, char*cod, int num) {
  buffCodPed[num] = asignaCadenaExacta(cod);
}

void asignaDniCant(int**buffDniCant, int dni, int cant, int num) {
  buffDniCant[num] = new int[2] {
  };
  asignaDni(buffDniCant[num], dni);
  asignaCant(buffDniCant[num], cant);
}

void asignaDni(int *buffDniCant, int dni) {
  buffDniCant[0] = dni;
}

void asignaCant(int *buffDniCant, int cant) {
  buffDniCant[1] = cant;
}

void asignaMemoriaExacta(char **&codigoPedidos, int**& dniCantPedidos, int num) {
  char **auxC = new char*[num + 1] {
  };
  int **auxI = new int*[num + 1] {
  };
  for (int i = 0; i< num+1; i++) {
    auxC[i] = codigoPedidos[i];
    auxI[i] = dniCantPedidos[i];
  }
  delete codigoPedidos;
  delete dniCantPedidos;
  codigoPedidos = auxC;
  dniCantPedidos = auxI;
}

void pruebaDeLecturaDeProductos(const char*nomArch, int*fechaPedidos, char***codigoPedidos, int***dniCantPedidos) {
  ofstream arch(nomArch, ios::out);
  if (not arch.is_open()) {
    cout << "Error no se pudo abrir " << nomArch;
    exit(1);
  }
  arch << setw(60)<<"EMPRESA COMERCIALIZADORA"<<endl;
  arch << setw(55)<<"reporte de Pedidos"<<endl;
  for (int i = 0; fechaPedidos[i]; i++) {
    arch << fechaPedidos[i] << endl;
    arch << "Pedidos:" << endl;
    imprimePedidos(arch, codigoPedidos[i], dniCantPedidos[i]);
    arch << endl;
  }
}

void imprimePedidos(ofstream &arch, char **codigoPedidos, int**dniCantPedidos) {
  for (int i = 0; codigoPedidos[i]; i++){
    arch << "   " << left << setw(10) << codigoPedidos[i] << setw(10) << dniCantPedidos[i][0] << dniCantPedidos[i][1] << endl;
  }
}
void reporteDeEnvioDePedidos(const char* nomArch,char***productos,int*stock,double*precios,
          int*fechaPedidos,char***codigoPedidos,int***dniCantPedidos){
  ofstream arch(nomArch, ios::out);
  if (not arch.is_open()) {
    cout << "Error no se pudo abrir " << nomArch;
    exit(1);
  }
  int d,m,a,fecha;
  double totalIngresos = 0,totalPerdidoFaltaStock=0;
  arch << setprecision(2)<<fixed;
  for (int i = 0; fechaPedidos[i]; i++) {
    fecha = fechaPedidos[i];
    d = fecha%100;
    fecha /=100;
    m = fecha%100;
    a = fecha/100;
    imprimeLinea(arch,'=');
    arch << "Fecha:  "<< setfill('0')<<setw(2)<< d<<'/'<<setw(2)<<m<<'/'<<a<<setfill(' ')<<endl;
    imprimeLinea(arch,'=');
    imprimeLinea(arch,'-');
    imprimePedidosFormato(arch,codigoPedidos[i],dniCantPedidos[i],productos,precios,stock,totalIngresos,totalPerdidoFaltaStock);
    imprimeLinea(arch,'=');
  }
  arch << "Resumen de ingresos:"<<endl;
  arch << "Total de ingresos en el periodo:" << setw(90)<< totalIngresos<<endl;
  arch << "Total perdido por falta de stock"<<setw(90)<<totalPerdidoFaltaStock<<endl;
  imprimeLinea(arch,'=');
}
void imprimePedidosFormato(ofstream&arch,char **codigoPedidos,int **dniCantPedidos,char***productos,double*precios,int*stock,double&totalIngresos,double&totalPerdidoFaltaStock){
  double tIngresado = 0,tPerdido = 0;
  double precio,tIng;
  int cant;
  int posP;
  for (int i = 0; codigoPedidos[i]; i++) {
    posP = busca(productos,codigoPedidos[i]);
    arch <<right<<setw(2)<< i+1<<")  "<<left << setw(15)<<dniCantPedidos[i][0]<< setw(10)<< codigoPedidos[i] << setw(60)
            << productos[posP][1]<< right<< setw(3)<<dniCantPedidos[i][1]<<right << setw(12)<< precios[posP];
    if(stock[posP] > 0){
      tIng = precios[posP]*dniCantPedidos[i][1];
      stock[posP]--;
      arch << setw(12)<< tIng;
    }else{
      tIng = 0;
      tPerdido+= precios[posP];
      arch << setw(12)<<"SIN STOCK";
    }
    tIngresado += tIng;
    arch << endl;
    
  }
  imprimeLinea(arch,'-');
  arch << "Total ingresado"<< setw(90)<<tIngresado<<endl;
  arch << "Total perdido por falta de stock"<< setw(90)<<tPerdido<<endl;
  totalIngresos += tIngresado;
  totalPerdidoFaltaStock += tPerdido;
}
int busca(char***productos,const char*codigoPedido){
  for (int i = 0; productos[i]; i++) {
    if(strcmp(productos[i][0],codigoPedido)==0)
      return i;
  }
  return -1;
}
void imprimeLinea(ofstream&arch,char c){
  for (int i = 0; i < ANCHO; i++) {
    arch.put(c);
  }
  arch <<endl;
}
