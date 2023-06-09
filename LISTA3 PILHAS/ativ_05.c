/*
Escreva uma função que inverta a ordem das letras de cada palavra de uma string,
preservando a ordem das palavras. Suponha que as palavras da string são separadas por
espaços. A aplicação da operação à string “AMU MEGASNEM ATERCES”, por
exemplo, deve produzir “UMA MENSAGEM SECRETA”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

void inverte_palavras( char *s );

int main(int argc, char *argv[]) {
	char str[] = "AMU MEGASNEM ATERCES";
	
	inverte_palavras( str );
	
	printf("%s\n", str );
	
	return 0;
}

void inverte_palavras( char *s ){
	Pilha p;
	inicializa_pilha( &p, strlen( s ) );
	
	int i, j, pos = 0; // assumindo que não há espaços no início
	for( i = 0 ; s[i] != 0 ; i++ ){
		if( s[i] != ' ' )
			empilha( &p, s[i] );
		else{
			for( j = pos ; j < i ; j++ ){
				int aux;
				desempilha( &p, &aux );
				s[j] = aux;
			}
			pos = i+1;				
		}
	}
	
	for( j = pos ; j < i ; j++ ){
		int aux;
		desempilha( &p, &aux );
		s[j] = aux;
	}	
	
	desaloca_pilha( &p );
}
