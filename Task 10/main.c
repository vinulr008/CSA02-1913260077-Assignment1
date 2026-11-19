#include <stdio.h>

int main()
{
    int n = 4000;

    float float_total = 0.0f;
    long long paise_total = 0;

    for (int i = 0; i < n; i++)
    {
        float_total += 162.50f;
        paise_total += 16250;
    }

    printf("Number of Bills: %d\n", n);

    printf("Float Total: Rs %.2f\n", float_total);

    printf("Integer Paise Total: Rs %lld.%02lld\n",
           paise_total / 100,
           paise_total % 100);

    printf("Difference: Rs %.6f\n",
           (double)float_total -
           (double)paise_total / 100.0);

    return 0;
}
