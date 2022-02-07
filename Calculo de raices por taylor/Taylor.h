#include <iostream>

using namespace std;

class Taylor{
	private:
		int serie, aprox, miniaprox;
		double resultado, menos, suma, valorsuma;
	public:
		//Getters
		int getSerie(){ return serie; }
		int getAprox(){ return aprox; }
		int getMiniaprox(){ return miniaprox; }
		double getResultado(){ return resultado; }
		double getMenos(){ return menos; }
		double getSuma(){ return suma; }
		double getValorsuma(){ return valorsuma; }
		
		//Setters
		void setSerie(int nserie){ serie = nserie; }
		void setAprox(int naprox){ aprox = naprox; }
		void setMiniaprox(int nminiaprox){ miniaprox = nminiaprox; }
		void setResultado(int nresultado){ resultado = nresultado; }
		void setMenos(int nmenos){ menos = nmenos; }
		void setSuma(int nsuma){ suma = nsuma; }
		void setValorsuma(int nvalorsuma){ valorsuma = nvalorsuma; }
		
		//Funciones
		void calcularCifras(int ingreso);
		void calcularValorAbsoluto();
		double calcularRaizCuadrada(int ingreso);
};
