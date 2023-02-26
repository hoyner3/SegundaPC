package poo;

public class Coche {
    // Atributos o propiedades (variables)
    //el private es encapsulamiento
    private int ruedas;
    private int largo;
    private int ancho;
    private int motor;
    private int peso_plataforma;
    
    private String color;
    private int peso_total;
    private boolean asientos_cuero, climatizador;

    // Constructor
    public Coche(){
        ruedas = 4;
        largo = 2000;
        ancho = 300;
        motor = 1600;
        peso_plataforma = 500;
        
        motor = 1600;
        peso_total = peso_plataforma + motor;
        climatizador = false;

    }

    // Metodo Getter - dime_Largo - devuelve el valor de la variable largo
    public String dime_datos_generales(){//GETTER

        return"La plataforma del vehiculo tiene " + ruedas + " ruedas. Mide " + largo/1000 + " metros con un ancho de " + ancho + " cm y un peso de plataforma de " + peso_plataforma + " kg";
    
    }

    // Metodo Setter - establece_color - El void es que no devuelve nada
    public void establece_color(String color_coche){ //SETTER

        color = color_coche;

    }

    public String dime_color(){//GETTER

        return "El color del coche es " + color;
    
    }
    // Setter

    public void configura_asientos(String asientos_cuero){ //SETTER

        if(asientos_cuero == "si"){
            this.asientos_cuero = true;
        }else{
            this.asientos_cuero = false;
        }
    }
    // Getter
    public String dime_asientos(){//GETTER

        if(asientos_cuero == true){
            return "El coche tiene asientos de cuero";
        }else{
            return "El coche tiene asientos de serie";
        }
    }

    public String dime_datos(){
        return motor + " " + peso_total + " "+ " " + climatizador;
    }


}
