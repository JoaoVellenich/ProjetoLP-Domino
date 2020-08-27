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

Tipo_pecas criarPecas(Tipo_pecas pc);
Tipo_pecas embaralharPecas(Tipo_pecas pc);
void imprimirPecasOrganizadas(Tipo_pecas pc);
void imprimirPecas(Tipo_pecas pc);

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

void imprimirPecasOrganizadas(Tipo_pecas pc){
    for(int j = 0;j<28;j++){
            if(pc.pecas[j].face2==6){
                printf("[%d|%d]\n",pc.pecas[j].face1, pc.pecas[j].face2);
            }else{
                printf("[%d|%d]",pc.pecas[j].face1, pc.pecas[j].face2);
            }
        }
}

void imprimirPecas(Tipo_pecas pc){
    for (int i = 0; i < N; i++)
    {
        printf("[%d|%d]\n",pc.pecas[i].face1,pc.pecas[i].face2 );
    }
}

