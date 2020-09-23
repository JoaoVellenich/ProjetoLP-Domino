#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoController.h"

void executarJogo() {

    Tipo_pecas pc;
    Tipo_Jogadores Jogadores;
    
    pc = criarPecas();

    int op, players;

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            players = menuIniciarJogo();
            Jogadores = maoJogador(pc);
            imprimirMao(Jogadores);
            pc = arrumarPc(Jogadores, pc);
            break;
        case 2:
            imprimirPecasOrganizadas(pc);
            break;
        case 3:
            pc = embaralharPecas(pc);
            break;
        case 4:
            imprimirPecas(pc);
            break;
        default:
            break;
        }
    } while (op != 5);

}