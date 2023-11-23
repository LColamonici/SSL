#include <stdio.h>

int c, nl, nw, nc;

void stateOut(){
    if(c=='\n') ++nl;
    analizarCaracter();
}

void stateIn(){
    ++nw;
    analizarCaracter();
}

void analizarCaracter(){
    c=getchar();
    if(c=='\t' || c==' ' || c=='\n') stateOut();
    else if(c==EOF) return;
    else stateIn();
}

int main3(){
    nl=nw=nc=0;
    analizarCaracter();    
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}