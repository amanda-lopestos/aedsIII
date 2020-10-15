/*Atividade (2) de AEDSIII, período ERE2020/5:
Crie as funções: pré-ordem e pós-ordem!
*
*
*por @https://repl.it/@amandalopestos/atv2-AEDSIII#main.c
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct no{
    int CHAVE;
    struct no *dir;
    struct no *esq;
}NO;

void inserir(NO *raiz,NO *p){

    if(p->CHAVE > raiz->CHAVE){ 
        if(raiz->dir == NULL) raiz->dir = p;
        else inserir(raiz->dir,p);
    }
    if(p->CHAVE < raiz->CHAVE){
        if(raiz->esq == NULL) raiz->esq = p;
        else inserir(raiz->esq,p);
    }
}
void imprimirPreOrdem(NO *raiz){ 
    printf("%d ",raiz->CHAVE);
    if(raiz->esq != NULL) imprimirPreOrdem(raiz->esq);
    if(raiz->dir != NULL) imprimirPreOrdem(raiz->dir);
}


void imprimirPosOrdem(NO *raiz){ 
    if(raiz->esq != NULL) imprimirPosOrdem(raiz->esq);
    if(raiz->dir != NULL) imprimirPosOrdem(raiz->dir);
    printf("%d ",raiz->CHAVE);
}

void pesquisar(NO *raiz, int CHAVE){
    if(raiz->CHAVE == CHAVE) printf("Encontrado");
    if(CHAVE > raiz->CHAVE && raiz->dir != NULL) pesquisar(raiz->dir,CHAVE);
    if(CHAVE < raiz->CHAVE && raiz->esq != NULL) pesquisar(raiz->esq,CHAVE);
}

void init(NO* raiz){ // COMEÇA POR ----> nó raiz
    raiz = NULL;
}

int nula(NO* raiz){ // EXAMINA se árvore está vazia
    if(raiz == NULL) 
        return 1; // Caso estiver VAZIO, retorna true 
    else 
        return 0;
}

int main()
{
    NO *raiz;    
    NO *p;

    init(raiz);

    int valor[5]={19,6,33,15,2};
    for(int i=0;i<5;i++){
        p=(NO*) malloc(sizeof(NO)); 
        p->CHAVE=valor[i];
        p->dir = NULL;
        p->esq = NULL;
        if(nula(raiz)) raiz = p;
        else inserir(raiz,p);
    }
    
    return 0;
}

  