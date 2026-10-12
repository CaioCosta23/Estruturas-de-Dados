#include <stdio.h>
#include <stdlib.h>

#include "include//vector.h"

int main() {
    Vector *vector;
    const char COPY[5] = "COPY", PUSH[5] = "PUSH", FIND[5] = "FIND", GET[4] = "GET",
         SET[4] = "SET", MAX[4] = "MAX", MIN[4] = "MIN", POP[4] = "POP",
         INSERT[7] = "INSERT", REMOVE[7] = "REMOVE", SORT[5] = "SORT",
         REVERSE[8] = "REVERSE", CLEAR[6] = "CLEAR";

    vector = vectorConstruct();

    // À fazer;

    vectorDestroy(vector);

    return 0;
}