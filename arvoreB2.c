/**
	COMO COMPILAR:
	
	gcc arvoreB2.c -o arvoreB2exeFile.exe
	./arvoreB2exeFile.exe
*/

#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>

#define t 2

typedef int TipoChave;

typedef struct no{
    TipoChave chave[2*t-1];
	struct no *filho[2*t];
    bool folha;
    int numChaves;
}NO;

void iniciaArvoreB(NO*raiz){
    raiz = (NO*)malloc(sizeof(NO));
    raiz->folha = true;
    raiz->numChaves = 0;
	int fValor = 0;
	while(fValor < 2*t){
		raiz->filho[fValor] = NULL;
		fValor++;
	}
}

void imprimeArvoreB(NO*raiz){
    NO* p = raiz;
    printf("(S");
	
	int tValor =  t;
	printf("\n ALHO_%p \n",p->filho[0]);
	printf("\n ALHO_%p \n",p->filho[1]);
	printf("\n ALHO_%p \n",p->filho[2]);
	printf("\n ALHO_%p \n",p->filho[3]);
	
	while(tValor>1){
		p = p->filho[0];
		tValor--;
	}
	
    /*
	printf("\n Valor da folha? %s", p->folha?"true":"false");
	int i = 0;
    while(!p->folha){
        p = p->filho[i];
        printf("(I");
    }
	*/
    printf("E)");
}

void main(){
	NO raiz;
    iniciaArvoreB(&raiz);
    imprimeArvoreB(&raiz);
    //buscaArvoreB(&raiz,20,);
    printf("\n**************COMPILOU!****************\n");
}