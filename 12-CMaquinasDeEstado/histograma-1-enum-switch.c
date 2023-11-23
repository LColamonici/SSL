#include <stdio.h>

enum StateCode{
    OUT,
    IN
};
/*
 * RESPECTO AL CODIGO ORIGINAL
 * Ventajas: el switch hace mas facil entender el alcance de cada condicional, el uso de enum permite agregar 
 * facilmente mas estados si hace falta
 * Desventajas: la estructura del switch complica la legibilidad del codigo al tener varios casos en los que se hace lo mismo
 */
typedef enum StateCode State;

main1(){
    int c, nl, nw, nc;
    nl=nw=nc=0;
    State state = OUT;
    while((c=getchar())!=EOF){
        ++nc;
        switch(c){
            case '\n':
                ++nl;
                state=OUT;
                break;
            case '\t':
                state=OUT;
                break;
            case ' ':
                state=OUT;
                break;
            default:
                switch(state){
                    case OUT:
                        state=IN;
                        ++nw;
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}