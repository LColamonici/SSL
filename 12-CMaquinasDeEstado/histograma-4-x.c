#include <stdio.h>
#include "histograma.h"

int isSpacing(char c){
    return c==' '||c=='\n'||c=='\t';
}

State none(State s, char c, int* nl_p, int* nw_p){ //no hay cambio en el estado
    if(c=='\n') (*nl_p)+=1; //si esta afuera y no cambia de estado igual hay que ver si no hay un \n
    return s;
}

State outToIn(State s, char c, int* nl_p, int* nw_p){ //cambio de fuera a dentro de una palabra
    (*nw_p)+=1;
    return IN;
}

State inToOut(State s, char c, int* nl_p, int* nw_p){//cambio de dentro a fuera de una palabra
    if(c=='\n') (*nl_p)+=1;
    return OUT;
}

int mainx(){
    int c, nl, nw, nc;
    nl=nw=nc=0;
    State s = OUT;
    State (*cambiosEstado[2][2])(State, char, int*, int*)={
        {none, outToIn},
        {inToOut, none}
    };
    while((c=getchar())!=EOF){
        nc++;
        State inOrOut=!isSpacing(c); //si c no es espaciador, esta dentro de una palabra (IN o 1 en el enum)
        s = cambiosEstado[s][inOrOut](s, c, &nl, &nw);
    }
    printf("lineas:%d palabras:%d caracteres:%d\n", nl, nw, nc);
    return 0;
}


