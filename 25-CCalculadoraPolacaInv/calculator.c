#include "scanner.c"
#include "stackOfDoublesModule.c"

void operarCon(char* operador){
    switch(*operador){
        case '+':
            push(pop()+pop());
            break;
        case '-':
            double b=pop(), a=pop();
            push(a-b);
            break;
        case '*':
            push(pop()*pop());
            break;
        case '/':
            double d=pop(), c=pop();
            push(c/d);
            break;
    }
}

int main(){
    getNextToken();
    while(!endOfTokens()){
        if(tokenType()==OPERANDO) push(tokenValue());
        else if(tokenType()==OPERADOR) operarCon(token);
        getNextToken();
    }
    printf("%f", pop());
    return 0;
}