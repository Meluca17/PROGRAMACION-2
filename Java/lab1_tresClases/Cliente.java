import java.util.Scanner;
import java.util.ArrayList;

class Cliente{
	private int codigo;
	private String nombre;
	private ArrayList<Solicitud>lsolicitudes;
	private int cantTotalPedida;
	private int cantLibPrestados;
	private int cantLibNoPrestados;
	private double montoTotal;
	
	//constructor
	public Cliente(){
		lsolicitudes = new ArrayList<Solicitud>();
		cantTotalPedida=0;
		cantLibPrestados=0;
		cantLibNoPrestados=0;
		montoTotal=0.0;
	}	
	
	//metodos selectorws
	public int GetCodigo(){
			return codigo;
	}
	
	// otros metodos
	public boolean leerCli(Scanner arch){
		codigo = arch.nextInt();
		if(codigo==0) return false;
		nombre = arch.next();
		return true;
	}
	
	public void agregaPedido(Libro auxLib){
		Solicitud solicitud = new Solicitud();
		
		//hay stock
		if(auxLib.GetStock()>0){
			solicitud.llenaSolicitud(auxLib.GetCodigo(),true,auxLib.GetPrecio());
			cantLibPrestados++;
			montoTotal+=auxLib.GetPrecio();
		}
		else{
			solicitud.llenaSolicitud(auxLib.GetCodigo(),false,auxLib.GetPrecio());
			cantLibNoPrestados++;
		}
		lsolicitudes.add(solicitud);
		cantTotalPedida++;
	}
	// private int codigo;
	// private String nombre;
	// private ArrayList<Solicitud>lsolicitudes;
	// private int cantTotalPedida;
	// private int cantLibPrestados;
	// private int cantLibNoPrestados;
	// private double montoTotal;
	public void imprimeCliente(){
		System.out.println("DNI           :"+codigo);
		System.out.println("NOMBRE        :"+nombre);
		System.out.println("CantPedido: "+cantTotalPedida + " | CantPrestada: "+cantLibPrestados + "| CantNoPrest:"+cantLibNoPrestados);
		if(lsolicitudes.size()>0)imprimePedidos();
		System.out.print("TOTAL A PAGAR : ");
		System.out.printf("%10.2f\n", montoTotal);
	}
	
	public void imprimePedidos(){
		imprimeLinea('-',100);
		System.out.println("  "+"CODIGO"+"  "+"PREC."+ "  ESTADO");
		imprimeLinea('-',100);
		for(Solicitud sol: lsolicitudes){
			sol.imprimeSolicitud();
		}
		imprimeLinea('-',100);
	}
	
	public void imprimeLinea(char c, int n){
		for(int i=0; i<n;i++){
			System.out.print(c);
		}
		System.out.println();
	}
}