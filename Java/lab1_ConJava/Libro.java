import java.util.Scanner;

class Libro{
	private String codigo;
	private String titulo;
	private String autor;
	private int stock;
	private double precio;
	
	//constructor
	public Libro(){
		
	}
	
	//metodos selectores
	public String GetCodigo(){
		return codigo;
	}
	public double GetPrecio(){
		return precio;
	}
	
	// Otros metodos
	public boolean leeLibro(Scanner arch){
		codigo = arch.next();
		if(codigo.compareTo("FIN")==0) return false;
		titulo = arch.next();
		autor = arch.next();
		stock =arch.nextInt();
		precio =arch.nextDouble();
		return true;
	}
	
	public boolean actualizaLibro(){
		if(stock>0){
			stock--;
			return true;
		}else{
			return false;
		}
	}
}