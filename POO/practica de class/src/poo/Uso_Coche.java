package poo;

public class Uso_Coche {
    public static void main(String[] args) {
        // este es el objeto
        Coche micoche = new Coche();

        micoche.establece_color();

        System.out.println(micoche.dime_color());
    }
    
}
