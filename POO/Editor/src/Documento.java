public class Documento {

    // Atributos de la clase Documento (privados)
    private Hoja[] hojas;

    // Constructor
    public Documento(Hoja[] hojas) {
        this.hojas = hojas;
    }

    // Getters
    public Hoja[] getHojas() {
        return hojas;
    }

    // Setters
    public void setHojas(Hoja[] hojas) {
        this.hojas = hojas;
    }


    
}
