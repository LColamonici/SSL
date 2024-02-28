/*
 * Histograma-1-enum-switch.c
 *
 * Progama de la seccion 1.5.4 de [KR1988] modificado para usar enum y switch para
 * almacenamiento y control de estados
 * 
 * Luca Colamonici
 */
#include <stdio.h>
#include "histograma.h"


 /* RESPECTO AL CODIGO ORIGINAL
 * Ventajas: el switch hace mas facil entender el alcance de cada condicional, el uso de enum permite agregar 
 * facilmente mas estados si hace falta
 * Desventajas: la estructura del switch complica la legibilidad del codigo al tener varios casos en los que se hace lo mismo
 */


int mainEnumSwitch(){
    int c, nl, nw, nc;
    nl=nw=nc=0;
    State s = OUT;
    while((c=getchar())!=EOF){
        ++nc;
        switch(c){
            case ' ':
                s=OUT;
                break;
            case '\n':
                ++nl;
                s=OUT;
                break;
            case '\t':
                s=OUT;
                break;
            
            default:
                switch(s){
                    case OUT:
                        s=IN;
                        ++nw;
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    printf("lineas:%d palabras:%d caracteres:%d\n", nl, nw, nc);;
    return 0;
}

/*
int main(){
    mainEnumSwitch();
    return 0;
}
*/