import java.util.Scanner;

class Principal{
	public static void main(String []arg){
		Empresa empresa = new Empresa();
		Scanner arch = new Scanner(System.in);
		//apertura del archivo aca ya q los pasientes se asignan ni bien se leen
		
		empresa.leeOmbibuses(arch);
		empresa.procesaPasajeros(arch);
		empresa.imprimeDatos();
	}
	
	
}