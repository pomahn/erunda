#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

int main()
    {

        double mas[7] = {342, 274, 220, 179, 142, 93, 57} ;
        double time[7] = {106, 133, 145,202.4, 256.05, 390, 636}  ;
        FILE* govno = fopen ("govno.txt", "w");
        for (int i=0; i<7;)
            {
            double a =0.119*9.81*mas[i]  ;
            double b = 2*3.1416*3/time[i];
                fprintf (govno, "(%lg ;%lg ) \n", a, b );
                i++;
            }
       //printf(" a = %lg \n", a);

       return 0;

       }
