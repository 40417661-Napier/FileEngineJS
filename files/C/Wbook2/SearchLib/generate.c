#include "generate.h"
#include <stdlib.h>
#include <time.h>

void generate(int size, int *data)
{
    // Seed  the  random
    srand(time(NULL));
    //  Generate  random  numbers
    for (int i = 0; i < size; ++i)
    {
        data[i] = rand();
    }
}
