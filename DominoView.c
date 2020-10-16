#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoView.h"
#include "DominoModel.h"

//DELETAR INUTIL
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

//DELETAR INUTIL
void imprimirPecas(Tipo_Mesa pc) {
    for (int i = 0; i < 56; i++)
    {
        printf("[%d|%d]\n", pc.mesa[i].face1, pc.mesa[i].face2);
    }
}

int menu() {

    int op;
    do
    {
        printf("(1) Jogar\n");
        printf("(2) Salvar Jogo\n");
        printf("(3) Carregar Jogo\n");
        printf("(4) Regras\n");
        printf("(5) Sair\n");
        printf("Selecione sua opcao: \n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 5);

    return op;
}

int menuIniciarJogo() {
    
    int op;

    do
    {
        printf("INICIAR JOGO:\n\nQuantos jogadores?\n");
        printf("1 Jogador\n2 Jogadores\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 2);

    return op;
}

void imprimirMao(Tipo_Jogadores mao, int op) {

    if (op == 1)
    {
        printf("Mao Jogador 1:\n ");
        for (int i = 0; i < retornarQtdJogador1(); i++)
        {   
            if (mao.jogadores[0].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[0].pecas[i].face1, mao.jogadores[0].pecas[i].face2);
            }
           
        }
    }
    else if (op == 2)
    {
        printf("Mao Jogador 2:\n ");
        for (int i = 0; i < retornarQtdJogador2(); i++)
        {
            if (mao.jogadores[1].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[1].pecas[i].face1, mao.jogadores[1].pecas[i].face2);
            }
        }
    }
    
}

//DELETAR INUTIL
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
        printf("\n(1) Proximo Player\n");
        printf("(2) Colocar Peca Na Mesa\n");
        printf("(3) Comprar Pecas\n");
        printf("(4) Finalizar o Jogo\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 4);

    return op;
}

//DELETAR INUTIL
int menuComprarPecas() {
    int op = 0;

    do
    {
        printf("Qual jogador ira comprar?\n(1) Jogador 1\n(2) Jogador 2\n(3)Deixar de Comprar\n");
        scanf_s("%d", &op);
    } while (op < 0 || op > 3);

    return op;
}

void desenharMesa(Tipo_Mesa pecasDesenhada) {

    printf("MESA:\n");

    for (int i = 0; i < 56; i++)
    {
        if (pecasDesenhada.mesa[i].face1 != -1)
        {
            printf("[%d|%d]", pecasDesenhada.mesa[i].face1, pecasDesenhada.mesa[i].face2);
        }
    }
    
}

//DELETAR INUTIL
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

int posPecaNaMesa() {
    int op;

    printf("Qual a posicao?\n(1) Antes\n(2) Depois\n");
    scanf_s("%d", &op);

    return op;
}

int novoJogo() {
    int op;

    printf("\n(1) Novo Jogo\n(2) Continuar\n");
    scanf("%d", &op);

    return op;
}

void imprimirErro() {
    printf("ERRO: POSICAO INVALIDA\n");
}

void mostrarRegras() {
    printf("As regras do jogo sao bem simples: cada jogador pega sete pecas e pode comprar sempre que precisar de uma peca para poder jogar e quantas vezes for necessario. Da inicio ao jogo o jogador que tirar a pedra seis-seis. Caso nenhum jogador a possua, inicia o jogo aquele que tiver a peca com os numeros repetidos mais altos, ou seja, cinco-cinco, quatro-quatro, etc. O jogo acontece no sentido anti-horario e os jogadores devem colocar pecas que tenham os mesmos numeros das pecas que se encontram na ponta do jogo. O jogador que comeca a partida leva vantagem. Este e um conceito importante para a estrategia do domino, pois o jogador que comeca, normalmente, e o que leva a vantagem durante a partida.\n\nCada jogador, no seu turno, deve colocar uma das suas pecas em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincida com os pontos da extremidade onde esta sendo colocada. As dobradas sao colocadas de maneira transversal para facilitar sua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.\n\nSe um jogador nao puder jogar, devera comprar do monte tantas pecas  como  forem necessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador.\n\n");
}

void mostrarVencedor() {
    printf("O grande vencedor e o jogador: %d\n", vverificarVencedor());
}

void imprimirDetalhes() {
    printf("\n==========\n");
}

void saveStatus() {
    printf("\nSave Game Realizado\n");
}

void erroLoadGame() {
    printf("\nERRO ARQUIVO NAO ENCONTRADO\n");
}