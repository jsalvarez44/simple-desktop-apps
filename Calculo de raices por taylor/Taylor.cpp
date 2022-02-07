void Taylor::calcularCifras(int ingreso){
	int a = ingreso;
	int digito = 0;
	aprox=1;
	do{
		aprox = aprox * 10;
		digito++;
		a = a / 10;
	}while(!a == 0);
	aprox = aprox / 10;
	int par = digito % 2;
	int cifraraiz;
	switch(par){
		case 0:
			aprox = aprox / 10 * 81;
			cifraraiz = (digito - 2) / 2;
			miniaprox = 9;
			break;
		case 1:
			aprox = aprox * 9;
			cifraraiz = (digito - 1) / 2;
			miniaprox = 3;
			break;
	}
	for(int j=0; j < cifraraiz; j++){
		miniaprox = miniaprox * 10;
	}
}

void Taylor::calcularValorAbsoluto(){
	valorsuma = (suma > 0) ? suma : -suma;
}

double Taylor::calcularRaizCuadrada(int ingreso){
	calcularCifras(ingreso);
	menos = ingreso - aprox;
	resultado = miniaprox;
	suma = menos / (2 * miniaprox);
	serie = 1;
	int paridad;
	calcularValorAbsoluto();
	
	while(valorsuma > 0.000001){
		resultado += suma;
		suma =- suma * menos * (2 * serie - 1) / (2 * (serie + 1) *aprox);
		calcularValorAbsoluto();
		serie++;
	}
	
	return resultado;
}
