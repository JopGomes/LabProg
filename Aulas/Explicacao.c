#include <stdio.h>

int main(){
	int x=10;
	int *ptr;
	ptr = &x;
	printf("%d \n",ptr);
	printf("%d \n",*ptr);
	*ptr = 13;
	printf("%d \n",x);
	
}
