public class matrices {
    public static void main(String[] args) {
        int [][] matriz = new int[3][3];
        matriz[0][0] = 5;
        matriz[0][1] = 38;
        matriz[0][2] = 15;
        matriz[1][0] = 92;
        matriz[1][1] = 71;
        matriz[1][2] = 3;
        matriz[2][0] = 85;
        matriz[2][1] = 2;
        matriz[2][2] = 49;
        
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
    
}
