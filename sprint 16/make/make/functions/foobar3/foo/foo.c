#include "foo.h"

void
foo()
{
    int randomNumber = 0;
    double sqrtNumber = 0;

    srand(time(NULL));
    randomNumber = rand() % 100 + 1;
    sqrtNumber = sqrt(randomNumber);

    printf("Did you know that the square root of %d is %.2f?\n", randomNumber,
           sqrtNumber);
    printf("Hello from foo!\n");
}
