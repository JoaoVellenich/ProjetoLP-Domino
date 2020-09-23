#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoView.h"
#include "DominoModel.h"

void imprimirPecasOrganizadas(Tipo_pecas pc) {
    for (int j = 0; j < 28; j++) {
        if (pc.pecas[j].face2 == 6) {
            printf("[%d|%d]\n", pc.pecas[j].face1, pc.pecas[j].face2);
        }
        else {
            printf("[%d|%d]", pc.pecas[j].face1, pc.pecas[j].face2);
        }
    }
}

void imprimirPecas(Tipo_pecas pc) {
    for (int i = 0; i < N; i++)
    {
        printf("[%d|%d]\n", pc.pecas[i].face1, pc.pecas[i].face2);
    }
}

int menu() {

    int op;
    do
    {
        printf("(1) Iniciar Jogo\n");
        printf("(2) Carregar Jogo\n");
        printf("(3) Continuar\n");
        printf("(4) Regras\n");
        printf("(5) Sair\n");
        printf("Qula sua opcao? \n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 5);

    return op;
}

int menuIniciarJogo() {
    
    int op;

    do
    {
        printf("Iniciar Jogo:\nQuantos jogadores?\n");
        printf("1 Jogador\n2 Jogadores");
        scanf_s("%d", &op);
    } while (op < 0 || op > 2);

    return op;
}

void imprimirMao(Tipo_Jogadores mao) {
    printf("\n[%d|%d] ", mao.jogadores[0].pecas[0].face1, mao.jogadores[0].pecas[0].face2);
    for (int i = 1; i < 7; i++)
    {
        printf("[%d|%d] ", mao.jogadores[0].pecas[i].face1, mao.jogadores[0].pecas[i].face2);
    }
    printf("\n[%d|%d] ", mao.jogadores[1].pecas[0].face1, mao.jogadores[1].pecas[0].face2);
    for (int i = 1; i < 7; i++)
    {
        printf("[%d|%d] ", mao.jogadores[1].pecas[i].face1, mao.jogadores[1].pecas[i].face2);
    }
}

void imprirPcOrganizado(Tipo_pecas pc) {
    for (int i = 0; i < 27; i++)
    {
        if (pc.pecas[i].face1 != -1)
        {
            printf("[%d|%d]\n", pc.pecas[i].face1, pc.pecas[i].face2);
        }
    }

}