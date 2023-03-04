public class Grupo extends ObjetoRep {

    private ObjetoRep objeto1;//esto hace que el grupo sea un objeto representable
    private ObjetoRep objeto2;
    // Constructor


    public Grupo(ObjetoRep objeto1, ObjetoRep objeto2) {

        this.objeto1 = objeto1;
        this.objeto2 = objeto2;
    }

    // Getters
    public ObjetoRep getObjeto() {
        return objeto1;

    }

    public ObjetoRep getObjeto2() {
        return objeto2;
    }

    // Setters
    public void setObjeto(ObjetoRep objeto1, ObjetoRep objeto2) {
        this.objeto1 = objeto1;
        this.objeto2 = objeto2;
    }
    
}
