/**
	COMO COMPILAR:
	
	gcc arvoreB2.c -o arvoreB2exeFile.exe
	./arvoreB2exeFile.exe
*/

#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#define t 5

typedef int TipoChave;

typedef struct no{
    TipoChave chave[2*t-1];
    struct no*filho[2*t];
    bool folha;
    int numChaves;
}NO;

void iniciaArvoreB(NO*raiz){
    raiz = (NO*)malloc(sizeof(NO));
    raiz->folha = true;
    raiz->numChaves = 0;
    ///escreve no disco raiz
}

void main(){
	NO*raiz;
    //iniciaArvoreB(&raiz);
    //imprimeArvoreB(&raiz);
    //buscaArvoreB(&raiz,20,);
    printf("\n**************COMPILOU!****************\n");
}