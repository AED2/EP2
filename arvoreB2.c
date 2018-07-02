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
	FILE * fp;
	fp = fopen ("saida1.txt", "w");
	
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
			    //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
				fprintf(fp,"\n %d ",p.chave[chValor]);			    
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
	//fclose(fp);
}

NO insereArvoreB(NO* raiz, int ch){
	printf("Vou inserir a chave: %d \n",ch);
	NO* p = raiz;
	//É FOLHA E NÃO ESTÁ CHEIA
	if(p->folha && p->numChaves < 2*t-1){
		int chValor = 0;
		//BUSCO A PRIMEIRA CASA VAZIA
		while(p->chave[chValor]){
			chValor++;
			//printf("\n ch valor1: %d \n", chValor);
		}
		p->chave[chValor] = ch;
		//AUMENTA O NUMERO DE CHAVES NO REGISTRO
		p->numChaves++;
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
			while(p->chave[chValor-1] > p->chave[chValor]){
				//printf("\n ch valor: %d \n", p->chave[chValor-1]);
				int aux = p->chave[chValor];
				p->chave[chValor] = p->chave[chValor-1];
				p->chave[chValor-1] = aux;
				if(chValor>1){
					chValor--;
				}
				else{
					break;
				}
			}
		}
    }
	
	//É FOLHA E ESTÁ CHEIA
	else if(p->folha && p->numChaves >= 2*t-1){
		printf("Vou inserir uma FOLHA E ESTÁ CHEIA \n");
		//ACHAR A CHAVE DO MEIO
		int chValor = 0;
		while(p->chave[chValor]< ch){
			chValor++;
		}
		//T É UM NUMERO PAR
		if(t%2==0){
			if(chValor<=(2*t-1)/2){
				printf("\n CASO 1 O VALOR DA QUEBRA É %d\n", chValor);
				NO raizNew;
				iniciaArvoreB(&raizNew);
				*raiz = raizNew;
				*raiz =insereArvoreB(raiz,p->chave[(2*t-1)/2]);
				raiz->folha = false;
				*raiz =insereArvoreB(raiz,ch);
				for(chValor = 1; chValor<=(2*t-1)/2; chValor++){
					*raiz =insereArvoreB(raiz,p->chave[chValor]);
				}
				for(chValor = p->numChaves-1; chValor>(2*t-1)/2; chValor--){
					*raiz =insereArvoreB(raiz,p->chave[chValor]);
				}
				printf("\n Vou imprimir \n");
				imprimeArvoreB(*raiz);
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

NO insereFilhoArvoreB(NO* raiz, int chs[], int filho){
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
	raiz = insereArvoreB(&raiz, 10);
	raiz = insereArvoreB(&raiz, 9);
	//imprimeArvoreB(raiz);
	
	//raiz = removerArvoreB(&raiz, 30);
	//raiz = removerArvoreB(&raiz, 20);
	//raiz = removerArvoreB(&raiz, 10);
	imprimeArvoreB(raiz);
/*	
	int i1,i2,i,r1,r2,r;
	
	FILE *fp;
	fp = fopen("entrada1.txt","r");
	if (!fp) {
		printf("Erro ao abrir o arquivo");
	}
	else{
		char buff[255];
		fscanf(fp, "%s", buff);
		char*save = buff;
		while(save[0]!='f'){
			//fgets(buff, 255, (FILE*)fp);
			//printf("OK zero:%c one:%c two:%c tre:%c \n", save[0], save[1], save[2], save[3]);
			if(save[0] =='i' && raiz.numChaves == 0){
				//LÊ O ESPAÇO
				fgets(buff, 255, (FILE*)fp);
				//LÊ O PRIMEIRO NUMERO
				i1 = (int)save[1]-48;
				//LÊ O SEGUNDO NUMERO
				i2 = (int)save[2]-48;
				//CONCATENA	
				i = (i1*10) + i2;
				raiz = insereArvoreB(&raiz, i);
				imprimeArvoreB(raiz);
			}
			else if(save[0] =='i'){
				//LÊ O ESPAÇO
				fgets(buff, 255, (FILE*)fp);
				fgets(buff, 255, (FILE*)fp);
				//save = buff;
				//LÊ O PRIMEIRO NUMERO
				i1 = (int)save[2]-48;
				//LÊ O SEGUNDO NUMERO
				i2 = (int)save[3]-48;
				//CONCATENA	
				i = (i1*10) + i2;
				raiz = insereArvoreB(&raiz, i);
				imprimeArvoreB(raiz);
			}
			else if(save[0] =='r'){
				//LÊ O ESPAÇO
				fgets(buff, 255, (FILE*)fp);
				fgets(buff, 255, (FILE*)fp);
				//LÊ O PRIMEIRO NUMERO
				r1 = (int)save[2]-48;
				//LÊ O SEGUNDO NUMERO
				r2 = (int)save[3]-48;
				//CONCATENA	
				r = (r1*10) + r2;
				raiz = removerArvoreB(&raiz, r);
				imprimeArvoreB(raiz);
			}
			else if(save[0] =='p'){
				imprimeArvoreB(raiz);
			}
			//LÊ A PROXIMA LINHA
			fgets(buff, 255, (FILE*)fp);
			save = buff;
			//printf(" after %c\n", save[0]);
		}
	}
	imprimeArvoreB(raiz);
*/    printf("\n**************COMPILOU!****************\n");
}