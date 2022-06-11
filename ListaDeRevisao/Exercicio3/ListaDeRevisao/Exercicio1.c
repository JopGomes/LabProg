#include <stdio.h>

int main(n){
	int numb;
	int i;
	printf("Digite o numero n: \n");
	scanf("%i",&numb);
	printf("Os numeros sao: \n");
	for(i=0; i<numb ;i=i+1){
		if(i%2==0){
			printf("%i",i);
			printf("\n");
		}
	}
	return 0;
}
