#include <iostream>
#include<ctime>
#include <cstdlib>
//#include <unistd.h> // para la función sleep()
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
//Declare tres listas simples de enteros.
struct listas{ //Estructura de la lista
    int numero;
    listas *siguiente;
    // Constructor
    listas(int num){
        numero = num;
        siguiente = NULL;    
    }

}*lista1, *lista2, *lista3;
//funcion de numeros aleatorios
int aleatorio(int num){
    
    
    num = 1 + rand() % 100;
    return num;
}
//Realice un único método de inserción al final de la lista, la lista debe recibirla por parámetro para saber en cual desea insertar.
listas* insertarFinal(int num, listas *lista){
    listas *nuevo = new listas(num);
    if (lista == NULL){
        lista = nuevo;
    }else{
        listas *aux = lista;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return lista;
}
//Metodo para insertar el numero aleatorio en la lista
listas *listaAleatoria(listas *lista){
    int num;
    srand(time(0));
    for (int i = 0; i < 15; i++){
        num = aleatorio(num);

        //sleep_for(seconds(1)); // pausar la ejecución por dos segundos
       
        lista = insertarFinal(num, lista);
    }
    return lista;
}
//Imprimir la lista deseada.
void imprimirLista(listas *lista){
    listas *aux = lista;
    while (aux != NULL){
        cout << aux->numero;
        aux = aux->siguiente;
        if (aux != NULL){
            cout << ", ";
        }
    }
    cout << endl;
}
//Realice un método para imprimir los múltiplos de 3 y 5 en el mismo método, debe recibir la lista por parámetro. Haga la llamada al método para cada una de las listas.
void multiplos(listas *lista){
    listas *aux = lista;
    while (aux != NULL){
        if (aux->numero % 3 == 0 && aux->numero % 5 == 0){
            cout << aux->numero << ", ";
        }

        aux = aux->siguiente;
    }
    cout << endl;
}
//Imprimir la lista mayor de las tres.
void listaMayor(listas *lista1, listas *lista2, listas *lista3){
    listas *aux1 = lista1;
    listas *aux2 = lista2;
    listas *aux3 = lista3;
    int cont1 = 0, cont2 = 0, cont3 = 0;
    while (aux1 != NULL){
        cont1= cont1 + aux1->numero;
        aux1 = aux1->siguiente;
    }
    while (aux2 != NULL){
        cont2=cont2 + aux2->numero;
        aux2 = aux2->siguiente;
    }
    while (aux3 != NULL){
        cont3=cont3 + aux3->numero;
        aux3 = aux3->siguiente;
    }
    if (cont1 > cont2 && cont1 > cont3){
        cout << "La lista mayor es la 1" << endl;
    }else if (cont2 > cont1 && cont2 > cont3){
        cout << "La lista mayor es la 2" << endl;
    }else if (cont3 > cont1 && cont3 > cont2){
        cout << "La lista mayor es la 3" << endl;
    }else{
        cout << "Las tres listas tienen el mismo tamano" << endl;
    }
}
//Imprimir que números de dos listas se repiten una sola vez.

void numero_lista_repetido(listas*lista1, listas*lista2){
    listas *aux1 = lista1;
    listas *aux2 = lista2;
    int cont = 0;
    int cont2 = 0; 
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (aux1->numero == aux2->numero){
            cont++;
            }
            
            aux2 = aux2->siguiente;

        }
        if (cont == 1){
            cont2++;
            cout <<"Numero que se repite una vez es: "<< aux1->numero << endl;
        }
        aux1 = aux1->siguiente;
        aux2 = lista2;
        cont = 0;
    }
    if (cont2 == 0){
        cout << "No hay numeros que se repitan una sola vez" << endl;
    }

}
void numero_lista_repetidos2(listas*lista1, listas*lista2){
    listas *aux1 = lista1;
    listas *aux2 = lista2;
    int cont = 0;
    int cont2 = 0; 
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (aux1->numero == aux2->numero){
            cont++;
            }
            
            aux2 = aux2->siguiente;

        }
        if (cont >= 2){
            cont2++;
            cout <<"Numero se repite dos veces es: "<< aux1->numero << endl;
        }
        aux1 = aux1->siguiente;
        aux2 = lista2;
        cont = 0;
    }
    if (cont2 == 0){
        cout << "No hay numeros que se repitan una sola vez" << endl;
    }

}
int main(){
    
    bool bandera = true;
    int opcion;
    int cont = 0;

    while (bandera == true){
        
        cout << "Bienvenido al sistema de listas." << endl;
        cout << "1. Insertar elemento en una lista." << endl;
        cout << "2. Imprimir la lista deseada." << endl;
        cout << "3. Imprimir los multiplos de 3 y 5 de las listas." << endl;
        cout << "4. Imprimer la lista mayor de las tres." << endl;
        cout << "5. Imprimir que numeros de dos lista se repiten una sola vez." << endl;
        cout << "6. Imprimir que numeros de dos lista se repiten una dos vez." << endl;
        cout << "7. Salir del sistema." << endl;
        cout << endl<<endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            //Inicialice las listas con números aleatorios entre 1 y 100.
           
            if (cont == 0){
                cout << "Inicializando listas..." << endl;
                sleep_for(seconds(1));
                
                lista1 = listaAleatoria(lista1);
                sleep_for(seconds(1));
                
                lista2 = listaAleatoria(lista2);
                sleep_for(seconds(1));
                
                lista3 = listaAleatoria(lista3);
                cout <<endl<<endl;
                cont++;
            }
            else{
                cout << "Las listas ya fueron inicializadas." << endl;
                cout <<endl<<endl;
            }
            
            break;
        case 2:
            cout << "Imprimiendo listas..." << endl;
            cout << "Lista 1: ";
            imprimirLista(lista1);
            cout << "Lista 2: ";
            imprimirLista(lista2);
            cout << "Lista 3: ";
            imprimirLista(lista3);
            cout <<endl<<endl;
            break;
        case 3:
            cout << "Imprimiendo multiplos de 3 y 5..." << endl;
            cout << "Multiplos de 3 y 5 de la lista 1: ";
            multiplos(lista1);
            cout << "Multiplos de 3 y 5 de la lista 2: ";
            multiplos(lista2);
            cout << "Multiplos de 3 y 5 de la lista 3: ";
            multiplos(lista3);
            cout <<endl<<endl;  
            break;
        case 4:
            cout << "Imprimiendo lista mayor..." << endl;
            listaMayor(lista1, lista2, lista3);
            cout <<endl<<endl;
            break;
        case 5:
            cout << "Imprimiendo numeros que se repiten una sola vez..." << endl;
            cout << "Numeros que se repiten una sola vez en la lista 1 y 2: "<<endl;
            numero_lista_repetido(lista1, lista2);
            cout << "Numeros que se repiten una sola vez en la lista 1 y 3: "<<endl;
            numero_lista_repetido(lista1, lista3);
            cout << "Numeros que se repiten una sola vez en la lista 2 y 3: "<<endl;
            numero_lista_repetido(lista2, lista3);
            cout <<endl<<endl;
            break;
        case 6:
            cout << "Imprimiendo numeros que se repiten dos veces..." << endl;
            cout << "Numeros que se repiten dos veces en la lista 1 y 2: "<<endl;
            numero_lista_repetidos2(lista1, lista2);
            cout << "Numeros que se repiten dos veces en la lista 1 y 3: "<<endl;
            numero_lista_repetidos2(lista1, lista3);
            cout << "Numeros que se repiten dos veces en la lista 2 y 3: "<<endl;
            numero_lista_repetidos2(lista2, lista3);
            cout <<endl<<endl;

            break;
        case 7:
            bandera = false;
            break;
    
        default:
            break;
        }
    }

    return 0;
}