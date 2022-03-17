#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//// ========Explica��o do ponteiro
//int main(){
//	int a;
//	a=10;
//	
//	int *ptr;
//	float *ptr2;// [Warning] assignment from incompatible pointer type
//	// � v�lido mas pode ser o causador do problema por conta do tipo, logo n�o fazer
//	
//	ptr = &a;
//	ptr2= &a; 
//	
//	printf("a= %d\n",a);
//	printf("->ptr = %d \n", *ptr);
//	printf("->ptr2 = %f \n", *ptr2); 
//	return 0;
//}

//// ========Aloca��o est�tica 
//int main(){
//	int vetor[11]; //Com erro de Buffer overflow no vetor se fosse 10
//	
//	for(int i=0 ; i<11;i++)
//		vetor[i]=2*i+1;
//	
//	for(int i=0;i<11;i++)
//		printf("%d\n",vetor[i]);
//	
// 
//	return 0;
//}

//// ========Aloca��o dinamica com malloc
//
//int main(){
//	int n;
//	int i;
//	scanf("%d",&n);
//	
//	int *vetor; 
//	vetor = (int*) malloc(n * sizeof(int));
//	if(!vetor){
//		return 17;
//	} 
//	
//	for(i=0 ; i<n;i++)
//		vetor[i]=2*i+1;
//	
//	for(i=0;i<n;i++)
//		printf("%d\n",vetor[i]);
//	
// 
//	return 0;
//}

//// ========Aloca��o dinamica com calloc 
//int main(){
//	int n;
//	int i;
//	scanf("%d",&n);
//	
//	int *vetor; 
//	vetor = (int*) calloc(n , sizeof(int));
//	if(!vetor){
//		return 17;
//	} 
//	for(i=0 ; i<n;i++)
//		vetor[i]=2*i+1;
//	
//	for(i=0;i<n;i++)
//		printf("%d\n",*(vetor+i)); //*(vetor+i) � equivalente a vetor[i]
//	
// 
//	return 0;
//}

// === Aloca��o dinamica com matriz ponteiro e malloc==
//int main(){
//	int n;
//	scanf("%d",&n);
//	// Criando variaveis
//	int **matriz,i,j;
//	
//	//Alocando na memoria
//	// Criamos um malloc para todas as linhas e depois alocamos para cada linha
//	matriz = (int**) malloc(n*sizeof(int*)); // observe que � um * a menos em rela��o a matriz no valor do sizeof 
//	for(i=0;i<n;i++)
//		matriz[i]=(int*) malloc(n*sizeof(int)); // Observe que � int* ali por que � um vetor
//	
//	for(i=0; i<3;i++)
//		for(j=0; j<3;j++)
//			matriz[i][j]=2*i+3*j;
//	for(i=0; i<3;i++)
//
//		for(j=0; j<3;j++)
//			printf("%d \n",matriz[i][j]);
//	
//	// Teve n+1 aloca��es dinamicas ent�o devemos liberar as n+1 memorias
//	for( i=0; i<n; i++) // Desaloca na ordem inversa a aloca��o, para n�o desalocar uma que j� foi desalocada para n�o dar erro de liberar area n�o alocada
//		free(matriz[i]); 
//	free(matriz);
//	
//	return 0;
//}

typedef struct{
	char nome[10];
	int codigo;
} TExemplo;

int main(){
	TExemplo e,e2;
	strcpy(e.nome,"Joao");
	e.codigo = 20123;
	e2 =e;
	
	printf("%s - %d \n",e2.nome,e2.codigo);
	printf("%d \n",sizeof(TExemplo));
	return 0;
}
