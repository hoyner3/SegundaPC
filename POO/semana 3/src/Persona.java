public class Persona {
    // Atributos el String es un tipo objeto y el int es un tipo primitivo
    // El private es un modificador de acceso que es encapsulamiento
    private String nombre;
    private int edad;
    private boolean mayorEdad;

    // Constructor
    public Persona(String nombre, int edad, boolean mayorEdad) {
        this.nombre = nombre;
        this.edad = edad;
        this.mayorEdad = mayorEdad;
    }

    // Metodo getter y setter
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public boolean isMayorEdad() {
        return mayorEdad;
    }

    public void setMayorEdad(boolean mayorEdad) {
        this.mayorEdad = mayorEdad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    @Override
    public String toString() {
        return "Persona{" +
                "nombre='" + nombre + '\'' +
                ", edad=" + edad +
                ", mayorEdad=" + mayorEdad +
                '}';
    }
}
