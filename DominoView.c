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
        printf("\n(1) Distribuir Pe�as\n");
        printf("(2) Mostrar Mesa\n");
        printf("(3) Mostrar Mao\n");
        printf("(4) Comprar Pe�as\n");
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

    printf("Qual a posicao?\n(1) Antes\n(2) Depois\n");
    scanf_s("%d", &op);

    return op;
}

void imprimirErro() {
    printf("ERRO LOCAL INVALIDO");
}

void mostrarRegras() {
    printf("As  regras  do  jogo  s�o  bem  simples:  cada  jogador  pega  sete  pe�as  e  pode  comprar sempre que precisar de uma pe�a para poder jogar e quantas vezes for necess�rio. D�-se in�cio ao jogo o jogador que tirar a pedra �seis-seis�. Caso ningu�m tenha o tirado, inicia-se o jogador que tiver a pe�a com os n�meros repetidos mais altos, ou seja, �cinco-cinco�, �quatro-quatro�, e assim  sucessivamente.  O  jogo  acontece  no  sentido  anti-hor�rio  e  os  jogadores  devem  colocar pe�as que tenham os mesmos n�meros das pe�as que se encontram na ponta do jogo. O jogador que  come�a  a  partida  leva  vantagem.  Este  �  um  conceito  importante  para  a  estrat�gia  do domin�, pois o jogador que come�a, normalmente, � o que leva a vantagem durante a partida.\n\nCada   jogador,   no   seu   turno,   deve   colocar   uma   das   suas   pe�as   em   uma   das   2 extremidades  abertas,  de  forma  que  os  pontos  de  um  dos  lados  coincida  com  os  pontos  da extremidade onde est� sendo colocada. As dobradas s�o colocadas de maneira transversal para facilitar sua localiza��o. Quando o jogador coloca sua pe�a sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.\n\nSe  um  jogador  n�o  puder  jogar,  dever�  �comprar�  do  monte  tantas  pe�as  como  forem necess�rias. Se n�o houver pe�as no monte, passar� o turno ao seguinte jogador.\n\n");
}

void mostrarVencedor() {
    printf("O grande vencedor � o jogador: %d", vverificarVencedor());
}