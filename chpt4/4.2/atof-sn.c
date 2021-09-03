/* atof: Extend atof to handle scientific notation of the form 123.45e-6 
where a floating-point number may be followed by e or E and an optionally signed exponent.

===============================================
How to convert numbers to scientific notation
===============================================

Use the following procedure:

Your exponent starts at zero.
Slide the decimal so there is only one non-zero digit to the left of the decimal.
Each place you slide the decimal to the left increases the exponent by 1.
Each place you slide the decimal to the right decreases the exponent by 1.
Trim off any leading zeros (on the left end of the significand)
Trim off any trailing zeros (on the right end of the significand) only if the original number had no decimal point. 
We’re assuming they’re not significant unless otherwise specified.

Here’s some examples:

Start with: 42030
Slide decimal left 4 spaces: 4.2030e4
No leading zeros to trim: 4.2030e4
Trim trailing zeros: 4.203e4 (4 significant digits)

Start with: 0.0078900
Slide decimal right 3 spaces: 0007.8900e-3
Trim leading zeros: 7.8900e-3
Don't trim trailing zeros: 7.8900e-3 (5 significant digits)

Start with: 600.410
Slide decimal left 2 spaces: 6.00410e2
No leading zeros to trim: 6.00410e2
Don't trim trailing zeros: 6.00410e2 (6 significant digits)

Here’s the most important thing to understand: The digits in the significand 
(the part before the ‘e’) are called the significant digits. 
The number of significant digits defines a number’s precision. 
The more digits in the significand, the more precise a number is.
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* atof: convert string s to double */

double atof(char s[]);

int main(int argc, char *argv[]) {
    //char s[8]="1234.45";
    //char s[12]="4.2030e4";
    //char s[12]="0007.8900e-3";
    //char s[12]="6.00410e2";
    char s[12]="1.0e10";
    double d;
    d = atof(s);
    printf("%f\n", d);
}

double atof(char s[])
{
    double val, power, expval;
    int i, sign, expsign;
    int decimal = 0;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        decimal = i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        expsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (expval = 0.0; isdigit(s[i]); i++)
            expval = 10 * expval + (s[i] - '0');
        //printf("expval: %d\n", expval);
        return sign * (val/power) * pow(10, (expsign*expval));
    }
    return sign * val / power;
}