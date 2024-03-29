/*
 * Histograma-2-goto.c
 *
 * Progama de la seccion 1.5.4 de [KR1988] modificado para usar goto para
 * control de estados
 * 
 * Luca Colamonici
 */

#include <stdio.h>
#include "histograma.h"

int mainGoto(){
    int c, nl, nw, nc;
    nl=nw=nc=0;
    State state = OUT;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n') goto nuevaLinea;
        if(c=='\t' || c==' ') goto finPalabra;
        else if(state==OUT) goto nuevaPalabra;
        goto finIteracion;
        nuevaLinea:
        ++nl;
        finPalabra:
        state=OUT;
        goto finIteracion;
        nuevaPalabra:
        state=IN;
        ++nw;
        finIteracion:
    }
    printf("lineas:%d palabras:%d caracteres:%d\n", nl, nw, nc);
    return 0;
}

/*
int main(){
    mainGoto();
    return 0;
}*/
