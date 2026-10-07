#include <stdio.h>
#include <stdlib.h>

#include "include//vector.h"

int main() {
    Vector *vector;

    vector = vectorConstruct();

    vectorDestroy(vector);

    return 0;
}