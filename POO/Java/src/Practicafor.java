import java.util.*;
public class Practicafor {
    public static void main(String[] args) {
        List<String> listaNom = new ArrayList<String>();
        String[] nombres = {"Juan", "Pedro", "Maria", "Luisa", "Jose", "Ana", "Luis", "Carlos", "Rosa", "Lorena","Alex"};

        List<Integer> listanumCamisas = new ArrayList<Integer>();
        int[] numCamisas = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};

        for (int i = 0; i < nombres.length; i++) {
            listaNom.add(nombres[i]);
            listanumCamisas.add(numCamisas[i]);

        }
        for (int i = 0; i < listaNom.size(); i++) {
            System.out.println(listaNom.get(i) + " " + listanumCamisas.get(i));
        }


    }
    
}
