/*
 * main.c
 *
 * Progama desde el que se puede probar y usar cada una de las 4 implementadiones de la
 * seccion 1.5.4 de [KR1988]
 * 
 * Luca Colamonici
 */



#include <stdio.h>
#include<stdlib.h>
#include "histograma.h"


int main(int argc, char* argv[]){
    //int c, nl, nw, nc;
    printf("ingresar palabras:\n");
    switch(atoi(argv[1])){
        case 1:
            mainEnumSwitch();
            break;
        case 2:
            mainGoto();
            break;
        case 3:
            mainRec();
            break;
        case 4:
            mainx();
            break;
        default:
            printf("argumento invalido");
            break;
    }
    return 0;
}