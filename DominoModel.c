#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoModel.h"

int quantidadeCompradaJogado1, quantidadeCompradaJogado2;
int quantidadeAntes = 0;
int quantidadeDepois = 0;

int pecaNaMao[2] = { 0, 0};


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

Tipo_Mesa criarMesa() {
    Tipo_Mesa mesa;

    for (int i = 0; i < 56; i++)
    {
        mesa.mesa[i].face1 = -1;
        mesa.mesa[i].face2 = -1;
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

    pecaNaMao[0] = 7;
    pecaNaMao[1] = 7;

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

        pecaNaMao[0] ++;
    }
    else if (num == 2)
    {
        player.jogadores[1].pecas[quantidadeCompradaJogado2].face1 = pc.pecas[total].face1;
        player.jogadores[1].pecas[quantidadeCompradaJogado2].face2 = pc.pecas[total].face2;
        pc.pecas[total].face1 = -1;
        pc.pecas[total].face2 = -1;
        quantidadeCompradaJogado2++;

        pecaNaMao[1] ++;
    }
    
    return player;
}

Tipo_Mesa irMesa(Tipo_Mesa pecasDesenhada ,Tipo_Jogadores player, int jogador, int numPeca, int pos) {

    if (pecasDesenhada.mesa[28].face1 == -1)
    {
        pecasDesenhada.mesa[28].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
        pecasDesenhada.mesa[28].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
        
        pecaNaMao[jogador - 1] --;
    }
    else if (pos == 1)
    {
        if (pecasDesenhada.mesa[28 - quantidadeAntes].face1 == player.jogadores[jogador - 1].pecas[numPeca - 1].face2)
        {
            pecasDesenhada.mesa[27 - quantidadeAntes].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
            pecasDesenhada.mesa[27 - quantidadeAntes].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;

            pecaNaMao[jogador - 1] --;

            quantidadeAntes++;
        }
        else
        {
            imprimirErro();
        }
    }
    else if (pos == 2)
    {
        if (pecasDesenhada.mesa[quantidadeDepois + 28].face2 == player.jogadores[jogador - 1].pecas[numPeca - 1].face1)
        {
            pecasDesenhada.mesa[quantidadeDepois + 29].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;
            pecasDesenhada.mesa[quantidadeDepois + 29].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;

            pecaNaMao[jogador - 1] --;

            quantidadeDepois ++;
        }
        else
        {
            imprimirErro();
        }

    }
    
    return pecasDesenhada;

}

Tipo_Jogadores descartePecas(Tipo_Jogadores Player, int numPlayer, int peca) {

    Player.jogadores[numPlayer -1].pecas[peca -1].face1 = -1;
    Player.jogadores[numPlayer -1].pecas[peca -1].face2 = -1;

    return Player;

}

int vverificarVencedor() {
    
    int vencedor = 0;

    if (pecaNaMao[0] == 0)
    {
        vencedor = 1;
    }
    else if (pecaNaMao[1] == 0)
    {
        vencedor = 2;
    }

    return vencedor;
}

int retornarQtdJogador1() {
    return quantidadeCompradaJogado1;
}
int retornarQtdJogador2() {
    return quantidadeCompradaJogado2;
}




