// ESTRUTURA Q SE ENCARREGA DE LER AS COORDENADAS
typedef struct Coordenada
{
    int x,y, passou;
}Coordenada;

// CADA BLOCO OU POSICAO DA MATRIZ
typedef struct Item
{
    /* DECLARACAO DE DUAS VARIAVEIS DO TIPO COORDENADA, PAI FUNCIONA COMO UM ELO DE LIGACAO
    ENTRE A POSICAO VISITADA E APOSICAO ACTUAL
    */
    Coordenada coordenada, pai;
    char dado;
} Item;

typedef struct Labirinto
{
    // TAMANHO E DO TIPO COORDENADA E GUARDA O TAMANHO DA MATRIZ
    Coordenada tamanho;
    Coordenada entrada, saida;
}Labirinto;

typedef struct Lista
{
    Item item;
    struct Lista *proximo;
}Lista;

typedef struct Fila
{
    int tamanho;
    Lista *inicio;
    Lista *fim;
}Fila;



Fila *criarFila();
int filaVazia(Fila *fila);
void InserirElementoNaFila(Fila *fila, Item valor);
struct Item desenfileirar(Fila *fila);

