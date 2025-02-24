#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "memoize.h"
#include "conversion.h"

int is_integer(const char *input) {
    for (size_t xx = 0; xx < strlen(input); xx++) {
        if (!isdigit(input[xx]) && input[xx] != '-') {
            return 0;  
        }
    }
    return 1;
}

void process_input(const char *input){
    if(!is_integer(input)) {
        printf("The value is not an integer.\n");
        return;
    }
    int value;
    if (sscanf(input, "%d", &value) == 1) {
        if (value < 0) {
            printf("The value contains non-positive integers.\n");
            return;
        }
        if (value > 150000) {
            printf("The value is greater than one thousand five hundred dollars.\n");
            return;
        }
        char* found = is_on_list(value);
        if (found != NULL) {
            printf("%d = %s\n", value, found);
            return;
        }
        char* string_value  = convert_to_text(value);
        add_value(value, string_value);
        free(string_value);

    }
}

int main() {
    FILE* file = fopen("test.txt", "r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char line[256];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        process_input(line);
        printf("\n");
    }

    fclose(file);
    free_memo();     
    return 0;
}
