public class Estudiante {
    // Atributos
    private String nombre;
    private int edad;
    private int añoActual;
    private String carrera;

    // Constructor
    public Estudiante(String nombre, int edad, int añoActual, String carrera){
        this.nombre = nombre;
        this.edad = edad;
        this.añoActual = añoActual;
        this.carrera = carrera;
    }

    // Metodos gettters y setters
    public String getNombre(){
        return this.nombre;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public int getEdad(){
        return this.edad;
    }

    public void setEdad(int edad){
        this.edad = edad;
    }

    public int getAñoActual(){
        return this.añoActual;
    }

    public void setAñoActual(int añoActual){
        this.añoActual = añoActual;
    }

    public String getCarrera(){
        return this.carrera;
    }

    public void setCarrera(String carrera){
        this.carrera = carrera;
    }

    


    

}
