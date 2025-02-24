#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoize.h"
#define MAX_CHAR 256

const char* ONES[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char* TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* TENS[] = {"", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char CENT_TEXT[MAX_CHAR] = "";
char DOLLAR_TEXT[MAX_CHAR] = "";


void to_cents (int cents){
    if(cents >= 20) {
        snprintf(CENT_TEXT + strlen(CENT_TEXT), sizeof(CENT_TEXT) - strlen(CENT_TEXT), "%s ", TENS[cents / 10 - 1]);

        cents %= 10;
    }
    if(cents >= 10) {
        snprintf(CENT_TEXT + strlen(CENT_TEXT), sizeof(CENT_TEXT) - strlen(CENT_TEXT), "%s cents", TEENS[cents - 10]);
        cents = 0;
    }
    if(cents > 0) {
        if(strlen(CENT_TEXT) == 0 ) {
            snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s cent", ONES[cents]);
            return;
        }
        snprintf(CENT_TEXT + strlen(CENT_TEXT), sizeof(CENT_TEXT) - strlen(CENT_TEXT), "%s cents", ONES[cents]);
    }
    snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s", CENT_TEXT);
}

void to_dollar (int dollars, int cents){

    if (dollars >= 1000) {
        snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s thousand ", ONES[dollars/1000]);
        dollars %= 1000;
    }
    if (dollars >= 100) {
        snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s hundred ", ONES[dollars / 100]);
        dollars %= 100;
    }
    if (dollars >= 20) {
        snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s ", TENS[dollars / 10 - 1]);
        dollars %= 10;
    }
    if (dollars >= 10) {
        snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s ", ONES[dollars - 10]);
        dollars = 0;
    }
    if (dollars > 0) {
        snprintf(DOLLAR_TEXT + strlen(DOLLAR_TEXT), sizeof(DOLLAR_TEXT) - strlen(DOLLAR_TEXT), "%s dollars ", ONES[dollars]);
    }
    to_cents(cents);
}

char* convert_to_text (int value) {

    int dollars = value / 100;
    int cents = value % 100;

    to_dollar(dollars, cents);

    printf("%d = %s\n", value, DOLLAR_TEXT);

    char* dollar_value = malloc(MAX_CHAR * sizeof(char));
    if (dollar_value == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    snprintf(dollar_value, MAX_CHAR, "%s", DOLLAR_TEXT);
    CENT_TEXT[0] = '\0';
    DOLLAR_TEXT[0] = '\0';

    return dollar_value;
}
