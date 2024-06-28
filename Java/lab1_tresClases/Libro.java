import java.util.Scanner;

class Libro{
	private String codigo;
	private String nombre;
	private String autor;
	private int stock;
	private double precio;
	
	//constructor
	public Libro(){
		
	}	
	
	//metodos selectorws
	public String GetCodigo(){
		return codigo;
	}
	public int GetStock(){
		return stock;
	}
	public double GetPrecio(){
		return precio;
	}
	// otros metodos
	public boolean leerLib(Scanner arch){
		codigo = arch.next();
		if(codigo.compareTo("FIN")==0) return false;
		nombre = arch.next();
		autor = arch.next();
		stock = arch.nextInt();
		precio = arch.nextDouble();
		return true;
	}
	
	public void actualizaStock(){
		if(stock>0){
			stock--;
		}else{
			stock=0;
		}
	}
}