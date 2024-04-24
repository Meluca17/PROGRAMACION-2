#include "Utils.h"
#include "AperturaDeArchivos.h"
#include "funcionesPG.h"
#include "Estructuras.h"
#define NOT_FOUND -1
using namespace std;
enum Cli{DNI,NOMBRE,LIBPEDIDOS,NUMLIB};
enum Lib{CODIGO,TITULO,AUTOR,STOCK,PRECIO};
enum Ped{COD,NOMB,PREC};
 
char *leeCadDelim(ifstream &arch, char delim){
    char *str, aux[100];
    
    arch.getline(aux,100,delim); 
    str = new char[strlen(aux)+1];
    strcpy(str,aux); 
    
    return str; 
}

void *leeRegCli(ifstream &arch){
    void **registro=new void*[4];
    int *dni;
    char *nomb;
    
    dni = new int;
    
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nomb = leeCadDelim(arch,'\n');
    
    registro[DNI]=dni;
    registro[NOMBRE] = nomb;
    registro[LIBPEDIDOS] = nullptr;
    registro[NUMLIB] = 0;
    
    return registro;
}

void cargaClientes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Cientes.csv");
    
    //registro
    void *registro, *buff[200]{};
    //aux
    int numDat=0;
    while(true){
        registro = leeRegCli(arch);
        if(registro ==nullptr) break;
        
        buff[numDat] = registro; 
        numDat++;
    }
    
    void **arr_cli = new void*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        arr_cli[i] = buff[i];
//        void **cli = (void**)arr_cli[i];
//        int *dni_aux = (int *)cli[DNI];
//        cout << *dni_aux<<endl;
    }
    clientes = arr_cli;
}

void *leeRegLib(ifstream &arch){
    void **registro=new void*[5];
    
    char *autor,*nomb,*cod,c;
    int *stock;
    double *precio;
    
    stock = new int;
    precio = new double;
    
    cod = leeCadDelim(arch,',');
    if(arch.eof()) return nullptr;
    nomb=leeCadDelim(arch,',');
    autor=leeCadDelim(arch,',');
    arch>>*stock>>c>>*precio;
    arch.get(); //lee el salto de liena 
    
    registro[CODIGO]=cod;
    registro[TITULO] = nomb;
    registro[AUTOR] = autor;
    registro[STOCK] = stock;
    registro[PRECIO] = precio;
    
    return registro;
}
//enum Lib{CODIGO,TIULO,AUTOR,STOCK,PRECIO};
void cargaLibros(void *&libros){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    
    void *registro,*buff[300]{};
    int numDat=0;
    while(true){
        registro = leeRegLib(arch);
        if(registro==nullptr) break;
        
        buff[numDat]=registro;
        numDat++;
    }
    void **arr_lib = new void*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        arr_lib[i] = buff[i];
//        void **lib = (void**)arr_lib[i];
//        int *stock_aux = (int *)lib[STOCK];
//        cout << *stock_aux<<endl;
    }
    
    libros = arr_lib;
}

void cargaPedidos(void *clientes,void *libros){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos_Mod.txt");
    char *codLeido;
    int dniLeid,posCli,posLib;
    
    int *nPedCliente; //PEDIDOS POR CLIENTE 
    nPedCliente = asignaMemTempEnPedidosxCliente(clientes);
            
    while(true){
        arch>>dniLeid;
        if(arch.eof()) break;
        arch.get();
        codLeido =leeCadDelim(arch,'\n');
        
        posCli = buscarCliente(dniLeid,clientes);
        
        
        if(posCli!=NOT_FOUND){
            posLib = buscarLibro(codLeido,libros);
            if(posLib!=NOT_FOUND){
                agregarPedidoCliente(clientes,posCli,libros,posLib,
                        codLeido,nPedCliente[posCli]);
            }
        }
    }
    
    //ASIGNA MEMORIA EXACTA 
    asignarMemoriaExactaEnPedidos(clientes,nPedCliente);
}
void asignarMemoriaExactaEnPedidos(void *& clientes, int* nPedidos){
    int nClientes = 0, i;
    void **auxPedidos, **auxCliente, **auxNuevo;
    void **auxClientes = (void **)clientes;
    for(nClientes; auxClientes[nClientes]; nClientes++){
        auxCliente = (void**) auxClientes[nClientes];
        if(nPedidos[nClientes] > 0){    
            auxPedidos = (void**) auxCliente[LIBPEDIDOS];
            auxNuevo = new void*[nPedidos[nClientes]+1];
            for(i=0; i<nPedidos[nClientes]; i++)
                auxNuevo[i] = auxPedidos[i];
            auxNuevo[i] = nullptr;
            auxPedidos = auxNuevo;
        } else {
            auxPedidos = nullptr;
        }
        auxCliente[LIBPEDIDOS] = auxPedidos;
        auxClientes[nClientes] = auxCliente;
    }
    clientes = auxClientes;
}

    
//enum Ped{COD,NOMB,PREC};
void agregarPedidoCliente(void *clientes,int posCli,void *libros,int posLib,
                        char *codLeido, int &numPedCli){
    void *registroLib = obtieneRegLib(libros,posLib);
    void **aux_Libro = (void **)registroLib; //ya puedo acceder a los campos del libro
//    char *nomb = (char *)aux_Libro[TITULO];
//    cout << nomb<<endl;
    
    void **registroPedido = new void *[3]; //cod nomb precio
    void **arr_cli = (void **)clientes;
    void **cliente = (void **)arr_cli[posCli]; 
    void **aux_pedidos = (void **)cliente[LIBPEDIDOS]; //accede a los indices de pedidos segun nPed
    
    
    registroPedido[COD] = aux_Libro[CODIGO];
    registroPedido[NOMB] =aux_Libro[NOMB];
    registroPedido[PREC] = aux_Libro[PRECIO];
    
    
    
    //actualizamos los punteros con los nuevos datos 
    aux_pedidos[numPedCli] = registroPedido;
    cliente[LIBPEDIDOS] = aux_pedidos;
    arr_cli[posCli] = cliente;
    numPedCli++;
}

void *obtieneRegLib(void *libros,int posLib){
    void **registro=new void*[5];
    //
    void **arr_lib=(void **)libros;
    void **libBuscado = (void **)arr_lib[posLib]; //para acceder a sus campos
    
    registro[CODIGO]=libBuscado[CODIGO];
    registro[TITULO] = libBuscado[TITULO];
    registro[AUTOR] = libBuscado[AUTOR];
    registro[STOCK] = libBuscado[STOCK];
    registro[PRECIO] = libBuscado[PRECIO];
    
    return registro;
}

int *asignaMemTempEnPedidosxCliente(void *clientes){
    void **arr_cli = (void **)clientes;
    
    int *nPedXCli; //arreglo
    int numPed=0;

    for(numPed; arr_cli[numPed];numPed++){ //por cada cliente reserva buff EN PED
        void **cli = (void**)arr_cli[numPed];
        cli[LIBPEDIDOS] = new void*[50]{};
        
        arr_cli[numPed] = cli;
    }
    
    //actualizo clientes ahora con la lista de pedidos de 50
    clientes = arr_cli;
    
    nPedXCli = new int[numPed+1]{}; //el ult sera null
    return nPedXCli;
}

int buscarLibro(char * codLeido,void *libros){
    void **arr_lib = (void **)libros;
    
    for(int i=0;arr_lib[i];i++){
        void **lib= (void **)arr_lib[i];
        char *cod_aux = (char *)lib[CODIGO];
        if(strcmp(codLeido,cod_aux)==0) return i;
    }
    return NOT_FOUND;
}

int buscarCliente(int dniLeid,void *clientes){
    void **arr_cli = (void **)clientes;
    
    for(int i=0;arr_cli[i];i++){
        void **cli= (void **)arr_cli[i];
        int *dni_aux = (int *)cli[DNI];
        if(*dni_aux ==dniLeid) return i;
    }
    return NOT_FOUND;
}

void imprimeLinea(ofstream& arch, char caracter, int repeticiones){
    for(int i=0; i<repeticiones; i++)
        arch << caracter;
    arch << endl;
}

void imprimereporte(void* clientes){
    ofstream archReporte("InformeFinal.txt", ios::out);
    void** auxClientes = (void**) clientes;
    
    if (not archReporte.is_open()) {
        cout << "No ha podido abrir el archivo de reporte";
        exit(1);
    }
    
    archReporte.precision(2);
    archReporte<<fixed;
    
    for(int i=0; auxClientes[i]; i++){
        imprimeLinea(archReporte, '=', 100);
        archReporte << left << setw(20) << "DNI" << setw(50) << "Nombre" <<
                "Crédito" << endl;
        imprimeCliente(archReporte, auxClientes[i]); //imprime un cliente 
        
    }
}

void imprimeCliente(ofstream& archReporte, void* cliente){
    void** auxCliente, **auxRegistro, **auxPedidos, **auxPedido;
    auxCliente = (void**) cliente; //para acceder a los campos de cliente 
    auxRegistro = (void**) auxCliente;
    archReporte << left << setw(20) << *((int*) auxRegistro[DNI]) << 
            setw(50) << (char*) auxRegistro[NOMBRE] << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << "Pedidos atendidos:" << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << left << setw(10) << "Código" << setw(10) << "Nombre" <<
            "Precio" << endl;
    auxPedidos = (void**) auxRegistro[LIBPEDIDOS];
    if(auxPedidos != nullptr)
        for(int i=0; auxPedidos[i]; i++){
            auxPedido = (void**) auxPedidos[i];
            archReporte << left << setw(10) << ((char*) auxPedido[COD]) <<
                    setw(60) << ((char*) auxPedido[NOMB]) <<
                    *((double*) auxPedido[PREC]) << endl;
        }
    archReporte << endl;
}
