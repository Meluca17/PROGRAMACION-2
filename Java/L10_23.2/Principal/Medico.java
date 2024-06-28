import java.util.Scanner; 

class Medico{
	int codigo; 
	private String nombre; 
	private String especialidad; 
	double tarifa; 
	double tiempoTotal; 
	double ingresosTotales; 
	int cantidadDeConsultas; 
	
	public Medico(){
		//inicializa los atributos acumulables 
		tiempoTotal  = 0.0; 
		ingresosTotales = 0.0; 
		cantidadDeConsultas = 0; 
	}
	//METODOS SELECTORES
	public void SetCodigo(int d){
		codigo = d; 
	}
	public int GetCodigo(){
		return codigo; 
	}
	public void SetNombre(String s){
		nombre = s; 
	}
	public String GetNombre(){
		return nombre; 
	}
	public void SetEspecialidad(String s){
		especialidad = s; 
	}
	public String GetEspecialidad(){
		return especialidad; 
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
	public void SetIngresosTotales(double d){
		ingresosTotales = d; 
	}
	public double GetIngresosTotales(){
		return ingresosTotales; 
	}
	//////////////////
	public boolean leerMedico(Scanner arch){
		codigo = arch.nextInt();
		if(codigo==0) return false; 
		nombre = arch.next(); 
		especialidad = arch.next(); 
		tarifa = arch.nextDouble(); 
		return true; 
	}
	
	public void imprimeMedico(){
		double tiempoHora; 
		tiempoHora = tiempoTotal/3600; 
		
		System.out.printf("%10d %-50s %-30s %8.2f %10.2f %5.2f %5d\n",
		codigo,nombre,especialidad,tarifa, tiempoHora, ingresosTotales,cantidadDeConsultas);
	}
	
	//el tiempo está en segundos 
	public void actualizaDatos(double tiempoCons){
		tiempoTotal+=tiempoCons; 
		ingresosTotales+= tarifa*(tiempoCons/3600); 
		cantidadDeConsultas++; 
	}
}