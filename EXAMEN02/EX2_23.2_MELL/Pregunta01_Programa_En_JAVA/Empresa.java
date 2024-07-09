import java.util.ArrayList;
import java.util.Scanner;

class Empresa{
	private ArrayList<Omnibus> flota;
	
	//CONSTRUCTOR
	Empresa(){
		flota = new ArrayList<Omnibus>();
	}
	
	//MET SELECTORES 
	
	//OTROS METODOS
	public void leeOmbibuses(Scanner arch){
		//lectura de omnibuses
		Omnibus omnibus;
		
		while(true){
			omnibus = new Omnibus(); // reserva de mem 
			if(omnibus.leeDatos(arch)==false) break;
			flota.add(omnibus);
		}		
	}
	
	public void procesaPasajeros(Scanner arch){
		String tipo;
		Pasajero pasajero;
		
		//lectura de los pasajeros 
		while(arch.hasNext()){ // mientras haya una linea por leer 
			tipo = arch.next();
			if(tipo.compareTo("P")==0) pasajero = new PrimeraClase();
			else pasajero = new claseTurista();
			//lectura polimorfica de pasajero 
			pasajero.leePasajero(arch);
			//procesamiento de ubicacion 
			ubicaPasajeroEnOmnibus(pasajero);
		}
	}
	
	public void ubicaPasajeroEnOmnibus(Pasajero pasajero){
		//recorremos la lista de omnibuses que tenemos 
		// verificamos si se puede insertar al pasajero 
		for(Omnibus omnibus: flota){
			if(omnibus.sePuedeUbicar(pasajero)) break;
		}
	}
	
	
	public void imprimeDatos(){
		//impresion de datos tipo ficha :) 
		System.out.print("              ");
		System.out.println("EMPRESA DE TRANSPORTE TURISTICO");
		imprimeLinea('=',100);
		for(Omnibus omnibus:flota){
			omnibus.imprimeDatos();
			imprimeLinea('=',100);
		}
	}
	
	public void imprimeLinea(char c , int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}