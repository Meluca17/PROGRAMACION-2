import java.util.Scanner;
import java.util.ArrayList;

class Biblioteca{
	
	private ArrayList<Cliente> lclientes;
	private ArrayList<Libro> llibros;
	
	public Biblioteca(){
		lclientes = new ArrayList<Cliente>();
		llibros = new ArrayList<Libro>();
	}
	
	//metodos de procesamiento 
	public void leerDatos(){
		Scanner arch = new Scanner(System.in);
		//lecturas :)
		leerClientes(arch);
		leerLibros(arch);
		leerPedidos(arch);
	}
	
	public void leerClientes(Scanner arch){
		Cliente cli;
		
		while(true){
			cli = new Cliente();
			//lectura de libro
			if(!cli.leerCli(arch)) break;
			//agregacion de libro en la lista 
			lclientes.add(cli);
		}
	}
	
	public void leerLibros(Scanner arch){
		Libro lib;
		
		while(true){
			lib = new Libro();
			//lectura de libro
			if(!lib.leerLib(arch)) break;
			//agregacion de libro en la lista 
			llibros.add(lib);
		}
	}
	
	public void leerPedidos(Scanner arch){
		int numPed,dniLeid,posCli;
		
		while(arch.hasNext()){ //hasta que sea la ult linea 
			numPed = arch.nextInt();
			dniLeid= arch.nextInt();
			
			posCli = buscarCliente(dniLeid);
			if(posCli!=-1){
				//lectura de pedidos
				leeListaPedidos(posCli,arch);
			}else{
				arch.nextLine();
			}
			
		}
	}
	
	public void leeListaPedidos(int posCli,Scanner arch){
		int cantPed,posLib;
		String codLib;
		//al ser punteros -> apuntan al mismo lugar -> los podemos usar para actualizar
		Libro auxLib;
		Cliente auxCli;
		
		//lectura de la lista de libros
		while(!arch.hasNextInt()){
			codLib = arch.next();
			posLib = buscarLibro(codLib);
			if(posLib!=-1){
				//proceso
				auxLib = llibros.get(posLib);
				auxCli = lclientes.get(posCli);
				auxCli.agregaPedido(auxLib);
				auxLib.actualizaStock();
			} // aca no paso a la sgte linea pq me interesa leer el sgte libro 
		}
		cantPed = arch.nextInt();//lee el ult numero
	}
	
	public int buscarLibro(String codLib){
		for(int i=0;i<llibros.size();i++){
			if(codLib.compareTo(llibros.get(i).GetCodigo())==0) return i;
		}
		return -1;
	}
	
	public int buscarCliente(int dniLeid){
		for(int i=0; i<lclientes.size();i++){
			if(dniLeid==lclientes.get(i).GetCodigo()){
				return i;
			}
		}
		return -1;
	}
	
	public void imprimeDatos(){
		for(Cliente cli: lclientes){
			imprimeLinea('=',100);
			cli.imprimeCliente();
		}
	}
	
	public void imprimeLinea(char c, int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}