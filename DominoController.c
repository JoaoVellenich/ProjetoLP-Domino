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
    int newGame, vez;

    pc = embaralharPecas(pc);

    Jogadores = maoJogador(pc);
    pc = arrumarPc(pc);

    int primeiroDescarte = primeiraPeca(Jogadores);
    vez = retornarPrimeioJogador();

    mesa = irMesa(mesa, Jogadores, vez, primeiroDescarte, 1);
    Jogadores = descartePecas(Jogadores, vez, primeiroDescarte);

    do
    {
        op = menu();

        switch (op)
        {
        case 1://iniciar jogo

            newGame = novoJogo();

            if (newGame == 1)
            {
                pc = criarPecas();
                mesa = criarMesa();

                pc = embaralharPecas(pc);

                Jogadores = maoJogador(pc);
                pc = arrumarPc(pc);

                int primeiroDescarte = primeiraPeca(Jogadores);
                vez = retornarPrimeioJogador();

                mesa = irMesa(mesa, Jogadores, vez, primeiroDescarte, 1);
                Jogadores = descartePecas(Jogadores, vez, primeiroDescarte);
            }

            do
            {
                imprimirDetalhes();
                desenharMesa(mesa); //desenha a mesa
                imprimirDetalhes();
                imprimirMao(Jogadores, vez); //imprime a mao do jogador
                imprimirDetalhes();

                opMenuInGame = menuInGame();
    
                switch (opMenuInGame)
                {
                case 1://Proximo Jogador
                    vez = proximoPlayer(vez);
                    break;
                case 2://Colocar na Mesa
                    opColocarNaMesa = pecaDescartada(); //seleciona a peca
                    opPos = posPecaNaMesa(); //Posicao da peca na mesa
                    mesa = irMesa(mesa, Jogadores, vez, opColocarNaMesa, opPos); //coloca a peca no array mesa
                    Jogadores = descartePecas(Jogadores, vez, opColocarNaMesa); //arruma o array de jogador
                    break;
                case 3://Comprar Pecas
                    Jogadores = comprarPecas(Jogadores, pc, vez);
                    pc = arrumarPc(pc);
                    break;
                default:
                    break;
                }
                if (vverificarVencedor() == 1 || vverificarVencedor() == 2)
                {
                    mostrarVencedor();
                    break;
                }
            } while (opMenuInGame != 4);
            
            break;
        case 2://Jogar contra o Computador
            newGame = novoJogo();
            
            if (newGame == 1)
            {
                pc = criarPecas();
                mesa = criarMesa();

                pc = embaralharPecas(pc);

                Jogadores = maoJogador(pc);
                pc = arrumarPc(pc);

                int primeiroDescarte = primeiraPeca(Jogadores);
                vez = retornarPrimeioJogador();

                mesa = irMesa(mesa, Jogadores, vez, primeiroDescarte, 1);
                Jogadores = descartePecas(Jogadores, vez, primeiroDescarte);
            }

            do
            {

                if (vez == 2)
                {
                    opMenuInGame = 1;
                }else{
                    imprimirDetalhes();
                    desenharMesa(mesa); //desenha a mesa
                    imprimirDetalhes();
                    imprimirMao(Jogadores, 1); //imprime a mao do jogador
                    imprimirDetalhes();

                    opMenuInGame = menuInGame();
                }
    
                switch (opMenuInGame)
                {
                case 1://Proximo Jogador
                    mesa = jogadaComputador(Jogadores, mesa);
                    Jogadores = retornarComputador();
                    vez = proximoPlayer(vez);
                    break;
                case 2://Colocar na Mesa
                    opColocarNaMesa = pecaDescartada(); //seleciona a peca
                    opPos = posPecaNaMesa(); //Posicao da peca na mesa
                    mesa = irMesa(mesa, Jogadores, 1, opColocarNaMesa, opPos); //coloca a peca no array mesa
                    Jogadores = descartePecas(Jogadores, 1, opColocarNaMesa); //arruma o array de jogador
                    break;
                case 3://Comprar Pecas
                    Jogadores = comprarPecas(Jogadores, pc, 1);
                    pc = arrumarPc(pc);
                    break;
                default:
                    break;
                }
                if (vverificarVencedor() == 1 || vverificarVencedor() == 2)
                {
                    mostrarVencedor();
                    break;
                }
            } while (opMenuInGame != 4);

            break;
        case 3://carregar jogo
            saveGame(vez, pc, mesa, Jogadores);
            saveStatus();
            break;
        case 4://continuar jogo
            carregarJogo();
            vez = retornarVez();
            pc = retornarPecas();
            mesa = retornarMesa();
            Jogadores = retornarJogadores();
            //imprimirPecas(mesa);
            break;
        case 5://mostrar regras
            mostrarRegras();
            break;
        default://sair
            break;
        }
    } while (op != 5);

}