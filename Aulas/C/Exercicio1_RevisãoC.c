#include <stdio.h>
#include <stdlib.h>

int calculaMedia(float *vetor, int n){
	int i;
	float soma,media;
	for(i=0; i < n; i++){
		soma += vetor[i];
	}
	media = soma/n;
	printf("A media e: %.3f",media);
	return media;
}

int main(){
	float*vetor;
	int qtdNotas;

	printf("Entre com o numero de notas:");
	scanf("%d", &qtdNotas);
	if(qtdNotas<0){
		printf("Coloque um valor positivo");
		return 1;
	}
	vetor= (float*) malloc(qtdNotas* (sizeof(float)));
	
	if ( vetor == NULL){
	
	printf("Erro: Memoria insuficiente");
	
	return -1;
	
	}
	
	else{
		int i;
		for(i=0 ; i<qtdNotas;i++){
			printf("Nota %d:",i+1);
			scanf("%f", &vetor[i]);
			if(vetor[i]<=0 || vetor[i]>10 ){
				printf("Notas apenas com valores entre 0 e 10");
				return 1;
			}
		}
		calculaMedia(vetor,qtdNotas);

	}
	
	free(vetor);
	return 0;
}

