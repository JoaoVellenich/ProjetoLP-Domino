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
            if (mao.jogadores[0].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[0].pecas[i].face1, mao.jogadores[0].pecas[i].face2);
            }
           
        }
    }
    else if (op == 2)
    {
        printf("\n\nMao Jogador 2:\n ");
        for (int i = 0; i < retornarQtdJogador2(); i++)
        {
            if (mao.jogadores[1].pecas[i].face1 != -1)
            {
                printf("(%d) [%d|%d] ", i+1, mao.jogadores[1].pecas[i].face1, mao.jogadores[1].pecas[i].face2);
            }
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
        printf("(5) Finalizar o Jogo\n");
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

void desenharMesa(Tipo_Mesa pecasDesenhada) {

    for (int i = 0; i < 56; i++)
    {
        if (pecasDesenhada.mesa[i].face1 != -1)
        {
            printf("[%d|%d]", pecasDesenhada.mesa[i].face1, pecasDesenhada.mesa[i].face2);
        }
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

int posPecaNaMesa() {
    int op;

    printf("Qual a posicao?\n(1) Antes\n (2) Depois\n");
    scanf_s("%d", &op);

    return op;
}

void imprimirErro() {
    printf("ERRO LOCAL INVALIDO");
}

void mostrarRegras() {
    printf("As  regras  do  jogo  são  bem  simples:  cada  jogador  pega  sete  peças  e  pode  comprarsempre que precisar de uma peça para poder jogar e quantas vezes for necessário. Dá-se inícioao jogo o jogador que tirar a pedra “seis-seis”. Caso ninguém tenha o tirado, inicia-se o jogadorque tiver a peça com os números repetidos mais altos, ou seja, “cinco-cinco”, “quatro-quatro”, eassim  sucessivamente.  O  jogo  acontece  no  sentido  anti-horário  e  os  jogadores  devem  colocarpeças que tenham os mesmos números das peças que se encontram na ponta do jogo. O jogadorque  começa  a  partida  leva  vantagem.  Este  é  um  conceito  importante  para  a  estratégia  dodominó, pois o jogador que começa, normalmente, é o que leva a vantagem durante a partida.\n\nCada   jogador,   no   seu   turno,   deve   colocar   uma   das   suas   peças   em   uma   das   2 extremidades  abertas,  de  forma  que  os  pontos  de  um  dos  lados  coincida  com  os  pontos  daextremidade onde está sendo colocada. As dobradas são colocadas de maneira transversal parafacilitar sua localização. Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba epassa-se ao seguinte jogador.\n\nSe  um  jogador  não  puder  jogar,  deverá  “comprar”  do  monte  tantas  peças  como  foremnecessárias. Se não houver peças no monte, passará o turno ao seguinte jogador.\n\n");
}

void mostrarVencedor() {
    printf("O grande vencedor é o jogador: %d", vverificarVencedor());
}