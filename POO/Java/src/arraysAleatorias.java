public class arraysAleatorias {

    public static void main(String[] args) {
        
        int [] numeros = new int[150];
        
        for (int i = 0; i < numeros.length; i++) {
            numeros[i] = (int) Math.round(Math.random() * 100);
        }
        
        for (int numero : numeros) {
            System.out.print(numero + " ");
        }
    }
    
}
