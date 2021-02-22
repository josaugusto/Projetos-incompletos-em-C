#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

/*

  Feito por: José Augusto
  Programa: Agenda-telefonica
  email: augustoreal.santos@gmail.com

*/

typedef struct{

    char nome[80];
    char numero[20];
    char endereco[150];

}AGENDA;


AGENDA dados[51];
int op, y, slots_resevados = 0;
char caracter_especial = 128;
FILE *file;

int main(){
        // faz a leitura dos dados salvados anteriomente
        file = fopen("Memoria.dat", "rb");
        fread(&slots_resevados, sizeof(int), 1, file);
        fclose(file);
        file = fopen("Agenda.dat", "rb");
        fread(&dados[y], sizeof(AGENDA), slots_resevados, file);
        fclose(file);

        while(op!=7){
                // Menu de opcões
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
                            adiciona_contato();
                            system("cls");
                        break;

                        case 2:
                            altera_contato();
                            system("cls");
                        break;

                        case 3:
                            exclui_contato();
                            system("cls");
                        break;

                        case 4:
                            salva_Agenda();
                        break;

                        case 5:
                            localiza_contato();
                        break;

                        case 6:
                            lista_contatos();
                        break;
                }
        }
    return 0;
}
// adciona um contato na agenda
void adiciona_contato(){

        while(op!=2){
                setbuf(stdin, NULL);
                printf("Digite o nome do contato:");
                gets(dados[slots_resevados].nome);
                printf("Digite o numero do contato:");
                gets(dados[slots_resevados].numero);
                printf("Digite o endere%co do contato:", caracter_especial);
                gets(dados[slots_resevados].endereco);
                ++slots_resevados;
                printf("Dejesa continuar adicionado 1/S - 2/N:");
                scanf("%d", &op);
        }
}
// altera um contato da agenda
void altera_contato(){

        int contato_excluir;

        for(y=0;y<slots_resevados;++y){
                printf("Contato %d\n", y);
                printf("Nome: %s\n", dados[y].nome);
                printf("Numero: %s\n", dados[y].numero);
                printf("Endere%co: %s\n", caracter_especial, dados[y].endereco);
        }

        printf("Digite o contato que voce dejesa alterar:");
        scanf("%d", &contato_excluir);
        setbuf(stdin, NULL);
        printf("Digite o novo nome para o contato %d:", contato_excluir);
        gets(dados[contato_excluir].nome);
        printf("Digite o novo numero para o contato %d:", contato_excluir);
        gets(dados[contato_excluir].numero);
        printf("Digite o novo endere%co para o contato %d:", caracter_especial, contato_excluir);
        gets(dados[contato_excluir].endereco);
}
// excluir um contato no array of structs
void exclui_contato(){

        int contato_excluir;

        for(y=0;y<slots_resevados;y++){
                printf("Contato %d\n", y);
                printf("Nome: %s\n", dados[y].nome);
                printf("Numero: %s\n", dados[y].numero);
                printf("Endere%co: %s\n", caracter_especial, dados[y].endereco);
        }

        printf("Digite qual contato vo%ce dejesa excluir:", caracter_especial);
        scanf("%d", &contato_excluir);

       for(y=contato_excluir;y<slots_resevados;y++){
                strcpy(dados[y].nome, dados[y+1].nome);
                strcpy(dados[y].numero, dados[y+1].numero);
                strcpy(dados[y].endereco, dados[y+1].endereco);
       }
        slots_resevados = slots_resevados - 1;
}
// salvar os dados em um arquivo binario
void salva_Agenda(){

        file = fopen("Memoria.dat", "wb");
        fwrite(&slots_resevados, sizeof(int), 1, file);
        fclose(file);
        file = fopen("Agenda.dat", "wb");
        fwrite(&dados, sizeof(AGENDA), slots_resevados, file);
        fclose(file);
}
// localiza um contato da agenda atravez do nome
void localiza_contato(){

        char localiza_contato[50];
        setbuf(stdin, NULL);
        printf("Digite o nome do contato que voce dejesa localizar:");
        gets(localiza_contato);

        for(y=0;y<slots_resevados;++y){
                if(strncmp(dados[y].nome, localiza_contato, strlen(localiza_contato)) == 0){
                        printf("O Contato %d\n", y);
                        printf("Nome: %s\n", dados[y].nome);
                        printf("Numero: %s\n", dados[y].numero);
                        printf("Endere%co: %s\n", caracter_especial, dados[y].endereco);
                        printf("\n");
                }
        }
}
// lista todos os contatos presentes na agenda
void lista_contatos(){

        for(y=0;y<slots_resevados;++y){
                printf("Contato %d\n", y);
                printf("Nome: %s\n", dados[y].nome);
                printf("Numero: %s\n", dados[y].numero);
                printf("Endere%co: %s\n", caracter_especial, dados[y].endereco);
        }
}
