/**
	COMO COMPILAR:
	
	gcc arvoreB2.c -o arvoreB2exeFile.exe
	./arvoreB2exeFile.exe
	
	EXCETO A RAIS Q NO INICIO TEM 2 SETAS NULL E 1 ELEMENTO/QUADRINHO QUE É A RAIZ
	SE T = 2 MAX FILHOS/SETAS SAINDO = 2*T = 4
	SE T = 2 MAX DE ELEMENTOS/QUADRADINHOS = 2*T-1 = 3
	
	Filhos tem p->numChave.
	O GCC faz a conta com quebra pro chão, arredonda pra menos.
	Nesse code ele quebra numeros par para n+1
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

void imprimeArvoreB(NO raiz){
    NO p = raiz;
    printf("\n(S");
    
	//printf("\n Valor da folha? %s", p->folha?"true":"false");
	
	//SE FOR FOLHA
	if(p.folha){
		//ESTÁ COM ELEMENTOS
		if(p.numChaves > 0){
			int chValor;
			for(chValor = 0; chValor < 2*t-1 && chValor < p.numChaves; chValor++){
				printf("%d ",p.chave[chValor]);
			}
		}
		//ESTÁ VAZIA
		else{
			//FAZ NADA
		}
	}
	
	int i = 0;
    while(!p.folha){
        p = *p.filho[i];
        printf("(I");
    }
	
    printf("E)\n");
}

NO insereArvoreB(NO* raiz, int ch){
	NO* p = raiz;
	//É FOLHA E NÃO ESTÁ CHEIA
	if(p->folha && p->numChaves < 2*t-1){
		int chValor = 0;
		//BUSCO A PRIMEIRA CASA VAZIA
		while(p->chave[chValor]){
			chValor++;
		}
		//SET OS FILHOS PRA NULL SE FOR O PRIMEIRO ELEMENTO
		if(chValor == 0){
			int numFilho;
			for(numFilho = 0; numFilho < 2*t; numFilho++){
				p->filho[numFilho] = NULL;
			}
		}
		//VERIFICO SE ESTÁ ORDENADA
		else{
			//SE A ANT É MAIOR QUE A INSERIDA
			while(p->chave[chValor-1] > ch){
				p->chave[chValor] = p->chave[chValor-1];
				chValor--;
			}
		}
		p->chave[chValor] = ch;
		//printf("chave inserida %d \n",p->chave[chValor]);
		//AUMENTA O NUMERO DE CHAVES NO REGISTRO
		p->numChaves++;
    }
	
	//É FOLHA E ESTÁ CHEIA
	else if(p->folha && p->numChaves > 2*t-1){
		//ACHAR A CHAVE DO MEIO
		int chValor = 0;
		while(p->chave[chValor]< ch){
			chValor++;
		}
		//T É UM NUMERO PAR
		if(t%2==0){
			if(chValor<=(2*t-1)/2){
				printf("\n 1 O VALOR DA QUEBRA É %d\n", 1);
			}
			if(chValor == ((2*t-1)/2)+1){
				printf("\n 2 O VALOR DA QUEBRA É %d\n", 2);
			}
			if(chValor>((2*t-1)/2)+1){
				printf("\n 3 O VALOR DA QUEBRA É %d\n", 3);
			}
		}
		// T É UM NUMEMO IMPAR
		else{
			if(chValor<(2*t-1)/2){
				printf("\n 4 O VALOR DA QUEBRA É %d\n", 4);
			}
			if(chValor == (2*t-1)/2){
				printf("\n 5 O VALOR DA QUEBRA É %d\n", 5);
			}
			if(chValor>(2*t-1)/2){
				printf("\n 6 O VALOR DA QUEBRA É %d\n", 6);
			}
		}
	}
	
	return *raiz;
}

NO removerArvoreB(NO* raiz, int ch){
	NO* p = raiz;
	
	//NÃO TEM FILHOS
	if(!p->filho[0]){
		int chValor;
		for(chValor = 0; ch != p->chave[chValor]; chValor++){	
		}
		if(p->chave[chValor] == ch){
			p->numChaves--;
			while(chValor < p->numChaves ){
				p->chave[chValor] = p->chave[chValor+1];
				chValor++;
			}
			p->chave[chValor] = 0;
		}		
	}
	
	return *raiz;
}

void main(){
	NO raiz;
    raiz = iniciaArvoreB(&raiz);
	
	raiz = insereArvoreB(&raiz, 30);
	raiz = insereArvoreB(&raiz, 20);
	//raiz = insereArvoreB(&raiz, 10);
	//raiz = insereArvoreB(&raiz, 9);
	imprimeArvoreB(raiz);
	
	//raiz = removerArvoreB(&raiz, 30);
	raiz = removerArvoreB(&raiz, 20);
	//raiz = removerArvoreB(&raiz, 10);
	imprimeArvoreB(raiz);
	
	int i,r;
	
	FILE *fp;
	fp = fopen("entrada1.txt","r");
	if (!fp) {
		printf("Erro ao abrir o arquivo");
	}
	else{
		char buff[255];
		fscanf(fp, "%s", buff);
		//printf("f = %s\n", buff );
		char*save = buff;
		
		while(*save!='f'){
			printf("OK");
			if(*save=='i'){
				//LÊ O ESPAÇO
				//LÊ O PRIMEIRO NUMERO
				//LÊ O SEGUNDO NUMERO
				//CONCATENA				
			}
			else if(*save=='r'){
				//LÊ O ESPAÇO
				//LÊ O PRIMEIRO NUMERO
				//LÊ O SEGUNDO NUMERO
				//CONCATENA
			}
			else if(*save=='p'){
				imprimeArvoreB(raiz);
			}
			//LÊ A PROXIMA LINHA
			fscanf(fp, "%s", buff);
			char*save = buff;
			i = (int)save[0]-48;
		}
	}
    printf("\n**************COMPILOU!****************\n");
}