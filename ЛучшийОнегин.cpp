#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

int filesize(FILE * file);
char* file_v_buf(FILE *reading);
int string_count(char*  buf_pointer);
void strings_pointers(char* buf_point, char* *pointers_on_strings ,char* *pointers_to_end, int string_counter);
int my_strcmp(const void *string1, const void *string2);
void array_copy(char* *normsort, char* *pointer_on_strings, int string_counter);
void file_print(FILE*reading, char* *normsort,int string_counter);
int is_rus_letter(char letter);
char my_tolower (char letter);
int my_reverse_strcmp(const void *string1, const void *string2);




int main()
    {
    FILE * reading ;
    char* buf_pointer;
    int string_counter=0;
    reading = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\reading.txt" , "rt");
    assert(reading);

    buf_pointer = file_v_buf ( reading);

    string_counter = string_count (buf_pointer);

    char* pointers_on_strings[string_counter-1];
    char* pointers_to_end[string_counter-1];

    strings_pointers (buf_pointer, pointers_on_strings, pointers_to_end, string_counter);

    printf("3\n");

    char* normsort[string_counter-1];
    char* reversesort[string_counter-1];

    array_copy (normsort, pointers_on_strings, string_counter);
    array_copy (reversesort, pointers_to_end, string_counter);

    printf("4\n");

    qsort (normsort, string_counter, sizeof(normsort[0]), my_strcmp);
    qsort (reversesort, string_counter, sizeof(normsort[0]), my_reverse_strcmp);

    printf("asdfadfsdfsdf\n");
    FILE * writing = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing.txt" , "wt");
    FILE * writing_reverse = fopen("C:\\Users\\pomah_000\\Desktop\\Onegin\\writing_reverse.txt" , "wt");

    file_print(writing, normsort, string_counter) ;
    file_print(writing_reverse, reversesort, string_counter) ;
    fclose(reading);
    fclose(writing_reverse);
    fclose(writing);
    return 0;
    }





char* file_v_buf(FILE *reading)
    {

        int file_size = 0;
        file_size = filesize(reading);
        rewind(reading);
        char* file_string = (char*)calloc(1, file_size);
        fread(file_string, file_size, 1, reading);
        return file_string;
    }


int filesize(FILE *file)
    {
        FILE* Minifile = file ;
        long int file_size=0;

        fseek( file, 0, SEEK_END );
        file_size = ftell( file );

        printf("filesize %d\n", file_size);
        return (file_size );
    }


int string_count(char*  buf_pointer)
    {
        assert(buf_pointer);
        char* pointer = buf_pointer;
        int string_counter = 0;

        while (1)

            {

            if (strchr(pointer, '\n') == NULL )
                {
                break;
                }

            pointer = strchr(pointer, '\n')+1;

             string_counter++;
            }
       printf("stringcount %d\n", string_counter+1);
       return (string_counter+1);
    }



void strings_pointers(char* buf_point, char* *pointers_on_strings ,char* *pointers_to_end, int string_counter)
    {
    assert(buf_point);
    pointers_on_strings[0] = buf_point;

    for (int i=1;    i <= (string_counter-1);     i++)
        {

        char* c = strchr(pointers_on_strings[i-1], '\n');
        *c = '\0';
        pointers_to_end[i-1] = c-1;
        pointers_on_strings[i] = c+1;
        assert(pointers_on_strings[i]);
        assert(pointers_to_end[i-1]);
        }
    char* c = strchr(pointers_on_strings[string_counter-1], '\0');
    assert(c);
    pointers_to_end[string_counter-1] = c-1;
    }


int my_reverse_strcmp(const void *string1, const void *string2)
    {

    unsigned char* string_a = *(unsigned char**)string1;
    unsigned char* string_b = *(unsigned char**)string2;

    while (1)
        {
        while (( !isalnum(*string_a) && (!is_rus_letter(*string_a)))  &&  (*string_a != '\0') )
            {
            string_a--;
            }

        while (( !isalnum(*string_b) && (!is_rus_letter(*string_b))) &&   (*string_b != '\0') )
            {

            string_b--;
            }

        if ( *string_a == '\0')
            {
            if (*string_b == '\0')
                {

                return 0;
                }
            else
                {

                 return -1;
                }
            }
        if ( *string_b == '\0')
            {

             return 1;
            }


        if (my_tolower(*string_a) - my_tolower(*string_b) != 0)
            {

            return (my_tolower(*string_a) - my_tolower(*string_b)) ;
            }
        string_a--;
        string_b--;
        }
    }


int my_strcmp(const void *string1, const void *string2)
    {

    unsigned char* string_a = *(unsigned char**)string1;
    unsigned char* string_b = *(unsigned char**)string2;

    while (1)
        {
        while (( !isalnum(*string_a) && (!is_rus_letter(*string_a)))  &&  (*string_a != '\0') )
            {
            string_a++;
            }

        while (( !isalnum(*string_b) && (!is_rus_letter(*string_b))) &&   (*string_b != '\0') )
            {

            string_b++;
            }

        if ( *string_a == '\0')
            {
            if (*string_b == '\0')
                {

                return 0;
                }
            else
                {

                 return -1;
                }
            }
        if ( *string_b == '\0')
            {

             return 1;
            }


        if (my_tolower(*string_a) - my_tolower(*string_b) != 0)
            {

            return (my_tolower(*string_a) - my_tolower(*string_b)) ;
            }
        string_a++;
        string_b++;
        }
    }

void array_copy(char* *normsort, char* *pointers_on_strings, int string_counter)
    {
    for (int i=0;    i <= string_counter-1 ;   i++)
        {
        assert(pointers_on_strings[i]);
        normsort[i] = pointers_on_strings[i];
        assert(normsort[i]);
        }
    }



void file_print(FILE*writing, char* *normsort, int string_counter)
    {


    for (int i=0; i<=(string_counter-1); i++)
        {
        assert(normsort[i]);
        fprintf( writing, "%s", normsort[i]);
        fputc('\n', writing);
        }
    }


int is_rus_letter(char letter)
    {
    if ((letter >= '�' && letter <= '�') || (letter >= '�' && letter <= '�') )
                {
                return 1;
                }
    else
        {
        return 0 ;
        }
    }

char my_tolower (char letter)
    {
    if (is_rus_letter(letter))
        {
         if (letter >= '�' && letter <= '�')
            {
            return (letter + ('�' - '�'));
            }
        }

    return tolower(letter);



    }

