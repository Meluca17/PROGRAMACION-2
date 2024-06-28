import java.util.Scanner; 
import java.util.ArrayList; 
import java.util.Comparator; //para ordenar 

class ClinicaLP1{
	//                clasetipo  nombre 
	private ArrayList<Medico>medicos; 
	private ArrayList<Paciente>pacientes; 
	
	public ClinicaLP1(){
		pacientes = new ArrayList <Paciente>(); 
		medicos = new ArrayList<Medico>(); 
	}
	
	
	//metodo para leer los medicos 
	public void leerDatosMedico(Scanner arch){
		Medico med; 
		//lectura
		while(true){
			med = new Medico(); 
			if(med.leerMedico(arch)==false) break; 
			//añadimos al ArrayList
			medicos.add(med);
		}
	}
	
	public void leerDatosPaciente(Scanner arch){
		Paciente pac; 
		//lectura
		while(true){
			pac = new Paciente(); 
			if(pac.leePaciente(arch)==false) break; 
			//añadimos al ArrayList
			pacientes.add(pac);
		}
	}
	
	
	//MED: cod nombre espec tarifa
	//PAC: dni nombre distrito 
	public void leerDatos(){
		Scanner arch = new Scanner(System.in); 
		
		leerDatosMedico(arch); 
		leerDatosPaciente(arch); 
		leerDatosConsulta(arch);
	}
	
	public void leerDatosConsulta(Scanner arch){
		int dniLeid, codMed; 
		int horaIni,minIni,segIni, horaFin,minFin,segFin; 
		double tiempoCons; 
		
		//lectura
		while(arch.hasNext()){
			dniLeid = arch.nextInt(); 
			//if(dniLeid==0) break; 
			codMed = arch.nextInt(); 
			horaIni = arch.nextInt(); 
			minIni = arch.nextInt(); 
			segIni = arch.nextInt(); 
			horaFin = arch.nextInt(); 
			minFin= arch.nextInt(); 
			segFin= arch.nextInt(); 
			//calcula el tiempo de la consulta 
			tiempoCons = calculaTiempoConsulta(horaIni,minIni,segIni,
							horaFin,minFin,segFin);
			// acumular lo leido:) 
			registraConsulta(dniLeid,codMed,tiempoCons);
			}
	}
	
	public void registraConsulta(int dniLeid,int codMed,double tiempoCons){
		double tarifMed; 
		
		tarifMed = actualizaConsMed(codMed,tiempoCons);
		//System.out.printf("Tarifa: %.2f\n",tarifMed);
		actualizaConsPac(dniLeid,tiempoCons,tarifMed);
	}
	
	public double actualizaConsMed(int codMed,double tiempoCons){
		double tarif=0; 
		//obtengo tarifa medico 
		for(Medico med: medicos){
			if(med.GetCodigo()==codMed){
				tarif = med.GetTarifa(); 
				//System.out.printf("Tarifa: "+tarifMed); 
				//System.out.printf("\n");
				med.actualizaDatos(tiempoCons);
			}  
		}
		return tarif; 
	}
	
	public void actualizaConsPac(int dniLeid,double tiempoCons, double tarifMed){
		//obtengo tarifa medico 
		for(Paciente pac: pacientes){
			if(pac.GetDni()==dniLeid){
				pac.actualizaDatos(tiempoCons,tarifMed);
			}  
		}
	}
	
	
	
	public double calculaTiempoConsulta(int horaIni,int minIni,int segIni,
							int horaFin,int minFin,int segFin){						
		double tiempo; 
		tiempo = (horaFin*3600 + minFin*60 + segFin) - (horaIni*3600 + minIni*60 + segIni);
		return tiempo; 
	}
	
	
	public void mostrarDatos(){
		System.out.printf("Datos Medicos: \n");
		mostrarDatosMedico(); 
		System.out.printf("Datos Pacientes: \n");
		mostrarDatosPaciente();
		
	}
	
	public void mostrarDatosMedico(){
		// usa el for each()
		//   elemento 	ArrayList
		for(Medico med: medicos){
			med.imprimeMedico(); 
		}
	}
	
	public void mostrarDatosPaciente(){
		// usa el for each()
		//   elemento 	ArrayList
		for(Paciente pac: pacientes){
			pac.imprimePaciente(); 
		}
	}
	
}