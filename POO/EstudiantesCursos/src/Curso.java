public class Curso {
    private String nombreCurso;
    private String descripcion;
    private int cantidadEstudiantes;
    private Estudiante[] estudiantes;

    // Constructor
    public Curso(String nombreCurso, String descripcion, int cantidadEstudiantes){
        this.nombreCurso = nombreCurso;
        this.descripcion = descripcion;
        this.cantidadEstudiantes = cantidadEstudiantes;
        // Crear un arreglo de estudiantes con la cantidad de estudiantes que se le pasa al constructor
        this.estudiantes = new Estudiante[cantidadEstudiantes];
    }

    // Metodos gettters y setters
    public String getNombreCurso(){
        return this.nombreCurso;
    }
    
    public void setNombreCurso(String nombreCurso){
        this.nombreCurso = nombreCurso;
    }
    
    public String getDescripcion(){
        return this.descripcion;
    }

    public void setDescripcion(String descripcion){
        this.descripcion = descripcion;
    }

    public int getCantidadEstudiantes(){
        return this.cantidadEstudiantes;
    }

    public void setCantidadEstudiantes(int cantidadEstudiantes){
        this.cantidadEstudiantes = cantidadEstudiantes;
    }

    // Metodo para agregar estudiantes a un arreglo
    public Estudiante[] getEstudiantes(){
        return this.estudiantes;
    }

    // Setter
    public void agregarEstudiante(Estudiante p){//Metodo para agregar estudiantes al arreglo es como el metodo setEstudiantes pero solo agrega un estudiante
        for (int i = 0; i < cantidadEstudiantes; i++) {
            if (this.estudiantes[i] == null) {
                this.estudiantes[i] = p;
                break;
            }
        }
    }
    
    //Metodo para imprimir los cursos y estudiantes

    public void imprimirCurso(){
        System.out.println("Nombre del curso: " + this.nombreCurso);
        System.out.println("Descripcion: " + this.descripcion);
        System.out.println("Cantidad de estudiantes: " + this.cantidadEstudiantes);
        System.out.println("Estudiantes: ");
        for (int i = 0; i < this.estudiantes.length; i++) {
            System.out.println(this.estudiantes[i].getNombre());
        }
    }
    


    // .toString() -- gettter para imprimir los cursos
    @Override
    public String toString(){
        return "\nNombre del curso: " + this.nombreCurso + "\nSemestre:"  + "\nCapacidad del curso: " + this.cantidadEstudiantes + "\nEstudiantes: ";

    }
    
    public void imprimirEstudiantes(){
        for (int i = 0; i < estudiantes.length; i++) {
            System.out.print("\nNombre: " + estudiantes[i].getNombre() + "\nEdad: "+ estudiantes[i].getEdad() + "\nCarrera: "+ estudiantes[i].getCarrera());
        }
    }

    // Metodo Getter para imprimir los estudiantes

}   
