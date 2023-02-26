package poo;
import java.util.Scanner;
public class Uso_Coche {
    public static void main(String[] args) {
        // este es el objeto
        Coche micoche = new Coche();

        //este es el metodo setter que modifica el valor de la variable
        micoche.establece_color("Rojo");



        //este es el metodo getter que devuelve el valor de la variable
        System.out.println(micoche.dime_datos_generales());
        
        System.out.println(micoche.dime_color());
    
        System.out.println("El asiento es de cuero 1. Si 2. No");
        //este objeto es para leer el teclado
        Scanner entrada = new Scanner(System.in);
        int asiento = entrada.nextInt();//lee el teclado y lo 

        if(asiento == 1){
            micoche.configura_asientos("si");
        }else{
            micoche.configura_asientos("no");
        }

        System.out.println(micoche.dime_asientos());
        
    }
    
}
