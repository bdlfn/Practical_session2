#include <stdio.h>
#include "sum.h"

int main() {
    int a = 5;
    int b = 7;
    int result = sum(a, b);
    printf("Sum of %d and %d is %d\n", a, b, result);
    return 0;
}
