#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "DominoController.h"

void executarJogo() {

    Tipo_pecas pc;
    Tipo_Mesa mesa;
    Tipo_Jogadores Jogadores;
    
    pc = criarPecas();
    mesa = criarMesa();

    int op, players;
    int opMenuInGame = 0;
    int opComprar, opMesa, opColocarNaMesa, opPos;

    do
    {
        op = menu();

        switch (op)
        {
        case 1://iniciar jogo
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
                    opMesa = menuMesa(); //qual jogador ira colocar na mesa
                    imprimirMao(Jogadores, opMesa); //imprime a mao do jogador
                    desenharMesa(mesa); //desenha a mesa
                    opColocarNaMesa = pecaDescartada(); //seleciona a peca
                    opPos = posPecaNaMesa(); //Posicao da peca na mesa
                    mesa = irMesa(mesa, Jogadores, opMesa, opColocarNaMesa, opPos); //coloca a peca no array mesa
                    desenharMesa(mesa); //desenha a mesa
                    Jogadores = descartePecas(Jogadores, opMesa, opColocarNaMesa); //arruma o array de jogador
                    imprimirMao(Jogadores, opMesa); //imprime a mao
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
                        imprimirMao(Jogadores, opComprar);
                    } while (opComprar != 3);
                    break;
                default:
                    break;
                }
                if (vverificarVencedor() == 1 || vverificarVencedor() == 2)
                {
                    mostrarVencedor;
                    break;
                }
            } while (opMenuInGame != 5);
            
            break;
        case 2://carregar jogo
            imprimirPecasOrganizadas(pc);
            break;
        case 3://continuar jogo
            pc = embaralharPecas(pc);
            break;
        case 4://mostrar regras
            mostrarRegras();
            break;
        default://sair
            break;
        }
    } while (op != 5);

}