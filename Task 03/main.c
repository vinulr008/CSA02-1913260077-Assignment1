#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;

    if (units > SLAB1_UNITS)
    {
        int second;

        if (units > SLAB2_UNITS)
            second = SLAB2_UNITS - SLAB1_UNITS;
        else
            second = units - SLAB1_UNITS;

        paise += (long)second * RATE2_PAISE;
    }

    return paise;
}

int main()
{
    int tests[] = {0, 100, 150, 200, 350};

    for (int i = 0; i < 5; i++)
    {
        long p = compute_bill(tests[i]);

        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], p / 100, p % 100);
    }

    return 0;
}
