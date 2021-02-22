struct pessoa{

    char nome[80];
    char numero[20];
    char endereco[150];

};

typedef struct Agenda{

    struct pessoa *PESSOA;
    struct Agenda *proximo;

}AGENDA;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cabeçalhos.h"

/*

  Feito por: José Augusto
  Programa: Agenda-telefonica
  email: augustoreal.santos@gmail.com

*/

AGENDA *lista = NULL; // ponteiro que serve como cabeça da lista
FILE *file = NULL; // ponteiro para manipulação de streams

int main(void){

    int op = 0;
    lista = (AGENDA*) malloc(sizeof(AGENDA));
    lista->proximo = NULL;
    /*
    typedef struct dados_salvos{

        char nome[80];
        char numero[20];
        char endereco[150];
        struct dados_salvos *proximo;

    }DADOS;

    DADOS *dados = (DADOS*) malloc(sizeof(DADOS));
    dados->proximo = NULL;

    file = fopen("dados.txt", "rb");
    */
    while(!feof(file)){

        fread(&dados, sizeof(struct dados_salvos), 1, file);
        printf("Nome: %s\n", dados->nome);
        printf("Numero: %s\n", dados->numero);
        printf("Endereco: %s\n", dados->endereco);
        lista->proximo = dados->proximo;
    }
    fclose(file);

    while(op!=7){ // loop principal
        printf("1- adicionar contato\n");
        printf("2- alterar contato\n");
        printf("3- excluir contato\n");
        printf("4- salvar agenda\n");
        printf("5 - Opcao de localizar contato pelo nome\n");
        printf("6 - listar todos os contatos\n");
        printf("7- sair da Agenda-telefonica\n");
        printf("Digite a sua op:");
        scanf("%i", &op);
        system("cls");

        switch(op){

            case 1:
                adicionar_contato();
                system("cls");
            break;

            case 2:
                alterar_contato(lista);
                system("cls");
            break;

            case 3:
                excluir_contato(lista);
            break;

            case 4:
                salvar_Agenda(lista);
            break;

            case 5:
                localizar_contato(lista);
            break;

            case 6:
                listar_contatos(lista);
            break;
        }
    }
    return 1;
}
// adcionar um novo contato na lista
void adicionar_contato(void){

    char nome[80], numero[20], endereco[150];
    int op;

     while(op != 2){
        printf("Digite o nome do contato:");
        scanf("%s", nome);
        setbuf(stdin, NULL); // limpeza de buffer do teclado
        printf("Digite o numero do contato:");
        scanf("%s", numero);
        printf("Digite o endereco do contato:");
        scanf("%s", endereco);
        setbuf(stdin, NULL); // segunda limpeza de buffer do teclado
        printf("Dejesa continuar adicionando contatos? 1/S ou 2/N:");
        scanf("%d\n", &op);
        system("cls");

        if(op == 1){
            AGENDA *novo = (AGENDA*) malloc(sizeof(AGENDA));
            strcpy(novo->PESSOA->nome, nome);
            strcpy(novo->PESSOA->numero, numero);
            strcpy(novo->PESSOA->endereco, endereco);
            novo->proximo = lista->proximo;
            lista->proximo = novo;
            system("cls");
        }
    }



}
// alterar um determinado contato já inserido na lista
void alterar_contato(struct Agenda *lista){

    AGENDA *p; // ponteiro para percorrer a lista
    int op = 0;

    for(p = lista->proximo; p != NULL; p = p->proximo){
        printf("Nome: %s\n", p->PESSOA->nome);
        printf("Numero: %s\n", p->PESSOA->numero);
        printf("Endereco: %s\n", p->PESSOA->endereco);
        printf("Voce dejesa alterar esse contato? 1/s ou  2/n:");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        if(op == 1){
            printf("Digite o novo nome do contato:");
            scanf("%s", p->PESSOA->nome);
            printf("Digite o novo numero do contato:");
            scanf("%s", p->PESSOA->numero);
            printf("Digite o novo endereco do contato:");
            scanf("%s", p->PESSOA->endereco);
            system("cls");
        }
    }
}
// excluir um contato da lista
void excluir_contato(struct Agenda  *lista){
}
// salvar a lista em um arquivo aberto em modo binario
void salvar_Agenda(struct Agenda  *lista){

    AGENDA *p; // ponteiro para percorrer a lista
    file = fopen("dados.txt", "wb");

    for(p = lista->proximo; p != NULL; p = p->proximo){
        fwrite(&p, sizeof(AGENDA), 1, file);
    }
    fclose(file);
}
// localizar o numero e endereço apartir de um nome do contato
void localizar_contato(struct Agenda *lista){

    char nome[80];
    printf("Infome o nome do contato que voce dejesa localizar:");
    scanf("%s", &nome);
    AGENDA *p; // ponteiro para percorrer a lista

    for(p = lista->proximo; p != NULL; p = p->proximo){
        if(strncmp(nome, p->PESSOA->nome, strlen(nome)) == 0){
            printf("Nome: %s\n", nome);
            printf("Numero: %s\n", p->PESSOA->numero);
            printf("Endereco: %s\n", p->PESSOA->endereco);
        }
    }
}
// listar todos os contato da lista
void listar_contatos(struct Agenda *lista){

    AGENDA *p; // ponteiro para percorrer a lista

    for(p = lista->proximo; p != NULL; p = p->proximo){
        printf("Nome: %s\n", p->PESSOA->nome);
        printf("Numero: %s\n", p->PESSOA->numero);
        printf("Endereco: %s\n", p->PESSOA->endereco);
        printf("\n");
    }
}
