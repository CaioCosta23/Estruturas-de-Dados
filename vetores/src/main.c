#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "include//vector.h"

int main() {
    unsigned int quantidadeAcoes, a;
    Vector *vector;
    char acao[8];
    const char COPY[5] = "COPY", PUSH[5] = "PUSH", FIND[5] = "FIND", GET[4] = "GET",
         SET[4] = "SET", MAX[4] = "MAX", MIN[4] = "MIN", POP[4] = "POP",
         INSERT[7] = "INSERT", REMOVE[7] = "REMOVE", SORT[5] = "SORT",
         REVERSE[8] = "REVERSE", CLEAR[6] = "CLEAR";

    
    scanf("%u\n", &quantidadeAcoes);

    vector = vectorConstruct();

    for(a = 0; a <  quantidadeAcoes; a++) {
        scanf("%s", acao);

        if (strcmp(acao, COPY) == 0) {

        }else if (strcmp(acao, PUSH) == 0) {

        }else if (strcmp(acao, FIND) == 0) {
            
        }else if (strcmp(acao, GET) == 0) {
            
        }else if (strcmp(acao, MAX) == 0) {
            
        }else if (strcmp(acao, MIN) == 0) {
            
        }else if (strcmp(acao, POP) == 0) {
            
        }else if (strcmp(acao, INSERT) == 0) {
            
        }else if (strcmp(acao, REMOVE) == 0) {
            
        }else if (strcmp(acao, SORT) == 0) {
            
        }else if (strcmp(acao, REVERSE) == 0) {
            
        }else if (strcmp(acao, CLEAR) == 0) {
            
        }else {
            printf("Opcao invalida.\n");
        }
        
    }
    vectorDestroy(vector);

    return 0;
}