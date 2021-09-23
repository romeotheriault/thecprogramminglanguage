#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("not a valid day or month\n");
        return -1;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (yearday < 1 || leap && yearday > 366 || !leap && yearday > 365) {
        printf("not a valid yearday\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main (void)
{
    int doy = day_of_year(1999, 12, 3);

    if (doy == -1)
        return 1;

    int month, day;
    doy = 999;
    month_day(1999, doy, &month, &day);
    if (month == -1 || day == -1)
        return 1;

    printf("doy: %d\n", doy);
    printf("month: %d\n", month);
    printf("day: %d\n", day);
}