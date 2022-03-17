#include <stdbool.h>
#include "StackV2.c"
#include "main.c"

typedef struct dlsResult {
    Element* element;
    bool result;
} DLSResult;

void ids(short int start[][4], short int goal[][4]) {
    Element* root = initStack(start);

    int depth = 0;
    while(1) {

    }
}

Element* DLS(Element* element, short int goal[][4]) {
    DLSResult* result = (DLSResult*)malloc(sizeof(DLSResult));

    if (element->game->depth == 0) {
        result->result = true;
        if (comparar(element->game->grid, goal)) {
            result->element = element;
        } else {
            result->element = NULL;
        }
        return result;
    } else {
        bool anyRemaining = false;
        for (int i = 0; i < 4; i++) { //Loop pelos 4 tipos de movimentos
            DLSResult* movementResult = DLS()
        }
    }
}