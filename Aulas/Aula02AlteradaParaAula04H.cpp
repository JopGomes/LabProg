#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char palavra[100];
	char nomeArquivo[100];
	char url[100];
	char txt[]=".txt";
	char info[100];	
	printf("Digite o nome do arquivo: ");
	scanf("%s",nomeArquivo);
	strcpy(url,nomeArquivo);
	strcat(url,txt);  
	
	FILE *arq;
	FILE *ler;   
	arq = fopen(url, "w");
	ler = fopen(url, "r");
	if(arq == NULL){
	     printf("Erro, nao foi possivel abrir o arquivo\n");
	     return -1;
	}
	else{
		printf("Entre com a palavra: ");
		scanf("%s",palavra);		
		fprintf(arq,palavra);
		rewind(arq);
		printf("%d %d\n", sizeof(info), sizeof(info2));
		while( (fgets(info, sizeof(info), ler))!=NULL ) {
   			if(!strcmp(info,palavra)){
				printf("São iguais");
			}
			else{
				printf("São diferentes");
			}	
		}
	}
	fclose(arq);	
	return 0;
}
