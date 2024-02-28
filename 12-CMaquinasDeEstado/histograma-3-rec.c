/*
 * Histograma-3-rec.c
 *
 * Progama de la seccion 1.5.4 de [KR1988] modificado para usar funciones recursivas para
 * almacenamiento y control de estados
 * 
 * Luca Colamonici
 */

#include <stdio.h>
#include "histograma.h"

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
    printf("lineas:%d palabras:%d caracteres:%d\n", nl, nw, nc);
    return 0;
}

/*
int main(){
    mainRec();
    return 0;
}
*/