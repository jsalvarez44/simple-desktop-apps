#funcion para verificar si una cadena es palindroma
def esPalindromo(cadena):
    #se cambia a minusculas la cadena y se le retira los espacios
    cadena = cadena.lower()
    cadena = cadena.replace(" ", "")

    #se declara la cadena invertida para validar
    volteada = cadena[::-1]

    #se recorre las cadenas verificando que cada letra sea igual, caso
    #contrario se retorna falso
    for i in range(len(cadena)):
        if(cadena[i] != volteada[i]):
            return False
    return True
        
#ingreso de datos
cadena_ingresada = input("A continuacion ingrese la cadena de texto: ")

#impresion de resultados
if(esPalindromo(cadena_ingresada)):
    print("La cadena ingresada es un palindromo!")
else:
    print("La cadena ingresada no es un palindromo!")
