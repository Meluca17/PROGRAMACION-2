import java.util.Scanner;
import java.util.ArrayList;

class Libreria{
	private ArrayList<Cliente> lcliente;
	private ArrayList<Libro> llibro;

	public Libreria(){
		lcliente = new ArrayList<Cliente>();
		llibro = new ArrayList<Libro>();
	}
		
	public void leerDatos(){
		Scanner arch = new Scanner(System.in);
		
		//lectura de datos
		leeDatosCliente(arch);
		leeDatosLibro(arch);
		lecturaDatosPedidos(arch);
		
	}
	
	public void leeDatosCliente(Scanner arch){
		Cliente cli;
		
		//lectura de datos
		while(true){
			cli = new Cliente();
			if(cli.leeCliente(arch)==false) break;
			//añadir al ArrayList
			lcliente.add(cli);
		}
	}
	
	public void leeDatosLibro(Scanner arch){
		Libro lib;
		
		//lectura de datos
		while(true){
			lib = new Libro();
			if(lib.leeLibro(arch)==false) break;
			//añadir al ArrayList
			llibro.add(lib);
		}
	}
	
	public void lecturaDatosPedidos(Scanner arch){
		int codPed, dniLeid;
		
		
		//lectura de datos
		while(arch.hasNext()){
			codPed = arch.nextInt();
			dniLeid = arch.nextInt();
			leePedidos(dniLeid,arch);
		}
	}
	
	public void leePedidos(int dniLeid,Scanner arch){
		int cantPed;
		String codLib,libro;
		boolean atendido=false;
		
		while(!arch.hasNextInt()){
			codLib = arch.next();
			for(Libro lib:llibro){
				if(codLib.compareTo(lib.GetCodigo())==0){
					//tengo la informacion del libro
					atendido = lib.actualizaLibro();
					System.out.println("Atendido: "+atendido+ "  DNI: "+dniLeid);
					agregaPedidoCliente(dniLeid,atendido,lib);
				}
			}
			
		}
		cantPed = arch.nextInt();
	}
	
	public void agregaPedidoCliente(int dniLeid,boolean atendido,Libro lib){
		
		for(Cliente cli:lcliente){
			if(cli.GetDni()==dniLeid){
				cli.agregaPedido(atendido,lib);
			}
		}
	}
	
	public void imprimeDatos(){
		
		//impresion de los datos :) 
		for(Cliente cli: lcliente){
			imprimeLinea('=',60);
			cli.imprimeCliente();
		}
		
	}
	public void imprimeLinea(char c,int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}
