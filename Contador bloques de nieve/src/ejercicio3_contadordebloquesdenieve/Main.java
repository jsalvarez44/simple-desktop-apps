package ejercicio3_contadordebloquesdenieve;

import java.util.Scanner;

/**
 *
 * @author WINDOWS-Sebastian
 */
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese los numeros separados por comas (,): ");
        
        String ingreso = sc.nextLine();
        String[] vectorString = ingreso.split(",");
        int[] vector = new int[vectorString.length];
        
        for(int i=0 ; i<vectorString.length; i++)
            vector[i] = Integer.parseInt(vectorString[i]);
        
        int matriz[][]= new int[numeroMayor(vector)][vector.length];
        
        pintarParedes(matriz, vector);
        pintarEspaciosVacios(matriz);
        imprimirMatriz(matriz);
        
        System.out.println("\nLa cantidad de bloques de hielo son: " + contarBloquesDeHielo(matriz));
    }
    
    public static int numeroMayor(int[] vector){
        int mayor = 0;
        
        for(int numero : vector)
            if(numero > mayor)
                mayor = numero;
        
        return mayor;
    }
    
    public static void encerarMatriz(int matriz[][]){
        for(int i=0; i<matriz.length; i++){
            for(int j=0; j<matriz[i].length; j++){
                matriz[i][j] = 0;
            }
        }
    }
    
    public static void imprimirMatriz(int matriz[][]){
        for(int i=0; i<matriz.length; i++){
            for(int j=0; j<matriz[i].length; j++){
                System.out.print(matriz[i][j] + "\t");
            }
            System.out.println("");
        }
    }
    
    public static void pintarParedes(int matriz[][], int[] vector){
        for(int i=0; i<matriz[0].length; i++){
            for(int j=0; j<vector[i]; j++){
                matriz[j][i] = 1;
            }
        }
    }
    
    public static void pintarEspaciosVacios(int matriz[][]){
        int aux = 0;
        int status = 0;
        
        for(int i=0; i<matriz.length; i++){
            status = 0;
            for(int j=0; j<matriz[0].length; j++){
                
                if(matriz[i][j] == 1 && status == 0){
                    aux = j;
                    status = 1;
                }
                if(matriz[i][j] == 1 && status == 1){
                    for(int k=aux+1; k<j; k++){
                        if(matriz[i][k] != 1)
                            matriz[i][k] = 2;
                    }
                }
            }
        }
    }
    
    public static int contarBloquesDeHielo(int matriz[][]){
        int contador = 0;
        
        for(int i=0; i<matriz.length; i++){
            for(int j=0; j<matriz[i].length; j++){
               if(matriz[i][j] == 2)
                   contador++;
            }
        }
        
        return contador;
    }
}