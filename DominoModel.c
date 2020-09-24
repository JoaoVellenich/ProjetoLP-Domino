#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoModel.h"

int quantidadeCompradaJogado1, quantidadeCompradaJogado2;
int quantidadeMesa = 0;

Tipo_pecas criarPecas() {
    Tipo_pecas pc;

    int count = 0;

    for (int i = 0; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            if (count < 28) {
                pc.pecas[count].face1 = i;
                pc.pecas[count].face2 = j;
            }
            count++;
        }
    }
    return pc;
}

Tipo_pecas criarMesa() {
    Tipo_pecas mesa;

    for (int i = 0; i < 28; i++)
    {
        mesa.pecas[i].face1 = -1;
        mesa.pecas[i].face2 = -1;
    }

    return mesa;
}

Tipo_pecas embaralharPecas(Tipo_pecas pc) {
    srand(time(NULL));//inicializa a funcao rand() com um valor semente
    int numRep[N];//armazena os numeros repetidos
    int numRand;//armazena o numero aleatorio
    int faceAnt1, faceAnt2;

    //preenche o array com o numero 0
    for (int i = 0; i < N; i++) {
        numRep[i] = 0;
    }
    //embaralha as pecas trocando os valores das faces com pecas aleatorias 
    for (int i = 0; i < N; i++) {
        do {
            numRand = rand() % N;//pega um numero aleatorio de 0 a 27
        } while (numRep[numRand] == 1);//esse processo se repete enquanto o numero for repetido

        faceAnt1 = pc.pecas[i].face1;
        faceAnt2 = pc.pecas[i].face2;

        pc.pecas[i].face1 = pc.pecas[numRand].face1;
        pc.pecas[i].face2 = pc.pecas[numRand].face2;

        pc.pecas[numRand].face1 = faceAnt1;
        pc.pecas[numRand].face2 = faceAnt2;
        numRep[numRand] = 1;
    }

    return pc;
}

Tipo_Jogadores maoJogador(Tipo_pecas pc) {
    Tipo_Jogadores player;

    int i,j;

    for (i = 0; i < 7; i++)
    {
        player.jogadores[0].pecas[i].face1 = pc.pecas[i].face1;
        player.jogadores[0].pecas[i].face2 = pc.pecas[i].face2;
    }
    
    for (j = 0; j < 7; j++)
    {
        player.jogadores[1].pecas[j].face1 = pc.pecas[j + 7].face1;
        player.jogadores[1].pecas[j].face2 = pc.pecas[j + 7].face2;
    }

    quantidadeCompradaJogado1 = i;
    quantidadeCompradaJogado2 = j;

    return player;
}

Tipo_pecas arrumarPc(Tipo_pecas pc) {
    int total = quantidadeCompradaJogado1 + quantidadeCompradaJogado2;

    for (int i = 0; i < total; i++)
    {
        pc.pecas[i].face1 = -1;
        pc.pecas[i].face2 = -1;
    }

    return pc;
}

Tipo_Jogadores comprarPecas(Tipo_Jogadores player, Tipo_pecas pc, int num) {

    int total = quantidadeCompradaJogado1 + quantidadeCompradaJogado2;
    if (num == 1)
    {
        player.jogadores[0].pecas[quantidadeCompradaJogado1].face1 = pc.pecas[total].face1;
        player.jogadores[0].pecas[quantidadeCompradaJogado1].face2 = pc.pecas[total].face2;
        pc.pecas[total].face1 = -1;
        pc.pecas[total].face2 = -1;
        quantidadeCompradaJogado1++;
    }
    else if (num == 2)
    {
        player.jogadores[1].pecas[quantidadeCompradaJogado2].face1 = pc.pecas[total].face1;
        player.jogadores[1].pecas[quantidadeCompradaJogado2].face2 = pc.pecas[total].face2;
        pc.pecas[total].face1 = -1;
        pc.pecas[total].face2 = -1;
        quantidadeCompradaJogado2++;
    }
    
    return player;
}

Tipo_pecas irMesa(Tipo_pecas pecasDesenhada ,Tipo_Jogadores player, int jogador, int numPeca, int pos) {

    if (pecasDesenhada.pecas[0].face1 == -1)
    {
        pecasDesenhada.pecas[quantidadeMesa].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
        pecasDesenhada.pecas[quantidadeMesa].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
        quantidadeMesa++;
    }
    else if (pos == 1)
    {
        if (pecasDesenhada.pecas[quantidadeMesa -1].face1 == player.jogadores[jogador - 1].pecas[numPeca - 1].face2)
        {
            pecasDesenhada.pecas[quantidadeMesa].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
            pecasDesenhada.pecas[quantidadeMesa].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
            quantidadeMesa++;
        }
        else
        {
            imprimirErro();
        }
    }
    else if (pos == 2)
    {
        if (pecasDesenhada.pecas[quantidadeMesa -1].face2 == player.jogadores[jogador - 1].pecas[numPeca - 1].face1)
        {
            pecasDesenhada.pecas[quantidadeMesa].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
            pecasDesenhada.pecas[quantidadeMesa].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
            quantidadeMesa++;
        }
        else
        {
            imprimirErro();
        }

    }
    
    return pecasDesenhada;

}



int retornarQtdJogador1() {
    return quantidadeCompradaJogado1;
}
int retornarQtdJogador2() {
    return quantidadeCompradaJogado2;
}
int retornarQtdMesa() {
    return quantidadeMesa;
}



