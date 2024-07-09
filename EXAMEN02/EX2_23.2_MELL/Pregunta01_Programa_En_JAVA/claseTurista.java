import java.util.Scanner;

class claseTurista extends Pasajero{
	private boolean valija;
	private boolean almuerzo;
	private double tarifaExtra;
	
	//constructor
	claseTurista(){
		tarifaExtra=0.0;
	}
	
	//METODOS SELECTORES
	
	
	//OTROS METODOS 
	@Override
	public void leePasajero(Scanner arch){
		//1. llamamos a la lectura del padre
		super.leePasajero(arch);
		//2. lectura del hijo
		String llevaValija,llevaAlmuerzo;
		
		llevaValija = arch.next();
		llevaAlmuerzo = arch.next();
		
		if(llevaValija.compareTo("S")==0) valija= true;
		else valija = false;
		if(llevaAlmuerzo.compareTo("S")==0) almuerzo= true;
		else almuerzo = false;
		
		//actualiza la tarifa extra
		if(valija) tarifaExtra+= 85.5;
		if(almuerzo) tarifaExtra+= 55.90;
	}
	
	@Override
	public String getTipo(){
		return "T";
	}
	@Override
	public void imprimePasajero(){
		super.imprimePasajero();
		// es para imprimir las comillas los \ \ 
		System.out.print("         \"CLASE TURISTA\" EXTRAS: ");
		if(valija) System.out.print("  Valija");
		if(almuerzo) System.out.print("  Almuerzo");
		System.out.println("  - Tarifa Extra: "+ tarifaExtra);
	}
}


// (vehic)PLACA NOMB [LISTA DE CIUDADES] CANTASIENTOS
// (pasaj)TIPO DNI NOMB CIUDADDEST