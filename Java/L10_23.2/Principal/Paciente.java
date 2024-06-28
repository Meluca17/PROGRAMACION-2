import java.util.Scanner;

class Paciente{
	//RECORDAD-> colocar private  o public 
	private int dni; 
	private String nombre; 
	private String distrito; 
	private double tarifa; 
	private double tiempoTotal; 
	private double gastosTotales; //
	private int cantidadDeConsultas; 
	
	//METODOS CONSTRUCTORES 
	public Paciente(){
		//inicializa los atributos acumulables 
		tiempoTotal  = 0.0; 
		gastosTotales = 0.0; 
		cantidadDeConsultas = 0; 
	}
	
	//METODOS SELECTORES
	public void SetDni(int d){
		dni = d; 
	}
	public int GetDni(){
		return dni; 
	}
	public void SetNombre(String s){
		nombre = s; 
	}
	public String GetNombre(){
		return nombre; 
	}
	public void SetDistrito(String s){
		distrito = s; 
	}
	public String GetDistrito(){
		return distrito; 
	}
	public void SetCantidadDeConsultas(int d){
		cantidadDeConsultas = d; 
	}
	public int GetCantidadDeConsultas(){
		return cantidadDeConsultas; 
	}
	public void SetTarifa(double d){
		tarifa = d; 
	}
	public double GetTarifa(){
		return tarifa; 
	}
	public void SetTiempoTotal(double d){
		tiempoTotal = d; 
	}
	public double GetTiempoTotal(){
		return tarifa; 
	}
	public void SetGastosTotales(double d){
		gastosTotales = d; 
	}
	public double GetGastosTotales(){
		return gastosTotales; 
	}
	
	
    //METODOS EXTRAS
	
	public void actualizaDatos(double tiempoCons,double tarifMed){
		tiempoTotal+= tiempoCons; 
		gastosTotales += tarifMed*(tiempoCons/3600); 
		cantidadDeConsultas++; 
	}
	
	public boolean leePaciente(Scanner arch){
		dni = arch.nextInt(); 
		if(dni == 0 ) return false; 
		nombre = arch.next();  
		distrito = arch.next(); 
		return true; 
	}
	
	public void imprimePaciente(){
		double tiempoHora; 
		tiempoHora = tiempoTotal/3600; 
		
		System.out.printf("%10d %-50s %-30s %15.2f %10.2f %5d\n",
		dni,nombre,distrito, tiempoHora, gastosTotales, cantidadDeConsultas);
	}
}