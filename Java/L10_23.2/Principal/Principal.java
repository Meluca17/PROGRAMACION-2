import java.util.Scanner; 
import java.util.ArrayList; 

class Principal{
	public static void main(String[]arg){
		//1. Definir el obj de lista de pacientes / medicos 
		ClinicaLP1 clinica = new ClinicaLP1(); 
		
		//2. metodos de la lista de pacientes / medicos 
		//LECTURA 
		clinica.leerDatos(); 
		
		//REPORTES 
		clinica.mostrarDatos(); 
	}
}
