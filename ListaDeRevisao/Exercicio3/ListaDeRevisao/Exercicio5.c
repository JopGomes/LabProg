#include <stdio.h>

int fibonacci(int max, int n1, int n0 , int atual  ) //Serie de fibonacci
{
	int temp = n1;
	n1 = temp + n0;
	n0= temp;
	atual++;
	if(max>atual){
		fibonacci(max,n1,n0,atual);
	}
	else return n1;
}


int main(){
	int n;
	printf("Digite o numero:");
	scanf("%d",&n);
	int final =fibonacci(n,1,1,2);
	printf("%d",final);
	return  final;
}
