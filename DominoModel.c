#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoModel.h"

Tipo_pecas criarPecas(Tipo_pecas pc){

    int count = 0;

    for (int i = 0; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            if(count < 28){
                pc.pecas[count].face1 = i;
                pc.pecas[count].face2 = j;
            }
            count++;
        }
    }
    return pc;
}

Tipo_pecas embaralharPecas(Tipo_pecas pc){
    srand(time(NULL));//inicializa a funcao rand() com um valor semente
    int numRep[N];//armazena os numeros repetidos
    int numRand;//armazena o numero aleatorio
    int faceAnt1, faceAnt2;

    //preenche o array com o numero 0
    for(int i = 0; i < N; i++){
        numRep[i]=0;
    }
    //embaralha as pecas trocando os valores das faces com pecas aleatorias 
    for(int i=0;i<N;i++){
        do{
        numRand = rand()%N;//pega um numero aleatorio de 0 a 27
        }while (numRep[numRand] == 1);//esse processo se repete enquanto o numero for repetido

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