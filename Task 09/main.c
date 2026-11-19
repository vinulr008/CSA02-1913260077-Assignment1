#include <stdio.h>
#include <limits.h>

#define RATE2 225
#define RATE3 450
#define FIXED_CHARGE 5000

unsigned int consumption(unsigned int previous,
                         unsigned int current)
{
    if (current >= previous)
        return current - previous;

    if (previous > 60000 && current < 1000)
        return (USHRT_MAX + 1U - previous) + current;

    return UINT_MAX;
}

long calculate_bill(unsigned int units)
{
    long bill = FIXED_CHARGE;

    if (units > 100 && units <= 200)
        bill += (units - 100) * RATE2;

    else if (units > 200)
        bill += 100 * RATE2 +
                (units - 200) * RATE3;

    return bill;
}

int main()
{
    unsigned int previous, current;

    printf("Enter Previous Reading: ");
    if (scanf("%u", &previous) != 1)
    {
        printf("Invalid Input\n");
        return 1;
    }

    printf("Enter Current Reading: ");
    if (scanf("%u", &current) != 1)
    {
        printf("Invalid Input\n");
        return 1;
    }

    if (previous > 65535 || current > 65535)
    {
        printf("Invalid Meter Reading\n");
        return 1;
    }

    unsigned int units = consumption(previous, current);

    if (units == UINT_MAX)
    {
        printf("Invalid Meter Rollover\n");
        return 1;
    }

    long bill = calculate_bill(units);

    printf("Units Consumed: %u\n", units);

    printf("Energy and Fixed Bill: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
