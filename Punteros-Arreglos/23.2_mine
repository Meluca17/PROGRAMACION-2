#include "Utils.h"
#include "AsignacionDinamicaMemoriaExacta.h"
using namespace std;
#define MAXLIN 100
#define ANCHO 60
/*
    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
*/

void lecturaDeProductos(const char*filename,char ***&productos,
        int *&stock,double *&precios){
    ifstream archProd(filename,ios::in);
    if(not archProd.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }
    
    char **buffer_productos[200]{};     //clon estatico char*** de productos
    int buffer_stock[200]{},numDat;
    double buffer_precios[200]{};
    char cod[8],desc[60],c; 
    
    numDat =0;
    while(true){
        archProd.getline(cod,8,',');
        if(archProd.eof()) break; 
        archProd.getline(desc,60,',');
        archProd>>buffer_precios[numDat]>>c>>buffer_stock[numDat]>>ws;
        //archProd.get(); //lee el cambio de linea 
        
        buffer_productos[numDat] = asignarMemoria(cod,desc); //ES DEL TIPO CHAR**
        
        numDat++;
    }
    //4. RESERVA DE MEMORIA EXACTA EN ARR_DIN+ (recordar q baja un nivel) 
    productos = new char **[numDat+1]{};
    stock = new int[numDat+1]{};
    precios = new double[numDat+1]{};
    
     //5. COPIA DE DATOS ESTATICOS A ARR_DIN
    for(int i=0; buffer_productos[i];i++){
        //asignamos 
        productos[i] = buffer_productos[i];
        stock[i] = buffer_stock[i];
        precios[i] = buffer_precios[i];
        //comprobamos: cout<<productos[i][1]<<" "<< stock[i]<<" "<<precios[i]<<endl;
    }
}


char ** asignarMemoria(const char *cod,const char *desc){
    char **aux;
    aux = new char*[2]{};
    aux[0] = asignaCadenaExacta(cod);
    aux[1] = asignaCadenaExacta(desc);
    return aux;
}

/*cod(cadena), des(cadena), precio(double) stock(int)*/



void pruebaDeLecturaDeProductos(const char*filename,char ***productos,
        int *stock,double *precios){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }
    arch<<setprecision(2)<<fixed; 
    arch<<setw(60)<<"EMPRESA COMERCIALIZADORA"<<endl;
    arch<<setw(60)<<"Reporte de Productos"<<endl;
    
    for(int i=0;productos[i];i++){
        //arch<<left;
        imprimeCodYDesc(arch,productos[i]);
        arch<<right<<setw(10)<<precios[i]<<setw(10)<<stock[i]<<endl;
    }
}

void imprimeCodYDesc(ofstream &arch,char **producto){
    arch<<left<<setw(10)<<producto[0]<<setw(60)<<producto[1];
}

/*codProd   dni     cant    fechaPed*/
void lecturaDePedidos(const char *filename,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    ifstream archPed(filename,ios::in);
    if(not archPed.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }    
    //variables aux para lectura
    char codProd[8],c; 
    int dni, cant, dia,mes, anho,numDat,fecha,pos; //numDat para ped
    //1.BUFFERS -> son un clon a los originales 
    int buffer_fechas[600]{},arrNumFil[100]{}; 
    int **buff_dnis[600]{}; 
    char **buffer_cods[600]{}; 
    
    numDat = 0; //2.NUM EXACTO DE DATOS
    while(true){
        archPed.getline(codProd,8,',');
        if(archPed.eof()) break; 
        archPed>>dni>>c>>cant>>c>>dia>>c>>mes>>c>>anho;
        archPed.get(); //lee el salto de linea 
        
        fecha = anho*10000+ mes *100 + dia; 
        pos = buscarEnFecha(fecha,buffer_fechas); 
        if(pos==-1){//NO LO ENCUENTRA: primera fecha y nuevas...
            buffer_fechas[numDat] = fecha; 
            buff_dnis[numDat] = new int *[100]{};
            buffer_cods[numDat] = new char *[100]{};
            pos = numDat; 
            numDat++; 

        }
        //3. LLENADO DE BUFF
        
        llenadoBuffDni(buff_dnis[pos],dni,cant,arrNumFil[pos]); 
        llenadoBuffCods(buffer_cods[pos],codProd,arrNumFil[pos]);
        arrNumFil[pos]++; //agrega un pedido a la fila 
        //cout <<buffer_fechas[pos]<<endl; 
    }
    
    //4. RESERVA DE MEMORIA DINAMICA A ORIGINALES
    fechaPedidos = new int [numDat+1]{};
    dniCantPedidos = new int **[numDat+1]{};
    codigoPedidos = new char **[numDat+1]{}; 
    
    
    //5. COPIAR BUFF A DINAMICO 
    for(int i=0; i<buffer_fechas[i]; i++){
        fechaPedidos[i] = buffer_fechas[i];
        dniCantPedidos[i] = buff_dnis[i];
        codigoPedidos[i] = buffer_cods[i];
    }
    //recorte de memoria para cada fila(fecha) ya q ya sabemos exactamente cuantos pedidos hay 
    for(int i=0; codigoPedidos[i]; i++){ //char**
        cut(codigoPedidos[i],dniCantPedidos[i],arrNumFil[i]); 
    }
}

void cut(char **&codigoPedidos,int **&dniCantPedidos,int numXFil){
    //necesito un buff arux con el num exacto por fila 
    char **aux_cod; 
    int **aux_dni; 
    
    if(numXFil!=0){
        aux_cod = new char *[numXFil+1]{}; 
        aux_dni = new int *[numXFil+1]{}; 
        for(int i=0; i<numXFil; i++){
            aux_cod[i] = codigoPedidos[i]; 
            aux_dni[i] = dniCantPedidos[i]; 
        }
        delete codigoPedidos; 
        delete dniCantPedidos;
        codigoPedidos = aux_cod; //iguala punteros 
        dniCantPedidos = aux_dni; //iguala punteros 
    }else{
        delete codigoPedidos; 
        delete dniCantPedidos; 
        codigoPedidos = nullptr; 
        dniCantPedidos = nullptr; 
    }
    
}


void llenadoBuffCods(char **&buffer_cods,char *codProd,int numPorFila){
    
    buffer_cods[numPorFila] = asignaCadenaExacta(codProd); 
}

void llenadoBuffDni(int **&buff_dnis,int dni,int cant, int numPorFila){
    buff_dnis[numPorFila] = new int[2]{}; 
  asignaDni(buff_dnis[numPorFila], dni);
  asignaCant(buff_dnis[numPorFila], cant);
}

void asignaDni(int *buffDniCant, int dni) {
  buffDniCant[0] = dni;
}

void asignaCant(int *buffDniCant, int cant) {
  buffDniCant[1] = cant;
}

//comprobamos: cout<<productos[i][1]<<" "<< stock[i]<<" "<<precios[i]<<endl;
char *asignaCadenaExacta(const char *cad){
    int longitud;
    char *str;
    longitud = strlen(cad);
    str=new char[longitud+1]{};
    
    strcpy(str,cad);
    return str; 
}

int buscarEnFecha(int fecha,int *bufferFechas){
    for(int i=0;bufferFechas[i];i++){
        if(fecha == bufferFechas[i]) return i;
    }
    return -1; 
}
void pruebaDeLecturaDePedidos(const char *filename,int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos){
    ofstream arch(filename,ios::out); 
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }     
    
    arch<<right<<setw(60)<<"REPORTE DE PEDIDOS"<<endl; 
    int i=0; 
//    while(fechaPedidos[i]) i++; 
//    cout <<i; 
    for(int i=0; i<16; i++){
        arch<<left << setw(20)<<fechaPedidos[i]<<endl;
        arch<<"Pedidos por fecha:  "<<endl; 
        imprimePedidos(arch,codigoPedidos[i],dniCantPedidos[i]);
        arch<<endl;
    }
    
}
 
void imprimePedidos(ofstream &arch,char **codigoPedidos,int **dniCantPedidos){
    //por cada fecha hay ciertos pedidos(es variable dependiendo de la fila-> fecha)
    for(int i=0; codigoPedidos[i]; i++){ //char *
        arch<<left<<setw(15)<<codigoPedidos[i]; 
        imprimeDnis(arch,dniCantPedidos[i]); 
        arch<<endl; 
        //arch << "   " << left << setw(10) << codigoPedidos[i] << setw(10) << dniCantPedidos[i][0] << dniCantPedidos[i][1] << endl;
    }
    
}

void imprimeDnis(ofstream &arch,int *dniCantPedidos){
    arch<<left<<setw(15)<<dniCantPedidos[0]<<setw(15)<<dniCantPedidos[1];
}

//OJO: el cut se hace cuando no se cuantos ped tengo para cada fila :) 
//1. buffer estaticos
//2. tamaño real de datos
//3. lectura y llenado de buffers
//4. reservar memoria exacta-> arr_dinamico
//5. Copia de datps estaticos a dinamicos

//PRODUCTOS -> cod , desc -> STOCK, PRECIO (relacionados con 
//FECHA,DNI(DNI,CANT),COD(COD)
void reporteDeEnvioDePedidos(const char*filename,char ***productos,int *stock,
            double *precios,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    int dd,mm,aa; 
     
    ofstream arch(filename,ios::out); 
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }
    
    arch<<setw(ANCHO)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl; 
    arch<<setprecision(2)<<fixed; 
    for(int i=0; fechaPedidos[i];i++){
        imprimeLinea(arch,'='); 
        convierteFecha(dd,mm,aa,fechaPedidos[i]); 
        arch<<left<<"FECHA: "<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm
                <<'/'<<aa<< setfill(' ')<<endl;
        imprimeLinea(arch,'=');
        arch<<left<<setw(5)<<"No."<<setw(15)<<"DNI"<<setw(40)<<"PRODUCTO"<<setw(15)
                <<"Cantidad"<<setw(15)<<"Precio"<<setw(15)<<"Total de ingresos"
                <<endl; 
        imprimeLinea(arch,'-');
        imprimePedidosPorFecha(arch,productos,stock,precios,dniCantPedidos[i],
                codigoPedidos[i]);
    }
}
void imprimePedidosPorFecha(ofstream &arch,char ***productos,int *stock,
        double *precios,int **dniCantPedidos,char **codigoPedidos){
    double totaIngXPed=0,tPerdido=0,totalGeneral=0,totalPerd=0;
    int posP; 
    
    for(int i=0; codigoPedidos[i];i++ ){ //char * 
        posP = busca(codigoPedidos[i],productos); 
        arch<<i+1<<") "<<left<<setw(15)<<dniCantPedidos[i][0]<<setw(15)<<codigoPedidos[i]
                <<setw(60)<<productos[posP][1]<<setw(15)<<dniCantPedidos[i][1]<<
                right <<setw(15)<<precios[posP];
//        totaIngXPed = dniCantPedidos[i][1] *precios[posP]; 
//        arch<<totaIngXPed<<endl; 
        if(stock[posP]>0){
            totaIngXPed = dniCantPedidos[i][1] *precios[posP];
            arch<<setw(10)<<totaIngXPed; 
        }else{
            //no hay stock, se pierde dinero 
            tPerdido +=precios[posP]*dniCantPedidos[i][1];
            arch<<setw(12)<<"SIN STOCK"; 
        }
        imprimeLinea(arch,'-');
        arch<<endl<<totalGeneral<<"   "<<totalPerd<<endl; 
        totalGeneral += totaIngXPed;
        totalPerd += tPerdido;
    }
}

int busca(char *codProd,char ***productos){
    for(int i=0; productos[i];i++){//char **
        if(strcmp(productos[i][0],codProd)==0) return i; //char*
    }
    return -1; 
}


void convierteFecha(int &dd,int &mm,int &aa,int fecha){
    //fecha = aa*1000+mm*100+dd
    dd = fecha%100;  //obtiene los dias (ult dig)
    fecha /= 100;    //elimina los ult dig (el dia)
    mm = fecha % 100;   //obtiene el mes  (los dos sgtes digs
    aa = fecha /100 ;  //obtiene el año 
    
    
    
}
void imprimeLinea(ofstream &arch, char car){
    for(int i=0; i<MAXLIN; i++){
        arch.put(car); 
    }
    arch<<endl; 
}
