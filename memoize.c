#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoize.h"

#define MAX_MEMOIZE 150000
#define MAX_LENGTH 256
Pair *MEMO[MAX_MEMOIZE] = {NULL};

void add_value(int value, char *text) {
    for (int xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] == NULL) {
            MEMO[xx] = (Pair *) malloc(sizeof(Pair));
            MEMO[xx]->value = value;
            snprintf(MEMO[xx]->text, MAX_LENGTH, "%s", text); 
            return;
        }
    }
}

char* is_on_list(int value) {
    for (int xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] != NULL && MEMO[xx]->value == value) {
            return MEMO[xx]->text;
        }
    }
    return NULL;
}

void free_memo() {
    for (int xx = 0; xx < MAX_MEMOIZE; xx++) {
        if (MEMO[xx] != NULL) {
            free(MEMO[xx]);
            MEMO[xx] = NULL;
        }
    }
}