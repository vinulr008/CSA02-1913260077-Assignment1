#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define RUPEES(x) ((x) * 100)

static inline int square_function(int x)
{
    return x * x;
}

static inline int max_function(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 5, b = 10;

    printf("Square of a: %d\n", SQUARE(a));
    printf("Square of a+1: %d\n", SQUARE(a + 1));
    printf("Maximum value: %d\n", MAX(a, b));
    printf("Rupees to Paise: %d\n", RUPEES(50));

    printf("Inline Square: %d\n", square_function(a));
    printf("Inline Maximum: %d\n", max_function(a, b));

    return 0;
}
