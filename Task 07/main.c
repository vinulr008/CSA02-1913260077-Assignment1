#include <stdio.h>

int main()
{
    int units = 150;

    printf("Integer Division: %d\n", units / 100);

    printf("Floating Division: %.2f\n",
           (float)units / 100);

    printf("Type Conversion: %.2f\n",
           (double)units / 100);

    printf("Integer Conversion: %d\n",
           (int)162.99);

    float a = 0.1;
    float b = 0.2;

    printf("Float Addition: %.10f\n", a + b);

    long paise = 16250;

    printf("Amount in Paise: %ld\n", paise);

    printf("Amount in Rupees: Rs %ld.%02ld\n",
           paise / 100, paise % 100);

    return 0;
}
