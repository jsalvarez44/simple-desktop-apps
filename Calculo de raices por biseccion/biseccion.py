import math

def f(x):
    return x**3 + 3*x - 6
error = 0.00001 
cont = 0

a = float(input("Ingrese valor de a: "))
b = float(input("Ingrese valor de b: "))
c = (a+b)/2
if f(a) * f(b) < 0:
    while abs(f(c)) > error:
        cont += 1
        c = (a+b)/2
        if f(a) * f(c) < 0:
            b=c
        else:
            a=c
    print("La raiz es: ",c)
    print("Se encontro en ",cont," iteraciones")
else:
    print("Raices no validas")