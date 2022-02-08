#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 1000

struct Tren{
	int PassengerId;
	int Survived;
	int Pclass;
	char Name[100];
	char Sex[20];
	int Age;
	int SibSp;
	int Parch;
	char Ticket[20];
	float Fare;
	char Cabin[20];
	char Embarked[20];
};

void leerCSV(char* nombreArchivo, Tren* temp){
	FILE* archivo;
	
	archivo = fopen(nombreArchivo, "r");
	
	if(archivo == NULL){
		printf("Error al abrir el archivo!\n");
		exit(1);
	}
	
	int bandera = 0, i = 0;
	char *tok;
	char linea[200];
	
	while(fscanf(archivo, "%s\n", linea) != EOF){
		if(bandera != 0){ 
			tok = strtok(linea, ",");
			temp[i].PassengerId = atoi(tok);
			tok = strtok(NULL, ",");
			temp[i].Survived = atoi(tok);
			tok = strtok(NULL, ",");
			temp[i].Pclass = atoi(tok);
			tok = strtok(NULL, ",");
			strcpy(temp[i].Name, tok);
			tok = strtok(NULL, ",");
			strcpy(temp[i].Sex, tok);
			tok = strtok(NULL, ",");
			temp[i].Age = atoi(tok);
			tok = strtok(NULL, ",");
			temp[i].SibSp = atoi(tok);
			tok = strtok(NULL, ",");
			temp[i].Parch = atoi(tok);
			tok = strtok(NULL, ",");
			strcpy(temp[i].Ticket, tok);
			tok = strtok(NULL, ",");
			temp[i].Fare = atof(tok);
			tok = strtok(NULL, ",");
			strcpy(temp[i].Cabin, tok);
			tok = strtok(NULL, ",");
			strcpy(temp[i].Embarked, tok);
			
			i++;			
		}
		
		bandera++;
	}

	fclose(archivo);
}

void imprimirDatos(Tren *temp, int numFilas){
	for(int i=0; i<numFilas; i++){
		printf("%d %d %d %s %s %d %d %d %s %.3f %s %s\n", 
							 temp[i].PassengerId, 
							 temp[i].Survived,
							 temp[i].Pclass,
							 temp[i].Name,
							 temp[i].Sex,
							 temp[i].Age,
							 temp[i].SibSp,
							 temp[i].Parch,
							 temp[i].Ticket,
							 temp[i].Fare,
							 temp[i].Cabin,
							 temp[i].Embarked);
	}
}

int obtenerNumeroFilas(char* nombreArchivo){
	FILE* archivo;
	
	archivo = fopen(nombreArchivo, "r");
	
	if(archivo == NULL){
		printf("Error al abrir el archivo!\n");
		exit(1);
	}
	
	int bandera = 0, i = 0;
	char *tok;
	char linea[200];
	
	while(fscanf(archivo, "%s\n", linea) != EOF){
		if(bandera != 0){ 			
			i++;			
		}
		
		bandera++;
	}

	fclose(archivo);
	return i;
}

void imprimirNumeroFilasColumnas(int numeroFilas){
	printf("Numero de filas:    %d\n", numeroFilas);
	printf("Numero de columnas: 12\n\n");
}

void imprimirEncabezados(char* nombreArchivo){
	FILE* archivo;
	
	archivo = fopen(nombreArchivo, "r");
	
	if(archivo == NULL){
		printf("Error al abrir el archivo!\n");
		exit(1);
	}
	
	char *tok;
	char linea[200];
	
	fscanf(archivo, "%s\n", linea);
	
	tok = strtok(linea, ",");
	printf("%s ",tok);
	for(int i=0; i<11; i++){
		tok = strtok(NULL, ",");
		printf("%s ",tok);
	}
	printf("\n");

	fclose(archivo);
}

int main(){
	Tren datos[NMAX];
	int numeroFilas;
	
	leerCSV("train.csv", datos);
	numeroFilas = obtenerNumeroFilas("train.csv");
	imprimirNumeroFilasColumnas(numeroFilas);
	imprimirEncabezados("train.csv");
	imprimirDatos(datos, numeroFilas);
	
	return 0;
}








