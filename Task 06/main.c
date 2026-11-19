#include <stdio.h>

int main()
{
    int previous, current;

    printf("Enter Previous Reading: ");

    if (scanf("%d", &previous) != 1)
    {
        printf("Invalid Input\n");
        return 1;
    }

    printf("Enter Current Reading: ");

    if (scanf("%d", &current) != 1)
    {
        printf("Invalid Input\n");
        return 1;
    }

    if (previous < 0 || previous > 65535 ||
        current < previous || current > 65535)
    {
        printf("Invalid Meter Reading\n");
        return 1;
    }

    int units = current - previous;
    long bill = 5000;

    if (units > 100)
    {
        int second = units > 200 ? 100 : units - 100;
        bill += second * 225L;
    }

    if (units > 200)
        bill += (units - 200) * 450L;

    printf("Units Consumed: %d\n", units);

    printf("Total Bill: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
