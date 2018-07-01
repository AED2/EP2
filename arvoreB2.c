/**
	COMO COMPILAR:
	
	gcc arvoreB2.c -o arvoreB2exeFile.exe
	./arvoreB2exeFile.exe
	
	EXCETO A RAIS Q NO INICIO TEM 2 SETAS NULL E 1 ELEMENTO/QUADRINHO QUE É A RAIZ
	SE T = 2 MAX FILHOS/SETAS SAINDO = 2*T = 4
	SE T = 2 MAX DE ELEMENTOS/QUADRADINHOS = 2*T-1 = 3
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

NO iniciaArvoreB(NO* raiz){
    raiz = (NO*)malloc(sizeof(NO));
    raiz->folha = true;
    raiz->numChaves = 0;
	int fValor = 0;
	while(fValor < 2*t){
		raiz->filho[fValor] = NULL;
		fValor++;
	}
	return *raiz;
}

void imprimeArvoreB(NO*raiz){
    NO* p = raiz;
    printf("(S");
    
	//printf("\n Valor da folha? %s", p->folha?"true":"false");
	
	//SE FOR FOLHA
	if(p->folha){
		//ESTÁ VAZIA
			//FAZ NADA
		//ESTÁ COM ELEMENTOS
		int chValor;
		for(chValor = 0; chValor < 2*t-1 && chValor < p->numChaves; chValor++){
			printf(" %d ",p->chave[chValor]);
		}
	}
	
	int i = 0;
    while(!p->folha){
        p = p->filho[i];
        printf("(I");
    }
	
    printf("E)");
}

NO insereArvoreB(NO* raiz, int ch){
	NO* p = raiz;
	if(p->folha){
		p->chave[0] = ch;
		p->numChaves++;
		int numFilho;
		for(numFilho = 0; numFilho < 2*t; numFilho++){
			p->filho[numFilho] = NULL;
		}
    }
	return *raiz;
}

void main(){
	NO raiz;
    raiz = iniciaArvoreB(&raiz);
    imprimeArvoreB(&raiz);
	
	raiz = insereArvoreB(&raiz, 10);
	imprimeArvoreB(&raiz);
    //buscaArvoreB(&raiz,20,);
    printf("\n**************COMPILOU!****************\n");
}