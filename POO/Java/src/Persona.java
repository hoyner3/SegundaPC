public class Persona {
    // Atributos
    private String nombre;
    private int edad;

    // Constructor
    public Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    // Métodos
    public void saludar() {
        System.out.println("Hola, mi nombre es " + this.nombre);
    }

    public void contarEdad() {
        System.out.println("Tengo " + this.edad + " años");
    }
}



