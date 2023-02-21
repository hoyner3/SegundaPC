#Programa para ejecutar intrucciones.

def binario_a_decimal(binario):
    #print(type(binario))
    decimal = 0
    for i in range(len(binario)):
        decimal += int(binario[i]) * 2 ** (len(binario) - i - 1)
    return decimal
# funcion para pasar de decimal a binario
def decimal_a_binario(decimal):
    binario = ''
    while decimal > 0:
        binario = str(decimal % 2) + binario
        decimal = decimal // 2
    return binario
def setInstruccion(instruccion,memoria,dir1,dir2,ac):
    dir = 0
    temp = 0
    if instruccion == 1:
        # 1- Carga de memoria 1 hacia AC
        dir1 = binario_a_decimal(dir1)#se pasa de binario a decimal
        dir = memoria.get(str(dir1))#se obtiene el valor de la memoria
        dir = binario_a_decimal(dir)#se pasa de binario a decimal
        ac = dir
        return ac
    elif instruccion == 2:
        #2- Almacenar en memoria 1 desde AC
        dir1 = binario_a_decimal(dir1)
        #dir = memoria.get(str(dir1))
        ac = decimal_a_binario(ac)
        memoria[str(dir1)] = ac #se guarda en la memoria
        ac = binario_a_decimal(ac)
        return ac
    elif instruccion == 3:
        # 3- Suma: memoria 1 + AC
        dir1 = binario_a_decimal(dir1)
        dir = memoria.get(str(dir1))
        dir = binario_a_decimal(dir)
        ac = dir + ac#se suma el valor de la memoria con el ac
        return ac
    elif instruccion == 4:
        # 4- Suma: memoria 1 + memoria 2 + AC
        dir1 = binario_a_decimal(dir1)
        dir2 = binario_a_decimal(dir2)
        dir1 = memoria.get(str(dir1))
        dir2 = memoria.get(str(dir2))
        dir1 = binario_a_decimal(dir1)
        dir2 = binario_a_decimal(dir2)
        ac = dir1 + dir2 + ac#se suma el valor de la memoria con el ac
        return ac
    elif instruccion == 5:
        # 5- Resta: AC – memoria 1, almacena en AC
        dir1 = binario_a_decimal(dir1)
        dir = memoria.get(str(dir1))
        dir = decimal_a_binario(dir)
        ac = ac - dir#se resta el valor de la memoria con el ac
        return ac
    elif instruccion == 6:
        #6- Resta: AC – memoria 1, almacena en memoria 2
        dir1 = binario_a_decimal(dir1)
        dir = memoria.get(str(dir1))# se obtiene el valor de la memoria
        #dir = decimal_a_binario(dir)
        dir = binario_a_decimal(dir)
        temp = ac - dir#se resta el valor de la memoria con el ac
        dir2 = binario_a_decimal(dir2)
        memoria[str(dir2)] = temp#se guarda en la memoria
        return ac
    elif instruccion == 7:
        # 7- Multiplicación: memoria 1 x AC, almacena en AC
        dir1 = binario_a_decimal(dir1)
        dir = memoria.get(str(dir1))# se obtiene el valor de la memoria
        dir = binario_a_decimal(dir)
        ac = ac * dir#se multiplica el valor de la memoria con el ac
        return ac

def crear_diccionario_a_archivo(diccionario):
    archivo = open("archivo.txt","w")
    for clave,valor in diccionario.items():
        archivo.write(clave + " " + str(valor) + "\n")
    archivo.close()

def leer_archivo_a_diccionario():
    archivo = open("archivo.txt","r")
    diccionario = {}
    for linea in archivo:
        clave,valor = linea.split()#separa la linea en dos partes ejemplo: 700 00011001110010000000000000
        diccionario[clave] = valor
    archivo.close()
    return diccionario

#metodo que agrege direcciones a memoria
def agregar_direcciones_a_memoria(memoria):
    print("1. Agregar direcciones a memoria")
    print("2. salir")
    opcion = int(input("Ingrese una opcion: "))
    if opcion == 1:
        validacion = False
        while validacion == False:
            direccion = input("Ingrese la direccion con formato debe empezar con d- : ")
            if direccion.startswith("d-"):
                validacion = True
                
            else:
                print("Direccion invalida")

        validacion = False
        while validacion == False:
            print()
            print()
            print("Las unicas intrucciones que se pueden ingresar son: ")
            print("1- Carga de memoria 1 hacia AC: 0001")
            print("2- Almacenar en memoria 1 desde AC: 0010")
            print("3- Suma: memoria 1 + AC: 0011")
            print("4- Suma: memoria 1 + memoria 2 + AC: 0100")
            print("5- Resta: AC – memoria 1, almacena en AC: 0101")
            print("6- Resta: AC – memoria 1, almacena en memoria 2: 0110")
            print("7- Multiplicación: memoria 1 x AC, almacena en AC: 0111")
            dato = input("Ingrese el dato de la memoria con una cantidad de 26bits: ")
            if  (len(dato) == 26 and dato.startswith("0")):
                if (binario_a_decimal(dato[4:15]) >= 1250 and binario_a_decimal(dato[4:15]) <= 1255):
                    validacion = True
                else:
                    print("Direccion invalida")
                    print("Las direcciones de memoria deben estar entre 1250 y 1255")
                
            else:
                print("Dato invalido")
                print("El dato debe tener 26 bits y empezar con 0")
                
        
        memoria[direccion] = dato 
        print("Direccion agregada con exito")
        print("Direccion: ",direccion,"Dato: ",dato)
        
        return memoria
    else:
        print("Saliendo...")
        main()

 

#metodo que ejecuta las intrucciones
def ejecutar_intrucciones(memoria,pc,ac,intruccion,dir1,dir2,numdato):
    # recorrer el diccionario
    for clave,valor in memoria.items():
        if clave[0:1] == "d":
            print("---------------------------------")
            
            print(clave,valor)
            pc = clave
            print("CPU")
            print("pc:",pc)
            #separar la instruccion
            intruccion = valor[0:4]
            #pasar de binario a decimal
            intruccion = binario_a_decimal(intruccion)
            #separar las direcciones
            dir1 = valor[4:15]
            dir2 = valor[15:26]
            #pasar de binario a decimal
            numdato = binario_a_decimal(dir1)
            numdato2 = binario_a_decimal(dir2)
            #seleccionar la instruccion
            ac = setInstruccion(intruccion,memoria,dir1,dir2,ac)

            print("ac:",ac)
            print("instruccion:",intruccion)
            print("dir1:",dir1)
            print("dir2:",dir2)
            print("Dato:",numdato)
            print("Memoria:",memoria.get(str(numdato)))# se obtiene el valor de la memoria
            #imprimir la instruccion
            if intruccion == 6:
                print("Dato:",numdato2)
                print("Memoria:",memoria.get(str(numdato2)))

            
            print("---------------------------------")
    
    return memoria,pc,ac,intruccion,dir1,dir2,numdato
            #hacer metodos para guardar la informarcion en archivos.
# El main es la funcion principal del programa
def main():
    print("Menu para ejecutar intrucciones")
    
    # diccionario de memoria
    #global memoria 
    memoria = {"d-700":"00011001110010000000000000","d-701":"01001001110001010011100100","d-702":"00101001110010000000000000","d-703":"00011001110011100000000000","d-704":"01111001110001000000000000","d-705":"01101001110010010011100010","1250":"1100101","1251":"101000010010001000","1252":"1100101","1253":"11010111010","1254":"10000001110010000","1255":"11"}
    # variables
    pc = 0
    #global ac
    ac = 0
    #global intruccion
    intruccion = 0 
    #global dir1
    dir1 = 0
    #global dir2
    dir2 = 0 
    #global numdato
    numdato = 0
    bandera = True
    while bandera == True:
        print("1. Agregar direcciones a memoria")
        print("2. Ejecutar intrucciones")
        print("3. Imprimir memoria")
        print("4. Salir")
        opcion = int(input("Ingrese una opcion: "))
        if opcion == 1:
            agregar_direcciones_a_memoria(memoria)
        elif opcion == 2:
            #print(type(memoria["d-700"]))
            #print(memoria)
            ejecutar_intrucciones(memoria,pc,ac,intruccion,dir1,dir2,numdato)
        elif opcion == 3:
            crear_diccionario_a_archivo(memoria)
            memoria = leer_archivo_a_diccionario()
            print(memoria)
        elif opcion == 4:
            print("Saliendo...")
            break
        else:
            print("Opcion invalida")
            print("Ingrese una opcion valida")
            
main()