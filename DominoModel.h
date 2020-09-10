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

Tipo_pecas criarPecas(Tipo_pecas pc);
Tipo_pecas embaralharPecas(Tipo_pecas pc);