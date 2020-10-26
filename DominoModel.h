#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 28

typedef struct Faces
{
    int face1, face2;
}Tipo_Domino;

typedef struct Pecas
{
    Tipo_Domino pecas[N];
}Tipo_pecas;

typedef struct jogadores 
{
    Tipo_pecas jogadores[2];
}Tipo_Jogadores;

typedef struct mesa
{
    Tipo_Domino mesa[56];
}Tipo_Mesa;

Tipo_pecas criarPecas();
Tipo_Mesa criarMesa();
Tipo_pecas embaralharPecas(Tipo_pecas pc);
Tipo_Jogadores maoJogador(Tipo_pecas pc);
Tipo_pecas arrumarPc(Tipo_pecas pc);
Tipo_Jogadores comprarPecas(Tipo_Jogadores player, Tipo_pecas pc, int num);
Tipo_Mesa irMesa(Tipo_Mesa pecasDesenhada, Tipo_Jogadores player, int jogador, int numPeca, int pos);
Tipo_Jogadores descartePecas(Tipo_Jogadores Player, int numPlayer, int peca);
int primeiraPeca(Tipo_Jogadores Player);
Tipo_Mesa jogadaComputador(Tipo_Jogadores Player, Tipo_Mesa mesa);

void saveGame(int vez, Tipo_pecas pc, Tipo_Mesa mesa, Tipo_Jogadores Jogadores);
void carregarJogo();

int proximoPlayer(int vez);

int vverificarVencedor();
int retornarQtdJogador1();
int retornarQtdJogador2();
int retornarPrimeioJogador();

int retornarVez();
Tipo_pecas retornarPecas();
Tipo_Mesa retornarMesa();
Tipo_Jogadores retornarJogadores();
Tipo_Jogadores retornarComputador();

