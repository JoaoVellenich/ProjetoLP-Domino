#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoController.h"

void executarJogo() {

    Tipo_pecas pc, colocadaMesa;
    Tipo_Jogadores Jogadores;
    
    pc = criarPecas();
    colocadaMesa = criarPecas();

    int op, players;
    int opMenuInGame = 0;
    int opComprar, opMesa, opColocarNaMesa;

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            players = menuIniciarJogo();
            pc = embaralharPecas(pc);
            do
            {
                opMenuInGame = menuInGame();
                switch (opMenuInGame)
                {
                case 1:
                    Jogadores = maoJogador(pc);
                    pc = arrumarPc(pc);
                    break;
                case 2:
                    opMesa = menuMesa();
                    imprimirMao(Jogadores, opMesa);
                    opColocarNaMesa = pecaDescartada();
                    colocadaMesa = irMesa(colocadaMesa, Jogadores, opMesa, opColocarNaMesa);
                    desenharMesa(colocadaMesa);
                    break;
                case 3:
                    opMesa = menuMesa();
                    imprimirMao(Jogadores, opMesa);
                    pc = arrumarPc(pc);
                    break;
                case 4:
                    do
                    {
                        opComprar = menuComprarPecas();
                        Jogadores = comprarPecas(Jogadores, pc, opComprar);
                    } while (opComprar != 3);
                    break;
                default:
                    break;
                }
            } while (opMenuInGame != 5);
            
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