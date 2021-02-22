#include <stdio.h>
#include <stdlib.h>

// Uma lista encadeada dinamica é constituida de diversos nós(nodes),
// sendo que cada nó da lista aponta para o proximo nó da lista.
typedef struct no{

    int v;
    struct no *proximo;

}lista; // criando o tipo de dado lista

void inserir(lista *lst, int valor);
int tamanho(lista *lst);
int posicao(lista *lst, int elem);
int vazia(lista *lst);
int imprimir(lista *lst);
int imprimir_recursivamente(lista *lst);
int remover(lista *lst);
void destruir_lista(lista *lst);

lista *c_lista = NULL; // cabeça da lista tem como função apenas de apontar para o primeiro no(elemento) da lista

int main(){

    inserir(c_lista, 4);
    inserir(c_lista, 5);
    inserir(c_lista, 6);
    imprimir_recursivamente(c_lista);
    return 1;
}

void inserir(lista *lst, int valor){

    lista *novo = (lista*) malloc(sizeof(lista)); // criando um novo no para a lista
    novo->v = valor; // atribuindo o valor ao novo criado
    novo->proximo = lst;
    c_lista = novo;
}

int tamanho(lista *lst){

    lista *p = lst;
    int n = 0;

    while(p!=NULL){
        p = p->proximo;
        n++;
    }
    return n;
}

int posicao(lista *lst, int elem){

    lista *p = lst;
    int n = 0;

    while(p!=NULL){
        if(p->v == elem) return n;
        p = p->proximo;
        n++;
    }
}

int vazia(lista *lst){

    return (lst == NULL);
}

int imprimir(lista *lst){

    lista *p = lst;

    if(vazia(lst) == 1) return 0;

    while(p!=NULL){
        printf("%d\n", p->v);
        p = p->proximo;
    }

    return 1;
}

int imprimir_recursivamente(lista *lst){

    lista *p = lst;

    if(vazia(lst) == 1) return 0;

    if(p!=NULL){
        printf("%d\n", p->v);
        imprimir_recursivamente(p->proximo);
    }

    return 1;
}

int remover(lista *lst){

    if(vazia(lst) == 1) return 0;

    int excluir, i, n = 0;
    lista *anterior, *aux;
    lista *p = lst;
    printf("Digite o elemento que voce deseja excluir da lista:");
    scanf("%d", &excluir);
    i = posicao(c_lista, excluir);
    //printf("%d\n", i);

     while(p!=NULL && n!=i){
        anterior = p;
        p = p->proximo;
        n++;
    }

    if(i == 0){
        aux = c_lista;
        c_lista = aux->proximo;
        free(aux);
        return 1;
    }else{
        anterior->proximo = p->proximo;  // p == excluir e aux é o anteior a ele
        free(p); // excluindo o no da lista
        c_lista = lst; // atualizando a lista
        return 1;
    }

}

void destruir_lista(lista *lst){

    lista *p = lst;

    while(p!=NULL){
        lista *proximo = p->proximo; /*guarda a referencia do proximo elemento*/
        free(p);
        p = proximo;
    }
}


