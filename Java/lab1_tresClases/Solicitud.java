class Solicitud{
	private String codLib;
	private boolean atentido;
	private double precio;
	
	public Solicitud(){
		
	}
	//metodos selectores
	
	//otros metodos
	public void llenaSolicitud(String cod, boolean atend, double prec){
		codLib=cod;
		atentido=atend;
		precio=prec;
	}
	
	public void imprimeSolicitud(){
		if(atentido==true){
			System.out.println("  "+codLib+"  "+precio+ "  ATENDIDO");
		}else{
			System.out.println("  "+codLib+"  "+precio+ "  NO-ATENDIDO");
		}
	}
}