#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lerArquivo() 
{
	// Pegar o nome do arquivo
	  char nomeArquivo[100];
	  char url[100];
	  char txt[]=".txt";

	  char *info;	
	  float somaFem=0,somaMasc=0,contMasc=0,contFem=0,mediaMasc,mediaFem; // Perguntar o pq disso
	  
	  printf("Digite o nome do arquivo: ");
	  scanf("%s",nomeArquivo);
	  strcpy(url,nomeArquivo);
	  strcat(url,txt);
	  char ch;

	// Abrir o arquivo
	 FILE *arq;
	          
	 arq = fopen(url, "r");
	 if(arq == NULL)
	     printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
	// Definir logica do programa

  		while( (fgets(info, sizeof(info), arq))!=NULL ){
  			char texto[10];
   			printf("%s", info);
   			strcpy(texto,info);
   			char ch = texto[0];
   			char ch3= texto[3];
   			if(ch=='M'){
   				char c = texto[2];
   				float f=(float)(c - '0');
   				//Resolver Bug do 10
//   			if(c=='1' && ch3=='0'){
//   					f+=9.0;
//					
//				}
   				somaMasc+=f;
   				contMasc++;
			}
			if(ch== 'F'){
				char c = texto[2];
   				float f=(float)(c - '0');
   				//Resolver Bug do 10
//   			if(c=='1' && ch3=='0'){
//   					f+=9.0;
//				}
   				somaFem+=f;
   				contFem++;
			}
		}
		mediaFem=somaFem/contFem;
		mediaMasc=somaMasc/contMasc;
		if(mediaMasc>mediaFem){
			printf("\nM %f",mediaMasc);
		}
		if(mediaFem>mediaMasc){
			printf("\nF %f",mediaFem);
		}
	}
//	printf("\n Impares: %d e Pares:%d",impar,par);
	fclose(arq);
		
	return 0;
	
}


int main(){
	lerArquivo();
	return 0;
}
