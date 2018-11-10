#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define tamanho 3

double* mut_Matriz_Vetor(double matriz[tamanho][tamanho], double vetor[tamanho]) {

	static double vetor_resultante[tamanho];
	
	int i, j;
	
	for (i = 0; i < tamanho; i++) {
		
		vetor_resultante[i] = 0;
		
		for (j = 0; j < tamanho; j++) {
		
			vetor_resultante[i] += matriz[i][j] * vetor[j];
		
		}
	
	}
	
	return vetor_resultante;

}

double* normalizar(double vetor[tamanho]) {

	static double vetor_resultante[tamanho];
	
	double max_valor_abs = fabs(vetor[0]);
	
	int i;
	for (i = 1; i < tamanho; i++) {
	
		if (fabs(vetor[i]) > max_valor_abs) {
			max_valor_abs = fabs(vetor[i]);
		}
		
	}
	
	for (i = 0; i < tamanho; i++) {
		vetor_resultante[i] = vetor[i] / max_valor_abs;
	}
	
	return vetor_resultante;

}

double* vetor_chute_inicial() {

	static double vetor_chute_inicial[tamanho];
	double elemento;
	
	//srand(time(NULL));
	
	int i;
	for (i = 0; i < tamanho; i++) {
		//vetor_chute_inicial[i] = (double) rand() / (double) RAND_MAX;
		printf("Entre com o valor [%d] do chute inicial: \n", i);
		scanf("%lf",&elemento);
		vetor_chute_inicial[i] = elemento;

	}
	
	return vetor_chute_inicial;

}

double calcular_auto_valor(double matriz[tamanho][tamanho], double vetor[tamanho]) {

    double vetor_resultante[tamanho];
    
    int i, j;
	
	for (i = 0; i < tamanho; i++) {
		
		vetor_resultante[i] = 0;
		
		for (j = 0; j < tamanho; j++) {
		
			vetor_resultante[i] += matriz[i][j] * vetor[j];
			printf("\nO vetor_resultante: %lf\n", vetor_resultante[i]);
		
		}
	
	}
    
	printf("\nO autovalor1: %lf\n", vetor_resultante[0]);

    double autovalor = vetor_resultante[0] / vetor[0];

	printf("\nO autovalor2: %lf\n", autovalor);

    return autovalor;

}

int main() {
	
	double* vetor;
	double* auto_vetor_atual;
	double* auto_vetor_antigo;
	double matriz[tamanho][tamanho];
	double autovalor_atual;
	double autovalor_antigo;
	double erro = 0.0001;


	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
		    printf("Entre o valor [%d][%d] da matriz \n",i,j);

		    double elemento;

		    scanf ("%lf", &elemento);

		    matriz[i][j] = elemento;
		}
	}


	printf("\nA matriz entrada é: \n");

	for (int i = 0; i < tamanho; i++){
		for (int j = 0; j < tamanho; j++){
				printf("%lf  ",matriz[i][j]);
			}
			printf("\n");	
	}

	
	vetor = vetor_chute_inicial();
	vetor = normalizar(vetor);	

	
	auto_vetor_atual = mut_Matriz_Vetor(matriz, vetor);
	
	autovalor_atual = calcular_auto_valor(matriz, auto_vetor_atual);
	
	auto_vetor_atual = normalizar(auto_vetor_atual);
	
	do {
	
	    auto_vetor_antigo = auto_vetor_atual;
	    autovalor_antigo = autovalor_atual;
	    
	    auto_vetor_atual = mut_Matriz_Vetor(matriz, auto_vetor_antigo);
	    
	    autovalor_atual = calcular_auto_valor(matriz, auto_vetor_atual);
	    
	    auto_vetor_atual = normalizar(auto_vetor_atual);
	
	} while (fabs(autovalor_antigo - autovalor_atual) > erro );
	
	printf("\nO autovalor dominante é : %lf\n", autovalor_atual);
	
	printf("\nE o seu autovetor associado é : ");
	
	int i;
	for (i = 0; i < tamanho; i++) {
	    printf("%.5f ", auto_vetor_atual[i]);
	}
	
	printf("\n");
	
	return 0;

}
