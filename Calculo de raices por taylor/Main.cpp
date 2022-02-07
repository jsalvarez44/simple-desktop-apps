#include "Taylor.h"

int main(){
	Taylor serie;
	int numero;
	double resultado;
	
	cout << "CALCULO DE RAICES CUADRADAS CON LA SERIE DE TAYLOR\n" << endl;
	cout << "Ingrese un numero para calcular su raiz: ";
	cin >> numero;
	
	if(numero <= 0){
		cout << "\nNumero incorrecto!" << endl;
	}
	else{
		resultado = serie.calcularRaizCuadrada(numero);
		
		cout << "\nLa raiz cuadrada de " << numero << " es: " << resultado << endl;
	}
	
	return 0;
}
