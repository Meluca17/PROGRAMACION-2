import java.util.Scanner;

//clase abstracta no se instancia - sirve de "plantilla"
abstract class Pasajero{
	private int dni;
	private String nombre;
	private String destino;
	
	//NO CONSTRUCTOR -> no permite instancias 
	
	//METODOS SELECTORES
	public String GetDestino(){
		return destino;
	}
	
	//OTROS METODOS 
	public void leePasajero(Scanner arch){
		dni = arch.nextInt();
		nombre = arch.next();
		destino = arch.next();
	}
	
	public abstract String getTipo(); //virtual void metodo()=0;
	
	public void imprimePasajero(){
		System.out.println("DNI: "+dni + "  Nombre: "+nombre+ "  Destino: "+
		destino);
	}
	
	
}