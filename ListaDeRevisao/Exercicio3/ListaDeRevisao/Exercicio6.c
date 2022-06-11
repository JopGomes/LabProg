#include <stdio.h>

int main(){
	int n,i;
	int n0=1,n1=1,temp;
	printf("Digite n:");
	scanf("%d",&n);
	for(i=2; n>i;i++){
		temp=n1;
		n1=temp+n0;
		n0=temp;
	}
	printf("%d", n1);
	return 0;
}
