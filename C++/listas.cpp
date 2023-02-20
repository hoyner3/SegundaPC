#include <iostream>
using namespace std;
//el nombre de la estructura no tiene que ser Nodo especificamente--ademas es global
// el nodo es una estructura que tiene un dato y un puntero que apunta al siguiente nodo de la lista
struct estudiante{
    //atributos de la estructura
    string nombre;
    int carnet;
    int edad;
    //puntero que apunta al siguiente nodo
    estudiante*sig;
    //constructor de la estructura
    estudiante(string n, int id, int e){ 
        //inicializamos los atributos
        nombre = n;
        carnet = id;
        edad = e;
        sig = NULL;

    }

}*primero,*lista1,*lista2;//punteros globales que apuntan al primer nodo de la lista y a los nodos de las listas que se van a unir *primero es el primero de la lista principal y lista1 y lista2 son las listas que se van a unir a la principal.
//metodo para insertar al inicio de la lista principal
estudiante * lista3;
//prototipos de los metodos un protoipo es una declaracion de un metodo
bool buscar(estudiante*,int);
// metodo para insertar al inicio de la lista principal 
void insertar(string n, int id, int e){
    //creamos un nuevo nodo y le mandamos los datos
    estudiante * nuevo = new estudiante(n,id,e);
    //el nuevo nodo apunta al primero de la lista
    nuevo->sig=primero;

    primero=nuevo;


}
//metodo para imprimir la lista
void imprimir1(){
    //creamos un puntero temporal que apunta al primero de la lista
    estudiante*temp=primero;
    //recorremos la lista hasta que el puntero temporal sea nulo
    while(temp != NULL){
        //imprimimos los datos del nodo
        cout<<"\nNombre: "<<temp->nombre<<" ";
        cout<<"\nCarnet: "<<temp->carnet<<" ";
        cout<<"\nEdad: "<<temp->edad<<" ";
        //el puntero temporal apunta al siguiente nodo
        temp = temp->sig;
    }

}
//metodo para imprimir la lista
void imprimir2(estudiante *lista){
    //creamos un puntero temporal que apunta al primero de la lista
    estudiante*temp=lista;
    //recorremos la lista hasta que el puntero temporal sea nulo
    while(temp != NULL){
        //imprimimos los datos del nodo
        cout<<"\nNombre: "<<temp->nombre<<" ";
        cout<<"\nCarnet: "<<temp->carnet<<" ";
        cout<<"\nEdad: "<<temp->edad<<" ";
        //el puntero temporal apunta al siguiente nodo
        temp = temp->sig;
    }

}

//metodo para insertar incio en cualquier lista
estudiante* insertarInicio(estudiante *lista, string n, int id, int e){
    //creamos un nuevo nodo y le mandamos los datos
    estudiante * nuevo = new estudiante(n,id,e);
    //la condicion es para que no se acepten duplicados de carnet
    if (buscar(lista,id)==true)
    {
        cout<<"El carnet ya existe no aceptamos duplicados"<<endl;
        return lista;
    }
    //el nuevo nodo apunta al primero de la lista
    nuevo->sig=lista;

    lista=nuevo;
    return lista;
}
// Metodo buscar un numero de carnet, que devuelva true o false
bool buscar(estudiante*lista,int id)//estudiante*lista es la lista que se va a recorrer y el id es el carnet que se va a buscar
{
    //creamos un puntero temporal que apunta al primero de la lista
    estudiante*temp=lista;
    while(temp!=NULL)//recorremos la lista hasta que el puntero temporal sea nulo
    {
        if(temp->carnet==id)//si el carnet del nodo es igual al carnet que se busca
        {
            cout<<"Se encontro el carnet: "<<temp->nombre;
            return true;//regresa al metodo main true
        }
        temp=temp->sig;//el puntero temporal apunta al siguiente nodo
    }

    cout<<"No se encontro el carnet"<<endl;

    return false;
}
estudiante* borrar(estudiante*lista,int id)
{
    if (lista==NULL)
    {
        cout<<"La lista esta vacia"<<endl;
        return lista;
    }
    else if(lista->carnet==id){
        lista=lista->sig;
    }
    else{
        estudiante*temp=lista;
        estudiante*tempA;
        while(temp!=NULL){
            if(temp->carnet==id){
                tempA->sig=temp->sig;
                break;

            }
            tempA=temp;
            temp=temp->sig;
        
        }
        if (temp==NULL)
        {
            cout<<"No se encontro y no lo borro"<<endl;
        }
    }
    return lista;
}
int main()
{
    cout<< "Lista Simples"<<endl;
    /*primero = new estudiante("juan",202210101,20);//llama al constructor y le mandamos los datos--son para hacer memoria nueva
    cout<<primero->nombre<<endl;
    cout<<primero->carnet<<endl;

    primero->nombre = "jose";

    cout<<primero->nombre<<endl;
    cout<<primero->carnet<<endl;
*/
    //insertar al inicio de la lista
    insertar("Ana",202210101,20);
    insertar("brayan",202210201,23);
    insertar("carlos",202212001,22);
    insertar("denis",202210222,21);

    //insertar al inicio de la lista
    lista3=insertarInicio(lista3,"maria",2022,20);
    lista3=insertarInicio(lista3,"marcela",202223,21);
    lista3=insertarInicio(lista3,"marianela",202322,21);
    primero=insertarInicio(primero,"oscar",20222,21);
    lista2=insertarInicio(lista2,"manuel",20222,21);

    //imprimir la lista
    cout<<"----------------------";
    cout<<"\n\nLista primero"<<endl;
    imprimir1();
    /*cout<<"\n------Lista 3-------";
    cout<<"\n\nLista lista3"<<endl;
    imprimir2(lista3);
    cout<<"\n--------Lista 2--------";
    cout<<"\n\nLista lista2"<<endl;
    imprimir2(lista2);
    cout<<"\n----------------------";

    //buscar un carnet
    cout<<"\n\nBuscar carnet"<<endl;
    buscar(primero,202210101);
    */
   //borrar lista
    cout<<"\n\nBorrar carnet"<<endl;
    primero=borrar(primero,202210101);
    imprimir2(primero);

    cout<<"";
    return 0;
}