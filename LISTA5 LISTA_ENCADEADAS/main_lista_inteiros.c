#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <time.h>

void mostra_int( void *x );

int main(int argc, char *argv[]) {
	Lista l1;
	
	inicializa_lista( &l1, sizeof(int) );
	
	int n, i, aux;
	scanf("%d", &n);
	
	srand( time(0) );
	for( i = 1 ; i <= n ; i++ ){
		int x = rand();
		insere_inicio( &l1, &x );
	}
	mostra_lista( l1, mostra_int );
	// remove_fim(&l1, &aux);
	
	//int x = rand();
	//insere_fim(&l1, &x);
	
	
	// limpa_lista(&l1);

	conta_elementos(l1);
	
	//mostra_lista( l1, mostra_int );
	return 0;
}

void mostra_int( void *x ){
	int *p = x;
	printf("%d\n", *p);
}

