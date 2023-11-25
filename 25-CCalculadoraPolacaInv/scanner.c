#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef enum{
    OPERANDO,
    OPERADOR
} tType;

bool isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

bool strIsOperator(char* s){
    return isOperator(s[0]) && s[1]=='\0';
}

bool endOfTokens(){
    return *token==EOF;
}

char token[30];

void getNextToken(){
    char ret[20];
    int i=0;
    char c=getchar();
    while(c==' ') c=getchar(); //si encuentra n espacio, sigue leyendo caracteres hasta que no haya un espacio
    if(isOperator(c)){
        *ret=c;
        ret[1]='\0';
    }
    else if(c==EOF || c=='\n') *ret=EOF;
    else if(isdigit(c) || c=='.'){
        while(isdigit(c) ||c=='.'){
            ret[i]=c;
            i++;
            c=getchar();
        }
        if(isOperator(c)) ungetc(c, stdin);
        ret[i]='\0';
    }
    strcpy(token, ret);

}

tType tokenType(){
    return isdigit(*token)?OPERANDO:OPERADOR; //si empieza con un digito, es un numero
}

double tokenValue(){
    if(tokenType()==OPERANDO) return atof(token);
    else return 0.0;
}