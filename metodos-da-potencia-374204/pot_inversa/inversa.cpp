#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define tamanho 3

double* LU(double A[tamanho][tamanho], double B[tamanho]) {
    
    int i, j, k;
    
    double L[tamanho][tamanho] = {0.0};
    double U[tamanho][tamanho] = {0.0};
    double Y[tamanho] = {0.0};
    static double X[tamanho] = {0.0};
    
    for (j = 0; j < tamanho; j++) {
    
        for (i = 0; i < tamanho; i++) {
        
            if (i <= j) {
            
                U[i][j] = A[i][j];
                
                for (k = 0; k <= i - 1; k++) {
                    U[i][j] -= L[i][k] * U[k][j];
                }
                
                if (i == j) {
                    L[i][j] = 1;
                } else {
                    L[i][j] = 0;
                }
                
            } else {
            
                L[i][j] = A[i][j];
                
                for (k = 0; k <= j - 1; k++) {
                    L[i][j]-=L[i][k]*U[k][j];
                }
                
                L[i][j] /= U[j][j];
                U[i][j] = 0;
                
            }
            
        }
        
    }
    
    for (i = 0; i < tamanho; i++) {
    
        Y[i] = B[i];
        
        for(j = 0; j < i; j++) {
            Y[i] -= L[i][j] * Y[j];
        }
        
    }
    
    for (i = tamanho - 1; i >= 0; i--) {
    
        X[i] = Y[i];
        
        for (j = i + 1; j < tamanho; j++) {
            X[i] -= U[i][j] * X[j];
        }
        
        X[i] /= U[i][i];
        
    }
    
    return X;

}

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
	
	double maiorValorAbs = fabs(vetor[0]);
	
	int i;
	for (i = 1; i < tamanho; i++) {
	
		if (fabs(vetor[i]) > maiorValorAbs) {
			maiorValorAbs = fabs(vetor[i]);
		}
		
	}
	
	for (i = 0; i < tamanho; i++) {
		vetor_resultante[i] = vetor[i] / maiorValorAbs;
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
		
		}
	
	}
    
    double autovalor = vetor_resultante[0] / vetor[0];

    return autovalor;

}

int main() {
	
	double* vetor;
	double* auto_vetor_atual;
	double* auto_vetor_antigo;
	double matriz[tamanho][tamanho];
	double autovalor_atual;
	double autovalor_antigo;
	double erro = 0.00001;


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




	auto_vetor_atual = LU(matriz, vetor);
	
	autovalor_atual = calcular_auto_valor(matriz, auto_vetor_atual);
	
	auto_vetor_atual = normalizar(auto_vetor_atual);
	
	do {
	
	    auto_vetor_antigo = auto_vetor_atual;
	    autovalor_antigo = autovalor_atual;
	    
	    auto_vetor_atual = LU(matriz, auto_vetor_antigo);
	    
	    autovalor_atual = calcular_auto_valor(matriz, auto_vetor_atual);
	    
	    auto_vetor_atual = normalizar(auto_vetor_atual);
	
	} while (fabs(autovalor_antigo - autovalor_atual) > erro );
	
	printf("\nO menor autovalor é: %.2f\n", autovalor_atual);
	
	printf("\nE o seu autovetor associado é: ");
	
	int i;
	for (i = 0; i < tamanho; i++) {
	    printf("%.2f ", auto_vetor_atual[i]);
	}
	
	printf("\n");
	
	return 0;

}
