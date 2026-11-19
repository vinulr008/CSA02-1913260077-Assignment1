#include <stdio.h>

int main()
{
    int household = 1024;
    int previous = 1200;
    int current = 1530;
    int units = current - previous;

    const int fixed_charge = 50;
    float energy_charge = 0;

    if (units > 100)
        energy_charge += 100 * 2.25;

    if (units > 200)
        energy_charge += (units - 200) * 4.50;

    if (units > 100 && units <= 200)
        energy_charge = (units - 100) * 2.25;

    float total = fixed_charge + energy_charge;

    printf("Household Number: %d\n", household);
    printf("Units Consumed: %d\n", units);
    printf("Energy Charge: Rs %.2f\n", energy_charge);
    printf("Fixed Charge: Rs %d\n", fixed_charge);
    printf("Total Bill: Rs %.2f\n", total);

    return 0;
}
