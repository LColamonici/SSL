#include "scanner.h"
#include "stackOfDoublesModule.h"

void operarCon(struct Token t){
    switch(t.type){
        case Addition:
            push(pop()+pop());
            break;
        case Subtraction:
            double b=pop(), a=pop();
            push(a-b);
            break;
        case Multiplication:
            push(pop()*pop());
            break;
        case Division:
            double d=pop(), c=pop();
            if(d==0){
                printf("Error: division entre 0\n");
            }
            else push(c/d);
            break;
    }
}

int main(){
    struct Token t;
    while(getNextToken(&t)){
        while(t.type!=PopResult && t.type!=EOF){
            if(t.type==Number) push(t.val);
            else if(isOperator(t.type)) operarCon(t);
            else if(t.type=LexError){
                printf("Error, lexema o  caracter no reconocido: ");
                printf(t.lexeme);
                printf("\n");
                //printf(" ascii: %d %d\n", (int)(t.lexeme[0]), (int)(t.lexeme[1]));
            }
            getNextToken(&t);
        }
        printf("%f \n", pop());
    }
    if(!stkIsEmpty()) printf("%f \n", pop()); //si quedaba un valor en la pila, tambien se imprime
    
    return 0;
}