import java.util.ArrayList;
import java.util.Scanner;

class Omnibus{
	private String placa;
	private String chofer;
	private ArrayList<String>ruta;  //guarda las ciudades
	private int asientosPC;			// asientos libres 
	private int asientosCT;			// asientos libres
	private ArrayList<Pasajero> pasajeros;
	
	//CONSTRUCTOR 
	Omnibus(){
		ruta = new ArrayList<String>();
		pasajeros = new ArrayList<Pasajero>();
	}
	
	//MET SELECTORES


	// OTROS METODOS
	public boolean leeDatos(Scanner arch){
		String ciudad;
		
		placa = arch.next();
		if(placa.compareTo("FIN")==0) return false;
		chofer = arch.next();
		//lectura de la ruta de ciudades
		while(!arch.hasNextInt()){
			ciudad = arch.next();
			ruta.add(ciudad);
		}
		asientosPC = arch.nextInt();
		asientosCT = arch.nextInt();
		return true;
	}
	
	public boolean sePuedeUbicar(Pasajero pasajero){
		String tipoPasajero, destino;
		tipoPasajero = pasajero.getTipo();
		destino = pasajero.GetDestino();
		
		if(verificaRuta(destino)){
			if(tipoPasajero.compareTo("T")==0){
				if(asientosCT>0){
					//ubicamos al pasajero 
					pasajeros.add(pasajero);
					//restamos el asiento
					asientosCT--;
				}else{
					return false;
				}
			}
			else{ //Primera clase 
				if(asientosPC>0){
					//ubicamos al pasajero 
					pasajeros.add(pasajero);
					//restamos el asiento
					asientosPC--;
				}else{
					return false;
				}
			}
		}
		else{
			return false;
		}
		return true;
	}
	
	public boolean verificaRuta(String destino){
		//recorre 
		for(String ciudad: ruta){
			if(ciudad.compareTo(destino)==0) return true;
		}
		return false;
	}
	
	

	public void imprimeDatos(){
		System.out.println("PLACA:              "+placa);
		System.out.println("CHOFER:             "+chofer);
		System.out.println("ASIENTOS LIBRES PC: "+asientosPC);
		System.out.println("ASIENTOS LIBRES CT: "+asientosCT);
		System.out.println("RUTA: ");
		//impresion de rutas 
		for(String ciudad: ruta) System.out.print("  "+ciudad); //PRINT
		//impresion de la lista de pasajeros 
		System.out.println();
		imprimeLinea('-',100);
		System.out.println("LISTA DE PASAJEROS: ");
		imprimeLinea('-',100);
		for(Pasajero pasaj: pasajeros) 
			pasaj.imprimePasajero();
		
		
	}
	
	public void imprimeLinea(char c , int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
	
	
	
	
	
}