#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct sLista{
	int valor;
	struct sLista *prox;
} TLista;

void insere(TLista **pInicio, int valor){
	TLista *novoElemento = (TLista*) malloc(sizeof(TLista));
	novoElemento->valor=valor;
	novoElemento->prox= *pInicio;
	*pInicio = novoElemento;
}
void remove(TLista **pInicio, int valor){
	TLista *aux= *pInicio, *anterior = NULL;
	while(aux){
		if(valor == aux->valor){
			break;
		}
		anterior = aux;
		aux = aux->prox;
	}
	if(aux){
		if(anterior)
			anterior->prox = aux->prox;
		else
			*pInicio = aux ->prox;
		free(aux);
	}
}

int buscar(TLista *inicio, int valor){
	while(inicio){
		if(valor== inicio->valor){
			return 1;
		}
		inicio = inicio ->prox;
	}
	return -1;
}

int main(){
	TLista *inicio = NULL, *aux;
	
	insere(&inicio,10);
	insere(&inicio,20);
	insere(&inicio,30);
	printf("B%d \n",buscar(inicio,30));
	remove(&inicio,30);
	printf("B%d \n",buscar(inicio,30));
	aux=inicio;
	while(aux){
		printf("*%d* \n",aux->valor);
		aux = aux->prox;
	}
	//liberar memoria
	aux=inicio;
	while(aux){
		TLista *tmp = aux->prox;
		free(aux);
		aux=tmp;
	}
	
}
