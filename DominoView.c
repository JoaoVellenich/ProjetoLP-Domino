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
        printf("INICIAR JOGO:\n\nQuantos jogadores?\n");
        printf("1 Jogador\n2 Jogadores");
        scanf_s("%d", &op);
    } while (op < 0 || op > 2);

    return op;
}

void imprimirMao(Tipo_Jogadores mao, int op) {

    if (op == 1)
    {
        printf("\n\nMao Jogador 1:\n ");
        for (int i = 0; i < retornarQtdJogador1(); i++)
        {
            printf("(%d) [%d|%d] ", (i+1),mao.jogadores[0].pecas[i].face1, mao.jogadores[0].pecas[i].face2);
        }
    }
    else if (op == 2)
    {
        printf("\n\nMao Jogador 2:\n ");
        for (int i = 0; i < retornarQtdJogador2(); i++)
        {
            printf("(%d) [%d|%d] ", (i+1),mao.jogadores[1].pecas[i].face1, mao.jogadores[1].pecas[i].face2);
        }
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

int menuInGame() {
    int op;

    do{
        printf("\n(1) Distribuir Peças\n");
        printf("(2) Mostrar Mesa\n");
        printf("(3) Mostrar Mao\n");
        printf("(4) Comprar Peças\n");
        printf("(5) Voltar ao Menu Inicial\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 5);

    return op;
}

int menuComprarPecas() {
    int op = 0;

    do
    {
        printf("Qual jogador ira comprar?\n(1) Jogador 1\n(2) Jogador 2\n(3)Deixar de Comprar\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 3);

    return op;
}

void desenharMesa(Tipo_pecas pecasDesenhada) {

    for (int i = 0; i < retornarQtdMesa(); i++)
    {
        printf("[%d|%d] ", pecasDesenhada.pecas[i].face1, pecasDesenhada.pecas[i].face2);
    }
    
}

int menuMesa() {
    int op;

    printf("Qual jogador ira colocar na mesa?\n");
    scanf_s("%d", &op);

    return op;
}

int pecaDescartada() {
    
    int op;

    printf("Qual peca?\n");
    scanf_s("%d", &op);

    return op;
}