public class Main {
    private int edad = 15;
    
    public void run(){
         // p1 es un objeto de la clase Persona pero es una direccion de memoria
        Persona p1 = new Persona("Juan",20,true);
        Persona p2 = new Persona("Pedro",18,false);
        // Declarando un arreglo de personas
        Persona[] personas; 
        personas = new Persona[5]; // Creando el arreglo de personas con 5 espacios
        
        // Agregando personas a la lista
        personas[0] = new Persona("Marcos", edad, false);
        personas[1] = new Persona("Maria", 25, true);

        // Imprimiendo el arreglo de personas
        for(Persona per: personas){
            if (per != null){
                System.out.println(per.toString());
            }
           // System.out.println(personas.toString());
        }

        System.out.println(p1.toString());
        //System.out.println("Nombre: "+p2.getNombre()+" Edad: "+p2.getEdad()+" Mayor de edad: "+p2.isMayorEdad());


    }
    public static void main(String[] args) throws Exception {
        // Creando un objeto de la clase Main
        (new Main()).run();
        


    }
}
