#ifndef TOKENSCANNER_H
#define TOKENSCANNER_H



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEXEME_LENGTH 20 //puede cambiar

enum TokenType{
    Number,
    Addition='+',
    Multiplication='*',
    Substraction='-',
    Division='/',
    PopResult='\n',
    LexError
};

typedef enum TokenType TokenType;
typedef double TokenValue;
struct Token{
    TokenType type;
    TokenValue val; 
    char lexeme[MAX_LEXEME_LENGTH];
};




bool isOperator(char c){
    return (c==Addition||c==Substraction||c==Multiplication||c==Division);
}

bool strIsOperator(char* s){
    return isOperator(s[0]) && s[1]=='\0';
}


bool getNextToken(struct Token *t){
    char lexeme[MAX_LEXEME_LENGTH];
    int i=0;
    char c=getchar();
    while(c==' ') c=getchar(); //si encuentra n espacio, sigue leyendo caracteres hasta que no haya un espacio

    if(isOperator(c)){
        t->type = c; //puede ser Addition, Subtraction, Division o Multiplication
        *lexeme=c;
        lexeme[1]='\0';
    }
    else if(isdigit(c) || c=='.'){
        t->type=Number;
        while(isdigit(c) ||c=='.'){
            lexeme[i]=c;
            i++;
            c=getchar();
        }
        if(c!=' ') ungetc(c, stdin);
        lexeme[i]='\0';
    }
    else if (c=='\n') t->type = PopResult;
    else t->type=LexError; //si c no es digito, operador, salto de linea, EOF o . , no se reconoce el lexema
    if(t->type==Number) t->val = atof(lexeme);
    strcpy(t->lexeme, lexeme);
    return c!=EOF;
}



#endif