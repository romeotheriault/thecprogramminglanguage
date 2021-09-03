#include <stdio.h>

float cel2fah(float celsius);

main ()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %6s\n", "celsius", "fahr");
    printf("===============\n");
    while (celsius <= upper) {
        fahr = cel2fah(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

float cel2fah(float celsius)
{
    return celsius * (9.0/5.0) + 32;
}
