package poo;
public class Coche {
    // Atributos o propiedades (variables)
    //el private es encapsulamiento
    private int ruedas;
    private int largo;
    private int ancho;
    private int motor;
    private int peso_plataforma;
    
    String color;
    int peso_total;
    boolean asientos_cuero, climatizador;

    // Constructor
    public Coche(){
        ruedas = 4;
        largo = 2000;
        ancho = 300;
        motor = 1600;
        peso_plataforma = 500;

    }

    // Metodo Getter - dime_Largo - devuelve el valor de la variable largo
    public String dime_largo(){//GETTER

        return"El largo del coche es " + largo;
    
    }

    // Metodo Setter - establece_color - El void es que no devuelve nada
    public void establece_color(){ //SETTER

        color = "Azul";

    }

    public String dime_color(){//GETTER

        return "El color del coche es " + color;
    
    }

}
