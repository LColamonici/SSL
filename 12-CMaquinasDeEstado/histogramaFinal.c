#include <stdio.h>
#include<stdlib.h>
#include "histograma-1-enum-switch.c"
#include "histograma-2-goto.c"
#include "histograma-3-rec.c"

int main(int argc, char* argv[]){
    //int c, nl, nw, nc;
    printf("ingresar palabras:\n");
    switch(atoi(argv[1])){
        case 1:
            main1();
            break;
        case 2:
            main2();
            break;
        case 3:
            main3();
            break;
    }
    return 0;
}