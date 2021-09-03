#include <stdio.h>

float atof (char s[]);

int main()
{
    //float var = 1.54334E-34;
    //double var2 = 1.54334E-34;


    //printf("\n normal:%f\n sci:%e \n or \n sci:%E   \n",var,var,var);
    //printf("\n normal:%f\n sci:%e \n or \n sci:%E   \n",var2,var2* 1.0E3 ,var2 * 1.0e3);
    float var = 1555.3E3;
    float var2 = 1555300.000000;
    if (var == var2) {
        printf("we're the same\n");
    }
    printf("normal: %f\n", var);
    printf("sn: %e\n", var);

}