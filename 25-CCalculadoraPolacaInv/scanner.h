#ifndef TOKENSCANNER_H
#define TOKENSCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEXEME_LENGTH 20 //puede cambiar

typedef enum{
    Number,
    Addition='+',
    Multiplication='*',
    Subtraction='-',
    Division='/',
    PopResult='\n',
    LexError
} TokenType;

typedef double TokenValue;
struct Token{
    TokenType type;
    TokenValue val; 
    char lexeme[MAX_LEXEME_LENGTH];
};
int isOperator(char c);
int strIsOperator(char* s);
int getNextToken(struct Token *t);
char nextCharInStream();

#endif