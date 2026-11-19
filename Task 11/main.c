#include <stdio.h>

#define SLAB1 100
#define SLAB2 200

#define RATE1 0
#define RATE2 225
#define RATE3 450

#define FIXED_CHARGE 5000LL

long long calculate_bill(unsigned long long units)
{
    long long energy = 0;

    if (units > SLAB1)
    {
        unsigned long long second;

        if (units > SLAB2)
            second = SLAB2 - SLAB1;
        else
            second = units - SLAB1;

        energy += (long long)second * RATE2;
    }

    if (units > SLAB2)
        energy += (long long)(units - SLAB2) * RATE3;

    return FIXED_CHARGE + energy;
}

int main()
{
    unsigned long long units;

    printf("Enter Units Consumed: ");

    if (scanf("%llu", &units) != 1)
    {
        printf("Invalid Input\n");
        return 1;
    }

    long long bill = calculate_bill(units);

    printf("Units: %llu\n", units);

    printf("Total Bill: Rs %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
