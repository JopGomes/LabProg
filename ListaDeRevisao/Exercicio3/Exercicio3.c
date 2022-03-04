#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lerArquivo() 
{
	  char nomeArquivo[100];
	  char url[100];
	  char txt[]=".txt";

	  char info[100];	
	  int par=1,impar=0, k=0,num;
	  printf("Digite o nome do arquivo: ");
	  scanf("%s",nomeArquivo);
	  strcpy(url,nomeArquivo);
	  strcat(url,txt);
	  char ch;
	 FILE *arq;
	          
	 arq = fopen(url, "r");
	 if(arq == NULL)
	     printf("Erro, nao foi possivel abrir o arquivo\n");
	else
  		while( (fgets(info, sizeof(info), arq))!=NULL ){
//   			printf("%s", info);
   			sscanf(info, "%d", &num);
  	     	if(num%2==0){
	     		par=par*num;
	     		
			 }
			if(num%2 ==1){
				impar+=num;
			}
		}
	printf("\n Impares: %d e Pares:%d",impar,par);
	fclose(arq);
		
	return 0;
	
}


int main(){
	lerArquivo();
	return 0;
}
