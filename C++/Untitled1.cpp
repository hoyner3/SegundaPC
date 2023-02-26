#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;
//estructura lista de enteros
struct numero{
  int num;
  numero*sig;
  numero(int n){
    num=n;
    sig=NULL;
  }
}*lista1,*lista2,*lista3;//se declaran las 3 lista
//Metodo de insertar al final generico
numero*insertar(numero*lista,int n){
  numero*nn=new numero(n);//nn es la variable nuevo nodo
  if(lista==NULL)
    lista=nn;//si la lista es vacia, llena 1 nodo con primero que resive
  else{
    numero*tempU=lista;//tempU es la variable que apunta al final
    while(tempU->sig!=NULL)//se recorren los nodos hasta llegar a NULL
      tempU=tempU->sig;//hace que avance el ciclo hasta NULL
    tempU->sig=nn;//cambia el NULL por el numero a llenar
  }
  return lista;//se retorna la lista modificada
}

void subMenuInsertar(){//Submenu para elegir la lista a llenar
  int opcion1;//opcion que elige el usuario para el submenu
  do{
    cout<<"Por favor escoja el numero de lista a llenard"<<endl;
    cout<<"1. Lista 1"<<endl;
    cout<<"2. Lista 2"<<endl;
    cout<<"3. Lista 3"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>opcion1;
    switch(opcion1){
      case 1://Crea y manda 15 numeros random para llenar lista 1
        int numRandom1[15];
        //sleep_for(seconds(1));
        srand(time(0));
        for (int i = 0; i < 15; i++)
          numRandom1[i] = rand() % 100 + 1;
        for (int i = 0; i < 15; i++)
          lista1=insertar(lista1,numRandom1[i]);
        break;
      case 2://Crea y manda 15 numeros random para llenar lista 2
        int numRandom2[15];
        sleep_for(seconds(1));
        srand(time(0));
        for (int i = 0; i < 15; i++)
          numRandom2[i] = rand() % 100 + 1;
        for (int i = 0; i < 15; i++)
          lista2=insertar(lista2,numRandom2[i]);
        break;
      case 3://Crea y manda 15 numeros random para llenar lista 3
        int numRandom3[15];
        sleep_for(seconds(1));
        srand(time(0));
        for (int i = 0; i < 15; i++)
          numRandom3[i] = rand() % 100 + 1;
        for (int i = 0; i < 15; i++)
          lista3=insertar(lista3,numRandom3[i]);
        break;
      case 4://Sale de este submenu
        break;
    }
  }while(opcion1!=4);
}
void imprimeListas(numero*lista){
  numero*temp= lista;
  while(temp!= NULL){// este while recorre la lista de inicio hasta el final
    cout<<temp->num<<", ";
    temp = temp->sig;
  }
}
void verMultiplos(numero*lista){
  numero*temp= lista;
  while(temp!= NULL){
    if (temp->num%3==0||temp->num%5==0){
      cout << temp->num<<", ";
    }
    temp = temp->sig;
  }
}
void subMenuVerMultiplos(){
  int opcion3;//opcion que elige el usuario para el submenu
  do{
    cout<<"\nListas Impresas"<<endl;
    cout<<"1. Lista 1"<<endl;
    cout<<"2. Lista 2"<<endl;
    cout<<"3. Lista 3"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>opcion3;
    switch(opcion3){
      case 1:
        verMultiplos(lista1);
        break;
      case 2:
        verMultiplos(lista2);
        break;
      case 3:
        verMultiplos(lista3);
        break;
      case 4:
        break;
    }
  }while(opcion3!=4);
}
int listaSumaMayor(numero* lista) {
  int resultado = 0;
  numero* temp = lista;
  while (temp != NULL) {
    resultado += temp->num;
    temp = temp->sig;
  }
  return resultado;
}
int main(){
  int opcion;
	cout<<"\nBienvenido";
	cout<<"\nPor favor elija la ejecuci�n que desea ejecutar\n";
	cout<<"1. Llenar listas 1 a 1 \n2. Imprimir lista por par�metros \n3. Ver multiplos de 3 y 5 de cada lista \n4. Ver cual lista tiene la mayor sumatoria \n5. Combinaci�n de ejercicio #1 y #3 \n6. Salir \n";
	cin>>opcion;
	cin.ignore();
	if (opcion == 1)
	{
		subMenuInsertar();
    main();
	}
	if (opcion == 2)
	{
    cout<<"\nContenido Lista 1"<<endl;
	  imprimeListas(lista1);
    cout<<"\nContenido Lista 2"<<endl;
    imprimeListas(lista2);
    cout<<"\nContenido Lista 3"<<endl;
    imprimeListas(lista3);
    main();

	}
	if (opcion == 3)
	{
        subMenuVerMultiplos();
        main();
	}
	if (opcion == 4)
	{
    int resultado1=listaSumaMayor(lista1);
    int resultado2=listaSumaMayor(lista2);
    int resultado3=listaSumaMayor(lista3);
    if (resultado1 > resultado2 && resultado1 > resultado3) {
    cout << "La lista 1 tiene la sumatoria mayor: " << resultado1 << endl;
  } else if (resultado2 > resultado1 && resultado2 > resultado3) {
    cout << "La lista 2 tiene la sumatoria mayor: " << resultado2 << endl;
  } else if (resultado3 > resultado1 && resultado3 >resultado2) {
    cout << "La lista 3 tiene la sumatoria mayor: " << resultado3 << endl;
  } else {
    cout << "Las tres listas tienen la misma sumatoria: " << resultado1 << endl;
  }
    main();
	}
	if (opcion == 5)
	{


	}
	if (opcion == 6)
	{
		exit;
	}


	return 0;
}
