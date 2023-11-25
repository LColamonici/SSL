#include "scanner.c"

int main(){
    char str[20];
    getNextToken(str);
    while(!endOfTokens(str)){
        printf(str);
        printf("\n");
        getNextToken(str);
    }
    
}