#include <stdio.h>
#include "histograma-1-enum-switch.c"


int main2(){
    int c, nl, nw, nc;
    nl=nw=nc=0;
    State state = OUT;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n') goto nuevaLinea;
        if(c=='\t' || c==' ') goto finPalabra;
        else if(state==OUT) goto nuevaPalabra;
        nuevaLinea:
        ++nl;
        finPalabra:
        state=OUT;
        goto finCiclo;
        nuevaPalabra:
        state=IN;
        ++nw;
        finCiclo:
    }
    printf("%d %d %d\n", nl, nw, nc);
}