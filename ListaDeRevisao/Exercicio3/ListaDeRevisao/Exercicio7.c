#include <stdio.h>
#include <stdlib.h>

void mudanca(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              mudanca(&arr[j], &arr[j+1]);
}

void mostrarVetor(int vetor[],int n){
	int i;
	for(i=0; n>i;i++){
		printf("%d ,", vetor [i]);
	}
}

int main(){
	int n,i;
	printf("Digite o valor n:");
	scanf("%d",&n);
	int vetor[n];
	for(i=0; n>i; i++){
		vetor[i] = rand() % 1000;
	}
	bubbleSort(vetor,n);
	mostrarVetor(vetor,n);
	return 0;
}
