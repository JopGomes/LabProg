#include <stdio.h>

int abrirArquivo(FILE *arq ,char NomeArquivo){;
	arq = fopen(NomeArquivo,"r");
	return arq;
}

int main(){
	char nome[500];
	FILE *arq;
	printf("Digite o nome do arquivo");
	scanf("%c",&nome);
	arq =abrirArquivo(arq,nome);
	return arq;
}
