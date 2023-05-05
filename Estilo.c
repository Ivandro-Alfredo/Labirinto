#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Estilo.h"

void estilo()
{
    /*{
       azul = 1
       verde = 2
       vermelho = 4
       amarelo = 6
   }*/
    cores(6);
    printf("\n\n");
    printf("\t\t\t\t\t    ##   ## ####### ##   ## ##   ##\n");
    printf("\t\t\t\t\t    ### ###  ##   # ###  ## ##   ##\n");
    printf("\t\t\t\t\t    #######  ##     #### ## ##   ## \n");
    printf("\t\t\t\t\t    ## # ##  ####   ####### ##   ##\n");
    printf("\t\t\t\t\t    ##   ##  ##     ## #### ##   ##\n");
    printf("\t\t\t\t\t    ##   ##  ##   # ##  ### ##   ##\n");
    printf("\t\t\t\t\t    ### ### ####### ##   ##  #####\n\n");

    cores(2);
    printf("\t\t\t          L     AA  BBBB  III RRRR  III N   N TTTTTT  OOO\n");
    printf("\t\t\t          L    A  A B   B  I  R   R  I  NN  N   TT   O   O\n");
    printf("\t\t\t          L    AAAA BBBB   I  RRRR   I  N N N   TT   O   O\n");
    printf("\t\t\t          L    A  A B   B  I  R R    I  N  NN   TT   O   O\n");
    printf("\t\t\t          LLLL A  A BBBB  III R  RR III N   N   TT    OOO\n\n");

    cores(6);
    printf("\n\n\t\t\t    ||1 -> Ver menor caminho || 2 -> Ver Labirinto vazio e percorrido||\n");
    printf("\n\t\t\t\t\t\t\t   ");


}
void estiloLabirinto()
{
    cores(2);
    printf("\n\n");
    printf("\t\t\t\t\t\t +-+-+-+-+-+-+-+-+-+\n");
    printf("\t\t\t\t\t\t |L|A|B|I|R|I|N|T|O|\n");
    printf("\t\t\t\t\t\t +-+-+-+-+-+-+-+-+-+\n\n");

}
void estiloLabirintoPercorrido()
{
    cores(2);
    printf("\n\n");
    printf("\t\t\t\t\t\t  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t\t\t\t\t\t  |M|E|N|O|R| |C|A|M|I|N|H|O|\n");
    printf("\t\t\t\t\t\t  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n");


}
void cores(int corTexto)
{
    // Handel-C � para design de hardware
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola,corTexto);

}
