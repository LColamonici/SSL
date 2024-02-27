#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H
typedef enum{OUT,IN} State;
int isSpacing(char);
int mainEnumSwitch();
int mainGoto();
int mainRec();
int mainx();
void analizarCaracter();
void stateIn();
void stateOut();
#endif