#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Fila.h"
#include "Estilo.h"

FILE *criarFicheiro();
void buscaEmLargura(Labirinto labirinto);
void calcularCaminho(Fila *fila);

Item** lerLabirinto(Labirinto *labirinto);

int estaNaSaida(int posicaoActualx, int posicaoActualy, Coordenada saida);

int main()
{

    int op = 0, escolha = 0,i,j;
    Fila *fila,*filaComCaminhos;
    fila = criarFila(fila);
    Labirinto labirinto;
    Item **lab = lerLabirinto(&labirinto);


    do{
        estilo();
        scanf("%d",&escolha);
        system("cls");
        switch(escolha)
        {
            case 0:
                estilo();
            case 1:
                estiloLabirintoPercorrido();
                //calcularCaminho(fila);
                buscaEmLargura(labirinto);
                escolha = 0;
                //imprimir(fila);
                break;
            case 2:
                estiloLabirinto();
                for (i = 0; i < labirinto.tamanho.x; ++i) {
                    for (j = 0; j < labirinto.tamanho.y; ++j)
                    {
                        printf("%c", lab[i][j].dado);
                    }
                    printf("\n");
                }

                printf("\nLabirinto percorrido\n\n");

                for (i = 0; i < labirinto.tamanho.x; ++i) {
                    for (j = 0; j < labirinto.tamanho.y; ++j)
                    {
                        if(lab[i][j].dado == ' ')
                            printf("X");
                        else
                            printf("%c", lab[i][j].dado);
                    }
                    printf("\n");
                }
                break;
            default:
                cores(4);
                printf("\n\n\n\n\t\t\t\t\t\toperacao invalida\n");

                break;

        }
        cores(6);
        printf("\n\n\t\t\t\t\t1 -> Voltar ao menu || 0 -> Sair do programa\n");
        printf("\n\t\t\t\t\t\t\t");
        scanf("%d",&op);

        if((op != 0)&&(op != 1))
        {
            do{

                system("cls");
                cores(4);
                printf("\n\n\n\t\t\t\t\t\t\tERRO\n");
                printf("\n\n\n\t\t\t\t\t\tInsira um numero valido\n");
                cores(6);
                printf("\n\n\t\t\t\t\t1 -> Voltar ao menu || 0 -> Sair do programa\n");
                printf("\n\t\t\t\t\t\t\t");
                scanf("%d",&op);
            }while((op != 0)&&(op != 1));
        }
        system("cls");


    }while(op != 0);


    return 0;
}


//Criação do ficheiro
FILE *criarFicheiro()
{
    FILE *ficheiro = fopen("labirinto.txt","r");

    if(ficheiro == NULL)
        return NULL;
    return ficheiro;
}
//função criada para ler o labirinto do ficheiro
Item** lerLabirinto(Labirinto *labirinto)
{
    int i,j;
    FILE *ficheiro = criarFicheiro();


    if(ficheiro == NULL)
    {
        printf("Erro a ler o ficheiro");

        exit(1);
    }

    fscanf(ficheiro,"%d %d %d %d %d %d",&labirinto->tamanho.x,&labirinto->tamanho.y,
           &labirinto->entrada.x,&labirinto->entrada.y,
           &labirinto->saida.x,&labirinto->saida.y);

    Item **vector;

    vector = malloc(labirinto->tamanho.x * sizeof(Item *));
    for (i = 0; i < labirinto->tamanho.x; i++) {
        vector[i] = malloc(labirinto->tamanho.y * sizeof(Item ));
    }

    for(i = 0; i<labirinto->tamanho.x; i++)
    {
        for(j = 0; j < labirinto->tamanho.y; j++)
        {
            Item valor;
            fscanf(ficheiro,"%c",&valor.dado);
            if(valor.dado != '\n')
            {
                valor.coordenada.x = i;
                valor.coordenada.y = j;
                valor.coordenada.passou = 0;
                vector[i][j] = valor;
            } else
                j--;
        }
    }


    return vector;
}


//FUNCAO CALCULAR CAMINHO
void calcularCaminho(Fila *fila)
{

    Lista *cabeca = fila->inicio;
    int i;
    for(i=0;i<fila->tamanho;i++)
    {
        if(cabeca->item.dado == ' ')
            cabeca->item.dado = 'X';
        cabeca = cabeca->proximo;
    }
}

int estaNaSaida(int posicaoActualx, int posicaoActualy, Coordenada saida) {
    return posicaoActualx == saida.x && posicaoActualy == saida.y-1;
}

// Função para encontrar o menor camino usamos o algoritimo de busca em largura
void buscaEmLargura(Labirinto labirinto) {
    int i, j;
    Fila *fila;
    Item **lab = lerLabirinto(&labirinto);
    fila = criarFila();

    InserirElementoNaFila(fila, lab[labirinto.entrada.x][labirinto.entrada.y]);
    Item item;
    int terminar = 0;
    int px, py;
// ALGORITIMO DE BUSCA EM LARGURAR E SO O WHILE.
    while (!filaVazia(fila)) {
        item = desenfileirar(fila);
        px = item.coordenada.x;
        py = item.coordenada.y;
        if (!item.coordenada.passou) {
            if (estaNaSaida(px, py, labirinto.saida)) {
                terminar = 1;
                break;
            } else {
                // CIMA
                if (lab[px + 1][py].dado == ' ' || estaNaSaida(px + 1, py, labirinto.saida)) {
                    lab[px + 1][py].pai = item.coordenada;
                    InserirElementoNaFila(fila, lab[px + 1][py]);
                }
                // BAIXO
                if (lab[px - 1][py].dado == ' ' || estaNaSaida(px - 1, py, labirinto.saida)) {
                    lab[px - 1][py].pai = item.coordenada;
                    InserirElementoNaFila(fila, lab[px - 1][py]);
                }
                if (lab[px][py + 1].dado == ' ' || estaNaSaida(px, py + 1, labirinto.saida)) {
                    lab[px][py + 1].pai = item.coordenada;
                    InserirElementoNaFila(fila, lab[px][py + 1]);
                }
                if (lab[px][py - 1].dado == ' ' || estaNaSaida(px, py - 1, labirinto.saida)) {
                    lab[px][py - 1].pai = item.coordenada;
                    InserirElementoNaFila(fila, lab[px][py - 1]);
                }

            }
            lab[px][py].coordenada.passou = 1;
            lab[px][py].dado = 'A';
        }
    }

    Coordenada parente = item.pai;

// MARCA O CAMINHO
     for (i = labirinto.tamanho.x-1; i >= 0; i--)
    {    for (j = labirinto.tamanho.y-1; j >= 0; j--) {

            if (parente.x == lab[i][j].coordenada.x && parente.y == lab[i][j].coordenada.y)
            {
                lab[i][j].dado = 'X';
                parente = lab[i][j].pai;
            }
        }
    }

// PRINTAR O CAMINHO
    for (i = 0; i < labirinto.tamanho.x; i++)
    {    for (j = 0; j < labirinto.tamanho.y; j++)
        {
                if(lab[i][j].dado == 'A')
                    printf(" ");
                else
                    printf("%c", lab[i][j].dado);
        }
        printf("\n");
    }


    if (terminar == 1){
        printf("\nSolucao\n");

    }
    else
        printf("\nNao tem solucao \n");
}


