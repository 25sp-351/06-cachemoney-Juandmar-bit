#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdlib.h>

void to_cents (int cents);
void to_dollar (int dollars, int cents);
char* convert_to_text (int value);

#endif // CONVERSION_H