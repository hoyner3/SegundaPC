import javax.swing.*;
public class BucleForEach {
    public static void main(String[] args) {
        String [] paises = new String[8];

        /*paises[0] = "España";
        paises[1] = "México";
        paises[2] = "Colombia";
        paises[3] = "Perú";
        paises[4] = "Argentina";
        paises[5] = "Venezuela";
        paises[6] = "Ecuador";
        paises[7] = "Chile";*/

        /*for (int i = 0; i < paises.length; i++) {
            System.out.println("País " + (i + 1) + ": " + paises[i]);
        }*/


        //String [] paises = {"España", "México", "Colombia", "Perú", "Argentina", "Venezuela", "Ecuador", "Chile"};

        for (int i = 0; i < paises.length; i++) {
            paises[i] = JOptionPane.showInputDialog("Introduce el país " + (i + 1));
        }
        for (String pais : paises) {
            System.out.println("País: " + pais);
        }


      


    }
    
}
