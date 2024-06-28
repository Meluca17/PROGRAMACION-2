import java.util.Scanner;
import java.util.ArrayList;

class Cliente{
	private int dni;
	private String nombre;
	private ArrayList<String> librosPrestados;
	private ArrayList<String> librosNoPrestados;
	double totalAPagar;
	int cantPrestada;
	int cantNoPrestada;
	
	//constructor
	public Cliente(){
		librosPrestados = new ArrayList<String>();
		librosNoPrestados = new ArrayList<String>();
		totalAPagar = 0.0;
		cantPrestada=0;
		cantNoPrestada=0;
	}
	
	//metodos selectores
	public int GetDni(){
		return dni;
	}
	
	// Otros metodos
	public boolean leeCliente(Scanner arch){
		dni =arch.nextInt();
		if(dni==0) return false;
		nombre = arch.next();
		return true;
	}
	
	public void agregaPedido(boolean atendido,Libro lib){
		if(atendido==true){
			librosPrestados.add(lib.GetCodigo());
			totalAPagar+= lib.GetPrecio();
			cantPrestada++;
		}
		else{
			librosNoPrestados.add(lib.GetCodigo());
			cantNoPrestada++;
		}
	}
	
	public void imprimeCliente(){
		System.out.println("DNI                : "+dni);
		System.out.println("NOMBRE             : "+nombre);
		imprimeLinea('-',60);
		System.out.println("Cantidad Prestada  : " + cantPrestada);
		imprimePedidos(librosPrestados);
		imprimeLinea('-',60);
		System.out.println("Cantidad NoPrestada: " + cantNoPrestada);
		imprimePedidos(librosNoPrestados);
		imprimeLinea('-',60);
		System.out.println("TOTAL A PAGAR   : "+totalAPagar);
		
	}
	
	public void imprimePedidos(ArrayList<String>lista){
		for(int i=0; i<lista.size();i++){
			System.out.print(" "+lista.get(i));
		}
		System.out.println();
	}
	
	public void imprimeLinea(char c,int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}