#Programa para ejecutar intrucciones.

def binario_a_decimal(binario):
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
        dir = memoria.get(str(dir1))
        memoria[str(dir1)] = ac #se guarda en la memoria
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
        dir = memoria.get(str(dir1))
        dir = decimal_a_binario(dir)
        dir = binario_a_decimal(dir)
        ac = ac - dir#se resta el valor de la memoria con el ac
        dir2 = binario_a_decimal(dir2)
        memoria[str(dir2)] = ac#se guarda en la memoria
        return ac
    elif instruccion == 7:
        # 7- Multiplicación: memoria 1 x AC, almacena en AC
        dir1 = binario_a_decimal(dir1)
        dir = memoria.get(str(dir1))
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
# El main es la funcion principal del programa
def main():
    print("Menu para ejecutar intrucciones")
    
    # diccionario de memoria
    memoria = {"700":"00011001110010000000000000","701":"01001001110001010011100100","702":"00101001110010000000000000","703":"00011001110011100000000000","704":"01111001110001000000000000","705":"01101001110010010011100010","1250":"1100101","1251":"101000010010001000","1252":"1100101","1253":"11010111010","1254":"10000001110010000","1255":"11"}
    # variables
    pc = 0
    ac = 0
    intruccion = 0
    dir1 = 0
    dir2 = 0
    numdato = 0
    # recorrer el diccionario
    for clave,valor in memoria.items():
        if clave[0:1] == "7":
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
            print("Memoria:",memoria.get(str(numdato)))
            #imprimir la instruccion
            if intruccion == 6:
                print("Dato:",numdato2)
                print("Memoria:",memoria.get(str(numdato2)))

            
            print("---------------------------------")
            #hacer metodos para guardar la informarcion en archivos.

    crear_diccionario_a_archivo(memoria)
    memoria = leer_archivo_a_diccionario()
    print(memoria)


       


main()