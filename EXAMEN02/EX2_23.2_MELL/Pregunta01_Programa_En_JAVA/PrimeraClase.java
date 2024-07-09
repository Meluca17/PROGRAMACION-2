import java.util.Scanner;
import java.util.ArrayList;

class PrimeraClase extends Pasajero{
	private ArrayList<String> articulosSolicitados;
	
	//constructor
	PrimeraClase(){
		articulosSolicitados = new ArrayList<String>();
	}
	//otros metodos
	@Override
	public void leePasajero(Scanner arch){
		//1. llamamos a la lectura del padre
		super.leePasajero(arch);
		//2. lectura del hijo
		int cantArt;
		String art;
		cantArt = arch.nextInt();
		//lectura de los articulosSolicitados
		for(int i=0;i<cantArt;i++){
			art = arch.next();
			articulosSolicitados.add(art);
		}
	}
	
	@Override
	public String getTipo(){
		return "T";
	}
	
	@Override
	public void imprimePasajero(){
		super.imprimePasajero();
		// es para imprimir las comillas los \ \ 
		System.out.print("       \"PRIMERA CLASE\" EXTRAS: ");
		//impresion de articulosSolicitados
		for(String art: articulosSolicitados){
			System.out.print(art + "  ");
		}
		System.out.println();
	}
	
	
}