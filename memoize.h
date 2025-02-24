#ifndef PAIR_H
#define PAIR_H

#include <stdlib.h>
#define MAX_LENGTH 256

typedef struct {
    int value;
    char text[MAX_LENGTH];
} Pair;

void add_value(int value, char *text);
char* is_on_list(int value);
void free_memo();

#endif