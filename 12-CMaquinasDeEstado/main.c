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
    }
    return 0;
}