#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoView.h"
#include "DominoModel.h"


int quantidadeCompradaJogado1, quantidadeCompradaJogado2;
int quantidadeAntes = 0;
int quantidadeDepois = 0;

int pecaNaMao[2] = { 0, 0};

int primeiroJogador = 0;

int vez_Save;
Tipo_pecas pc_Save;
Tipo_Mesa mesa_Save;
Tipo_Jogadores jogadores_Save;


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
        else if (pecasDesenhada.mesa[28 - quantidadeAntes].face1 == player.jogadores[jogador - 1].pecas[numPeca - 1].face1)
        {
            pecasDesenhada.mesa[27 - quantidadeAntes].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
            pecasDesenhada.mesa[27 - quantidadeAntes].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;

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
        else if (pecasDesenhada.mesa[quantidadeDepois + 28].face2 == player.jogadores[jogador - 1].pecas[numPeca - 1].face2)
        {
            pecasDesenhada.mesa[quantidadeDepois + 29].face1 = player.jogadores[jogador - 1].pecas[numPeca - 1].face2;
            pecasDesenhada.mesa[quantidadeDepois + 29].face2 = player.jogadores[jogador - 1].pecas[numPeca - 1].face1;

            pecaNaMao[jogador - 1] --;

            quantidadeDepois++;
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

int primeiraPeca(Tipo_Jogadores Player) {
    int maiorJogador1 = -1;
    int maiorJogador2 = -1;

    int numPeca1 = -1;
    int numPeca2 = -1;

    int primeiraPeca = -1;

    for (int i = 0; i < 7; i++)
    {
        if (Player.jogadores[0].pecas[i].face1 == Player.jogadores[0].pecas[i].face2)
        {
            if (Player.jogadores[0].pecas[i].face1 > maiorJogador1)
            {
                maiorJogador1 = Player.jogadores[0].pecas[i].face1;
                numPeca1 = i+1;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        if (Player.jogadores[1].pecas[i].face1 == Player.jogadores[1].pecas[i].face2)
        {
            if (Player.jogadores[1].pecas[i].face1 > maiorJogador2)
            {
                maiorJogador2 = Player.jogadores[1].pecas[i].face1;
                numPeca2 = i+1;
            }
        }
    }

    if (maiorJogador1 > maiorJogador2)
    {
        primeiroJogador = 1;
        primeiraPeca = numPeca1;
    }
    else if (maiorJogador2 > maiorJogador1)
    {
        primeiroJogador = 2;
        primeiraPeca = numPeca2;
    }

    return primeiraPeca;
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

int proximoPlayer(int vez) {
    if (vez == 1)
    {
        vez = 2;
    }
    else if (vez == 2)
    {
        vez = 1;
    }

    return vez;
}



void saveGame(int vez, Tipo_pecas pc, Tipo_Mesa mesa, Tipo_Jogadores Jogadores) {

    FILE* Arquivo_Player = fopen("Arquivo_Player.bin", "w+b");
    FILE* Arquivo_Mesa = fopen("Arquivo_Mesa.bin", "w+b");

    fwrite(&vez, sizeof(int), 1, Arquivo_Player);

    for (int i = 0; i < 28; i++)
    {
        fwrite(&pc.pecas[i].face1, sizeof(Tipo_pecas), 1, Arquivo_Player);
        fwrite(&pc.pecas[i].face2, sizeof(Tipo_pecas), 1, Arquivo_Player);
    }
    
    for (int i = 0; i < 56; i++)
    {
        fwrite(&mesa.mesa[i].face1, sizeof(Tipo_Mesa), 1, Arquivo_Mesa);
        fwrite(&mesa.mesa[i].face2, sizeof(Tipo_Mesa), 1, Arquivo_Mesa);
    }
    
    for (int i = 0; i < 28; i++)
    {
        fwrite(&Jogadores.jogadores[0].pecas[i].face1, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
        fwrite(&Jogadores.jogadores[0].pecas[i].face2, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
        fwrite(&Jogadores.jogadores[1].pecas[i].face1, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
        fwrite(&Jogadores.jogadores[1].pecas[i].face2, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
    }

    fclose(Arquivo_Player);
    fclose(Arquivo_Mesa);

}

void carregarJogo() {

    FILE* Arquivo_Player = fopen("Arquivo_Player.bin", "rb");
    FILE* Arquivo_Mesa = fopen("Arquivo_Mesa.bin", "rb");

    if (Arquivo_Player != NULL)
    {
        fread(&vez_Save, sizeof(int), 1, Arquivo_Player);

        for (int i = 0; i < 28; i++)
        {
            fread(&pc_Save.pecas[i].face1, sizeof(Tipo_pecas), 1, Arquivo_Player);
            fread(&pc_Save.pecas[i].face2, sizeof(Tipo_pecas), 1, Arquivo_Player);
        }

        for (int i = 0; i < 28; i++)
        {
            fread(&jogadores_Save.jogadores[0].pecas[i].face1, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
            fread(&jogadores_Save.jogadores[0].pecas[i].face2, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
            fread(&jogadores_Save.jogadores[1].pecas[i].face1, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
            fread(&jogadores_Save.jogadores[1].pecas[i].face2, sizeof(Tipo_Jogadores), 1, Arquivo_Player);
        }
    }
    else
    {
         erroLoadGame();
    }

    if (Arquivo_Mesa != NULL){
        for (int i = 0; i < 56; i++)
        {
            fread(&mesa_Save.mesa[i].face1, sizeof(Tipo_Mesa), 1, Arquivo_Mesa);
            fread(&mesa_Save.mesa[i].face2, sizeof(Tipo_Mesa), 1, Arquivo_Mesa);
        }
    }
    else
    {
        erroLoadGame();
    }

    fclose(Arquivo_Player);
    fclose(Arquivo_Mesa);

    return 0;

}



int retornarQtdJogador1() {
    return quantidadeCompradaJogado1;
}
int retornarQtdJogador2() {
    return quantidadeCompradaJogado2;
}
int retornarPrimeioJogador() {
    return primeiroJogador;
}
int retornarVez() {
    return vez_Save;
}
Tipo_pecas retornarPecas() {
    return pc_Save;
}
Tipo_Mesa retornarMesa() {
    return mesa_Save;
}
Tipo_Jogadores retornarJogadores() {
    return jogadores_Save;
}