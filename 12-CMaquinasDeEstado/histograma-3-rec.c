#include <stdio.h>
#include "histograma.h"

//typedef enum{OUT,IN} State;

void analizarCaracter();

int c, nl, nw, nc;
State s=OUT;

void stateOut(){
    s=OUT;
    if(c=='\n') ++nl;
    analizarCaracter();
}

void stateIn(){
    if(s==OUT) ++nw;
    s=IN;
    analizarCaracter();
}

void analizarCaracter(){
    c=getchar();
    if(c==EOF) return;
    ++nc;
    if(c=='\t' || c==' ' || c=='\n') stateOut();
    else stateIn();
}

int mainRec(){
    nl=nw=nc=0;
    analizarCaracter();    
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}

/*
int main(){
    mainRec();
    return 0;
}
*/