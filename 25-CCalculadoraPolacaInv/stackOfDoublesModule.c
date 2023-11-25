#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKDEPTH 100
/*
struct stack{
    double operandos[STACKDEPTH];
    unsigned int sp; //stack pointer
};
*/

double operandos[STACKDEPTH];
unsigned int sp; //stack pointer

void push(double val){
    operandos[sp]=val;
    sp++;
}

bool stkIsEmpty(){
    return sp==0;
}

double pop(){
    return operandos[--sp];
}

bool stkIsFull(){
    return sp>=STACKDEPTH;
}

