#include <stdio.h>

int retornaPar(int N1, int i) //retornaPAr recebe N1 q é o numero maximo e i que é o numero atual
{
  if(i%2==0 && N1>=i){
  	printf("%d \n",i);
  	retornaPar(N1, i+1);
  	if(N1 == i){
  		printf("Fim");
	}
  	return 0;
  }
  if(i==N1){
  	printf("Fim");
  	return 0;
  }
  if(N1> i){
  	retornaPar(N1,i+1);
  }

}


int main(){
	printf("Escreva n:");
	int n;
	scanf("%d",&n);
	retornaPar(n,0);	
}
