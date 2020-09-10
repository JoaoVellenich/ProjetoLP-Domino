#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 28

typedef struct Domino
{
    int face1, face2;
}Tipo_Domino;

typedef struct Pecas
{
    Tipo_Domino pecas[N];
}Tipo_pecas;


int main(){
    Tipo_pecas pc;
    Tipo_pecas embaralhada;
    pc = criarPecas(pc);

    int op = 0;
    do
    {
        printf("(1) Organizar\n");
        printf("(2) Mostrar Organizado\n");
        printf("(3) Embaralhar\n");
        printf("(4) Mostrar Embaralhado\n");
        printf("(5) Sair\n");
        printf("Qula sua opcao? \n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            pc = criarPecas(pc);
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








