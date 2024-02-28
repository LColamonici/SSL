/*
 * stackOfDoublesModule.c
 *
 * Implementación de una pila para almacenar los operandos entrantes en orden
 * 
 * Luca Colamonici
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackOfDoublesModule.h"

#define STACKDEPTH 100

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