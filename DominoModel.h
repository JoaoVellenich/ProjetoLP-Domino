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

typedef struct mao 
{
    Tipo_Domino pecas[7];
}Tipo_mao;

typedef struct jogadores {
    Tipo_mao jogadores[2];
}Tipo_Jogadores;

Tipo_pecas criarPecas();
Tipo_pecas embaralharPecas(Tipo_pecas pc);
Tipo_Jogadores maoJogador(Tipo_pecas pc);
Tipo_pecas arrumarPc(Tipo_Jogadores Jogadores, Tipo_pecas pc);