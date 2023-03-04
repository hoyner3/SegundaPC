//los imports
import java.util.ArrayList;

public class Hoja {
    private ArrayList<ObjetoRep> objetos;

    //Constructor
    public Hoja() {
        this.objetos = new ArrayList<ObjetoRep>();
    }

    
    // Constructor
    public Hoja(ArrayList<ObjetoRep> objetos) {
        this.objetos = objetos;
    }

    // Getters
    public ArrayList<ObjetoRep> getObjetos() {
        return objetos;
    }

    // Setters
    public void setObjetos(ArrayList<ObjetoRep> objetos) {
        this.objetos = objetos;
    }
}
