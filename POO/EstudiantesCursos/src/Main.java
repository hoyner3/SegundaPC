public class Main {
    
    public static void main(String[] args) throws Exception {
        // Crear un curso
        Curso curso1 = new Curso("POO", "Curso de programacion orientada a objetos", 5);
        Curso curso2 = new Curso("BD", "Curso de bases de datos", 5);
        
        // Crear estudiantes

        Estudiante estudiante1 = new Estudiante("Juan", 20, 1, "Ingenieria en sistemas");
        Estudiante estudiante2 = new Estudiante("Maria", 21, 2, "Ingenieria en sistemas");
        Estudiante estudiante3 = new Estudiante("Pedro", 22, 3, "Ingenieria en sistemas");
        Estudiante estudiante4 = new Estudiante("Luis", 23, 4, "Ingenieria en sistemas");
        Estudiante estudiante5 = new Estudiante("Ana", 24, 5, "Ingenieria en sistemas");

        // metodo para agregar estudiantes a un arreglo

        curso1.agregarEstudiante(estudiante1);
        curso1.agregarEstudiante(estudiante2);
        curso1.agregarEstudiante(estudiante3);
        curso1.agregarEstudiante(estudiante4);
        curso1.agregarEstudiante(estudiante5);

        curso2.agregarEstudiante(estudiante1);
        curso2.agregarEstudiante(estudiante2);
        curso2.agregarEstudiante(estudiante3);
        curso2.agregarEstudiante(estudiante4);
        curso2.agregarEstudiante(estudiante5);
        
        
        System.out.println(curso1.toString());
        curso1.imprimirEstudiantes();
        System.out.println("");
        System.out.println(curso2.toString());
        curso2.imprimirEstudiantes();
        // Imprimir los cursos con metodo imprimirCurso
        

        

        
    }
}
