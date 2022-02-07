#Funcion para contar el numero de palabras que existe en una frase
#dada un vector de palabras (vector) y la palabra a buscar (ingreso)
def contarPalabras(ingreso, vector):
    contador = 0
    for palabra in vector:
        if(palabra == ingreso): #si la palabra es igual al ingreso se le suma
                                #en uno al contador
            contador+=1
    return contador

#Ingreso de datos
cadena_ingresada = input("A continuacion ingrese la cadena de texto: ")
palabra_buscar =   input("Ingrese la palabra a buscar:               ")

#se cambia la palabra y la frase a minusculas para evitar inconvenientes
#tambien se retira cualquier espacio en la palabra a buscar
palabra_buscar = palabra_buscar.lower()
palabra_buscar = palabra_buscar.replace(" ", "")
cadena_ingresada = cadena_ingresada.lower()

#se crea el vector de palabras utilizando la funcion split
vector_palabras = cadena_ingresada.split(" ")

contador = contarPalabras(palabra_buscar, vector_palabras)
print("\nLa palabra aparece " + str(contador) + " veces en la frase!")



