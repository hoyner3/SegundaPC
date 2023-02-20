#include <iostream>
using namespace std;
//estructura de un nodo
struct numero{

    int num;
    numero *sig;

    //constructor
    numero(int n){
        num = n;
        sig = NULL;
    }    
}*l1, *l2, *l3;

//metodo insertar al final
numero * insertar(numero *lista, int n){
    //creamos un nuevo nodo es como una lista de nodos
    numero *nuevo = new numero(n);
    //si la lista esta vacia
    if(lista == NULL){
        lista = nuevo;
    }
    //si la lista tiene elementos
    else{
        //creamos un puntero temporal que apunta al primero de la lista
        numero *temp = lista;
        //recorremos la lista hasta que el puntero temporal sea nulo
        while(temp->sig != NULL){
            //el puntero temporal apunta al siguiente nodo
            temp = temp->sig;
        }
        //el puntero temporal apunta al nuevo nodo
        temp->sig = nuevo;
    }
    return lista;
}
void imprimir(numero*lista){
    numero *temp = lista;
    while(temp != NULL){
        cout<<temp->num<<", ";
        temp = temp->sig;
    }
}
void cargarDatos(){
    l1 = insertar(l1, 1);
    l1 = insertar(l1, 2);
    l1 = insertar(l1, 3);
    l1 = insertar(l1, 4);
    l1 = insertar(l1, 5);
    l1 = insertar(l1, 6);
    l1 = insertar(l1, 7);
}
void imprimirRecusivo(numero*lista){

    if (lista == NULL){
        return;

    }
    else{
        imprimirRecusivo(lista->sig);
        cout<<lista->num<<", ";
    }
}
    
int main(){
    cout<<"Lista 1: "<<endl;
    cargarDatos();
    imprimir(l1);
    cout<<"\n\nImprimir recursivo: "<<endl;
    imprimirRecusivo(l1);


    return 0;
}