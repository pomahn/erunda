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
    printf("%i",n);
    sort(n);

    return 0 ;
}




void sort(int n)
    {
        char s1[100] = "";
        char s2[100] = "";
        int tries = 0;
        FILE * reading ;
        FILE * writing;

        while (tries <= n )
            {
            printf("%i",tries);

                if (tries % 2==0)
                    {
                        reading = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing.txt" , "rt"  );
                        writing = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\sort.txt" , "wt"  );

                    }
                else
                    {
                        writing = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing.txt" , "wt"  );
                        reading = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\sort.txt" , "rt"  );
                        fgets(s1,100,reading);
                        fprintf(writing, "%s", s1);

                    }
                sprintf(s2,"");
                sprintf(s1,"");
                while ( fgets(s1, 100, reading) != NULL )
                    {
                        if ( fgets(s2, 100, reading) != NULL )
                            {
                                if (strcmp(s1, s2) > 0)
                                    {
                                    fprintf(writing, "%s%s", s2,s1);
                                    }
                                else
                                    {
                                    fprintf(writing, "%s%s", s1,s2);
                                    }
                            }
                        else
                            {
                            fprintf(writing, "%s", s1);
                            }
                    }
                fclose(reading);
                fclose(writing);
             tries++;
            }
    }










