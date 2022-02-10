#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXMascotas 10
#define MAXPersonas 10

void borrarArchivos(){
	remove("archivos/mascotas.txt");
	remove("archivos/personas.txt");
	remove("archivos/veterinarios.txt");
}

class Mascota {
	public:
	int codigo;
	char nombre[20];
	int edad;
	char raza[20];
	
	void leerMascota(){
		printf("Codigo: "); scanf("%d",&this->codigo); fflush(stdin);
		printf("Nombre: "); gets(this->nombre);
		printf("Edad:   "); scanf("%d",&this->edad); fflush(stdin);
		printf("Raza:   "); gets(this->raza);
	}
	
	void mostrarMascota(){
		printf("\tCodigo: %d\n", this->codigo);
		printf("\tNombre: %s\n", this->nombre);
		printf("\tEdad:   %d\n", this->edad);
		printf("\tRaza:   %s\n", this->raza);
	}
};

class Persona {
	public:
	char cedula[10];
	char nombre[20];
	int edad;
	int numeroTelefono;
	char correoElectronico[40];
	int numeroMascotas;
	Mascota mascotas[MAXMascotas];
	
	void leerPersona(){
		printf("Cedula: "); gets(this->cedula);
		printf("Nombre: "); gets(this->nombre);
		printf("Edad:   "); scanf("%d",&this->edad); fflush(stdin);
		printf("Numero de telefono: "); scanf("%d",&this->numeroTelefono); fflush(stdin);
		printf("Correo electronico: "); gets(this->correoElectronico);
		printf("Numero de mascotas: "); scanf("%d",&this->numeroMascotas); fflush(stdin);
	}
	
	void mostrarPersona(){
		printf("Cedula: %s\n", this->cedula);
		printf("Nombre: %s\n", this->nombre);
		printf("Edad:   %d\n", this->edad);
		printf("Numero de telefono: %d\n", this->numeroTelefono);
		printf("Correo electronico: %s\n", this->correoElectronico);
		printf("Numero de mascotas: %d\n", this->numeroMascotas);
		
		for(int i=0; i<this->numeroMascotas; i++){
			printf("MASCOTA N[%d]: \n",(i+1));
			this->mascotas[i].mostrarMascota();
			printf("\n");
		}
	}
};

class Veterinario {
	public:
	char nombre[20];
	int edad;
	int codigoVeterinario;
	
	void leerVeterinario(){
		printf("Nombre: "); gets(this->nombre);
		printf("Edad:   "); scanf("%d",&this->edad); fflush(stdin);
		printf("Codigo: "); scanf("%d",&this->codigoVeterinario); fflush(stdin);
	}
	
	void mostrarVeterinario(){
		printf("Codigo: %d\n", this->codigoVeterinario);
		printf("Nombre: %s\n", this->nombre);
		printf("Edad:   %d\n", this->edad); 
	}
};

void guardarMascota(Mascota m){
	FILE* archivo;
	archivo = fopen("archivos/mascotas.txt", "a");
	fprintf(archivo, "Codigo: %d \nNombre: %s \nEdad: %d \nRaza: %s\n\n", m.codigo, m.nombre, m.edad, m.raza);
	
	fclose(archivo);
}

void guardarPersona(Persona p){
	FILE* archivo;
	archivo = fopen("archivos/personas.txt", "a");
	fprintf(archivo, "Cedula: %s \nNombre: %s \nEdad: %d \nNumero de telefono: %d \nCorreo electronico: %s \nNumero de mascotas: %d\n", p.cedula, p.nombre, p.edad, p.numeroTelefono, p.correoElectronico, p.numeroMascotas);
	
	for(int i=0; i<p.numeroMascotas; i++){
		fprintf(archivo, "Codigo de mascota [%d]: %d \n",(i+1), p.mascotas[i].codigo);
	}
	fprintf(archivo, "\n\n");
	
	fclose(archivo);
}

void guardarVeterinario(Veterinario v){
	FILE *archivo;
	archivo = fopen("archivos/veterinarios.txt", "a");
	fprintf(archivo, "Codigo: %d \nNombre: %s \nEdad: %d\n\n", v.codigoVeterinario, v.nombre, v.edad);
	
	fclose(archivo);
}

void imprimirClinica(Veterinario v, Persona *personas, int numPersonas){
	printf("INFORMACION DE LA CLINICA: \n");
	printf("Veterinario: \n");
	v.mostrarVeterinario();
	
	printf("\n");
	printf("Listado de %d personas: \n", numPersonas);
	for(int i=0; i<numPersonas; i++){
		printf("PERSONA N[%d]: \n", (i+1));
		personas[i].mostrarPersona();
		printf("\n");
	}
}

void menu(){
	printf("+------------------------------------------+\n");
	printf("|               MENU PRINCIPAL             |\n");
	printf("+------------------------------------------+\n");
	printf("| 1. Ingresar clinica                      |\n");
	printf("| 2. Listar informacion de la clinica      |\n");
	printf("| 3. Buscar mascota                        |\n");
	printf("| 0. Salir                                 |\n");
	printf("+------------------------------------------+\n");
}

int main(){
	Veterinario veterinario;
	Persona personas[MAXPersonas];
	
	int opc, num = 0;
	char nombreBuscar[20];
	
	while(true){
		system("cls");
		menu();
		printf("Ingrese su opcion: "); scanf("%d",&opc); fflush(stdin);
		
		switch(opc){
			case 1: // ingresar clinica
				system("cls");
				borrarArchivos();
				
				printf("Ingreso del veterinario: \n");
				veterinario.leerVeterinario();
				guardarVeterinario(veterinario);
				printf("\nDatos guardados correctamente en archivos/veterinarios.txt\n");
				
				printf("\n");
				printf("Ingrese el numero de personas de la clinica: "); scanf("%d",&num); fflush(stdin);
				printf("\n");
				printf("Ingreso de las %d personas: \n", num);
				
				for(int i=0; i<num; i++){
					printf("\n");
					printf("PERSONA N[%d]: \n", (i+1));
					personas[i].leerPersona();
					
					printf("\n");
					printf("Ingreso de %d mascotas: \n", personas[i].numeroMascotas);
					for(int j=0; j<personas[i].numeroMascotas; j++){
						printf("\n");
						printf("MASCOTA N[%d]: \n",(j+1));
						personas[i].mascotas[j].leerMascota();
						guardarMascota(personas[i].mascotas[j]);
						printf("\nDatos guardados correctamente en archivos/mascotas.txt\n");
					}
					
					guardarPersona(personas[i]);
					printf("\nDatos guardados correctamente en archivos/personas.txt\n");
				}
				
				break;
			case 2: // listar datos
				if(num > 0){
					system("cls");
					imprimirClinica(veterinario, personas, num);
				} else {
					printf("\nDebe ingresar la clinica primero!\n");
				}
				
				break;
			case 3: // buscar mascota
				if(num > 0){
					system("cls");
					bool encontrado = false;
				
					printf("Ingrese el nombre de la mascota a buscar: "); gets(nombreBuscar);
					
					for(int i=0; i<num; i++){
						for(int j=0; j<personas[i].numeroMascotas; j++){
							if(strcmp(personas[i].mascotas[j].nombre, nombreBuscar) == 0){
								printf("\nSe ha encontrado la mascota %s: \n", nombreBuscar);
								personas[i].mascotas[j].mostrarMascota();
								printf("El numero de caracteres del nombre de la mascota es: %d\n", strlen(nombreBuscar));
								encontrado = true;
							}
						}
					}
					
					if(!encontrado) printf("\nNo se ha encontrado a la mascota %s\n", nombreBuscar);
					
				} else {
					printf("\nDebe ingresar la clinica primero!\n");
				}
			
				break;
			case 0: // salir
				printf("\nSaliendo del programa...\n");
				exit(0);
				
				break;
			default:
				printf("\nIngrese una opcion correcta!\n");
				
				break;
		}
		system("pause");
	}
		
	return 0;
}








