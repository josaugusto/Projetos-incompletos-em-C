#include <stdio.h>
#include <stdlib.h>
#include "Jogo-da-velha.h"

char tabuleiro[3][3] = {{'x', 'o', 'x'},
                        {'o', 'x', 'x'},
                        {'o', 'o', 'x'}};

struct jogador_1 player_1;

struct jogador_2 player_2;

int main(){

    carrega_save();
    abertura_jogo();
    //salva_jogo();
    return 0;
}

void abertura_jogo(){

    int op;
    puts("--------------------------------------------------\n");
    puts("\t  JOGO-DA-VELHA!\n\n\tCriado por Gugusto\n");
    puts("--------------------------------------------------\n");
    pula_linha(1);
    mostra_tabuleiro();
    printf("\n");
    pula_linha(2);
    printf("Deseja iniciar uma nova partida 1/S ou 2/N:");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        novo_jogo();
    }
    else
        exit(0);
}

void nomes_jogadores(void){

    printf("Informe o nome e idade do player 1(x):");
    scanf("%s %d", &player_1.nome, &player_1.idade);
    printf("Informe o nome e idade do player 2(o):");
    scanf("%s %d", &player_2.nome, &player_1.idade);
}

void novo_jogo(void){

    limpa_tabuleiro();
    nomes_jogadores();
    ler_jogada();
    verifica_jogo();

}

void ler_jogada(void){

        int i = 0;

        while(i<3){
            printf("Informe a linha(0,1,2) e a coluna(0, 1 e 2) a ser jogada %s:", player_1.nome);
            scanf("%d%d", &player_1.linha, &player_1.coluna);
            tabuleiro[player_1.linha][player_1.coluna] = 'x';
            mostra_tabuleiro();
            printf("Infrome a linha e a coluna a ser jogada %s:", player_2.nome);
            scanf("%d%d", &player_2.linha, &player_2.coluna);
            tabuleiro[player_2.linha][player_2.coluna] = 'o';
            mostra_tabuleiro();
            i++;
        }
}
void mostra_tabuleiro(void){

    int i,j;

    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%3c", tabuleiro[i][j]);
        }
        printf("  <-%2d\n", i);
    }
    printf("  \n  1  2  3\n  ^  ^  ^\n  |  |  |");
}

int verifica_jogo(void){

}

void salva_jogo(void){

    int i,j;
    FILE *f = fopen("save.txt", "w");

    if(f != NULL){
         for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                fprintf(f,"%c", tabuleiro[i][j]);
            }
             fprintf(f,"\n");
        }
        fclose(f);
    }
    else
        exit(0);
}

void carrega_save(void){

    int i,j;
    FILE *f = fopen("save.txt", "r");

    if(f != NULL){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                tabuleiro[i][j] = fgetc(f);
            }
            fprintf(f, "\n");
         }
        fclose(f);

    }else
        exit(0);

}

int limpa_tabuleiro(void){

    int i,j;

     for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                tabuleiro[i][j] = ' ';
            }
         }
    return 0;
}

void pula_linha(int n){

    int i = 0;

    while(i<=n){
        printf("\n");
        i++;
    }
}
