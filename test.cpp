#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sort (int n);

int main()
{
    char s1[100] ="";
    char s2[100] ="";
    FILE * reading ;
    reading = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\reading.txt" , "rt");
    FILE * writing = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing.txt" , "wt"  );
    int n=0;

    while ( fgets(s1, 100, reading) != NULL )
        {
            if (strcmp(s1,s2)!=0)
                {
                    fprintf( writing, "%s", s1);
                    n++;
                    sprintf(s2,"%s", s1);
                }

        }
    fclose(writing);
    fclose(reading);

    return n ;
}
