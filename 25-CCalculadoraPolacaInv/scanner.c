#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"    


int isOperator(char c){
    return (c==Addition||c==Subtraction||c==Multiplication||c==Division);
}

int isSpacing(char c){
    return c==' '||c=='\t';
}

int strIsOperator(char* s){
    return isOperator(s[0]) && s[1]=='\0';
}

/*int isDigit(char c){
    return c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0';
}*/

char nextCharInStream(){
    char c = getchar();
    ungetc(c, stdin);
    return c;
}


int getNextToken(struct Token *t){
    char lexeme[MAX_LEXEME_LENGTH];
    int i=1;
    char c=getchar();
    lexeme[0]=c;
    while(isSpacing(c)) lexeme[0]=c=getchar(); //si encuentra un espacio, sigue leyendo caracteres hasta que haya algo distinto

    if(isOperator(c)){
        t->type = (TokenType)c; //puede ser Addition, Subtraction, Division o Multiplication
        *lexeme=c;
        lexeme[1]='\0';
    }
    if(isdigit(c) || (c=='-' && isdigit(nextCharInStream()))){
        t->type=Number;
        lexeme[i]=c=getchar();
        //i++;
        while(isdigit(c) ){
            lexeme[i]=c;
            i++;
            c=getchar();
        }
        if(c=='.'){
            lexeme[i++]=c;
            c=getchar();
            while(isdigit(c)){
                lexeme[i]=c;
                i++;
                c=getchar();
            }
            if(c=='.') t->type=LexError;//si encuentra un segundo punto, el numero esta mal escrito
        }
        if(c!=' ') ungetc(c, stdin);
        lexeme[i]='\0';
    }
    else if (c=='\n' || c==EOF) t->type = PopResult;
    else if(!(isOperator(c) || isSpacing(c) || c=='\n' ||c==EOF || isdigit(c))) t->type=LexError; //si c no es digito, operador, salto de linea, EOF o . , no se reconoce el lexema
    if(t->type==Number) t->val = atof(lexeme);
    strcpy(t->lexeme, lexeme);
    return c!=EOF;
}

