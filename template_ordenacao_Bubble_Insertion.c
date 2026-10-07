#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMANHO 10000

void bubble_sort(int vetor[], int n);
void insertion_sort(int vetor[], int n);
void preencherVetorOrdenado(int vetor[], int n);
void preencherVetorAleatorio(int vetor[], int n);
void copiarVetor(int origem[], int destino[], int n);
	
int main() {
		
    int vetorOrdenado[TAMANHO];
    int vetorAleatorio[TAMANHO];
    int copia[TAMANHO];
    clock_t inicio, fim;
    double tempo;

	preencherVetorOrdenado(vetorOrdenado, TAMANHO);
    preencherVetorAleatorio(vetorAleatorio, TAMANHO);


    copiarVetor(vetorOrdenado, copia, TAMANHO);
    inicio = clock();
    bubble_sort(copia, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
    printf("Bubble Sort | vetor ordenado : %f ms\n", tempo);
    
 
    copiarVetor(vetorAleatorio, copia, TAMANHO);
    inicio = clock();
    bubble_sort(copia, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
    printf("Bubble Sort | vetor aleatorio: %f ms\n", tempo);


    copiarVetor(vetorOrdenado, copia, TAMANHO);
    inicio = clock();
    insertion_sort(copia, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
    printf("Insertion Sort | vetor ordenado : %f ms\n", tempo);
    
 
    copiarVetor(vetorAleatorio, copia, TAMANHO);
    inicio = clock();
    insertion_sort(copia, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
    printf("Insertion Sort | vetor aleatorio: %f ms\n", tempo);

    return 0;
}

void bubble_sort(int vetor[], int n){
	
	int i, j, temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(vetor[j] > vetor[j + 1]){
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(int vetor[], int n){
	
	int i, j, chave;
	
	for(i = 1; i < n; i++){
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] =  vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
	}
}

void preencherVetorOrdenado(int vetor[], int n) {

    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }
}

void preencherVetorAleatorio(int vetor[], int n) {

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10000;
    }
}

void copiarVetor(int origem[], int destino[], int n) {

    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}
