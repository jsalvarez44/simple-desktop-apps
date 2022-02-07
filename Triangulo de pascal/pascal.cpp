#include <stdio.h>

int factorial(int);
void mostrarPascal(int);

int main(){
    int filas;

	printf("TRIANGULO DE PASCAL\n");
    printf("Ingrese el numero de filas: ");
    scanf("%d",&filas);

	printf("\nTriangulo de pascal de %d filas\n\n", filas);
    mostrarPascal(filas);

    return 0;
}

int factorial(int n){
    int c;
    long result = 1;

    for (c = 1; c <= n; c++){
        result = result*c;
    }
    

    return result;
}

void mostrarPascal(int filas){
	int i, c;
	
	for (i = 0; i < filas; i++){    
        for (c = 0; c <= (filas - i - 2); c++){
            printf(" ");
        }
        

        for (c = 0 ; c <= i; c++){
            printf("%d ", factorial(i) / (factorial(c) * factorial(i-c)));
        }

        printf("\n");
	}
}






