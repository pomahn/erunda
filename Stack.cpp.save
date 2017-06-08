#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

#define MAX_LEN 100
#define CANARY 0xBADF00D
#define TRASH 0xFFFFFFFE
#define WHERE printf ("File %s Line %d Function %s \n", __FILE__, __LINE__, __FUNCTION__);

#ifdef NDEBUG
#define OK(wut);
#else
#define OK(wut)                     \
    {                                \
        if (!wut##_OK(This))          \
            {                          \
                wut##_dump (This);      \
                WHERE ;                  \
            }                             \
    }
#endif

struct stack
{
    double can1;
    double* data;
    int count;
    int max_len;
    double can2;
};


void stack_dump (const stack *This);

void stack_ctor (stack *This, int stack_size);

void stack_dtor (stack *This);

bool stack_OK (const stack *This);

void stack_push (stack *This, double val);

double stack_pop (stack *This);




int main()

    {

        stack* stk = (stack*)calloc(1, sizeof(stack));
        WHERE
        stack_ctor (stk, 99);
        WHERE
        stack_push (stk, 123);
        stack_push (stk, 11);
        printf("Cifra %lg \n", stack_pop (stk));
        stack_dump (stk);
        stack_dtor (stk);
        stack_dump (stk);


        return 0;

    }

void stack_ctor (stack* This, int size)

    {
        assert(This);

        This ->can1 = CANARY ;
        This ->data = (double*)((char*)calloc (size + 2, sizeof(double)) + sizeof (double));
        This ->count = 0;
        This ->data[-1] = CANARY;
        This ->data[size] = CANARY;
        This ->max_len = size;
        This ->can2 = CANARY;

    }


void stack_dtor (stack* This)

    {
        assert (This);

        free (This ->data - 1);
        This ->data = NULL;
        This ->count = TRASH;
        This ->can1 = TRASH;
        This ->can2 = TRASH;
        This ->max_len = TRASH;

        free(This);
    }


double stack_pop (stack* This)

    {
        assert (This);
        assert(This->count > 0);
        OK(stack);

        return This ->data[This ->count-- - 1];
    }



void stack_push (stack* This, double val)

    {
        assert (This);
        OK(stack);

        This ->data[This ->count++] = val;

        OK(stack);
    }



bool stack_OK (const stack* This)
    {

    return (This != NULL) &&

           (This ->can1 == CANARY) &&
           (This ->can2 == CANARY) &&

           (This ->data != NULL) &&

           (This ->count >= 0) &&

           (This ->data[-1] == CANARY) &&
           (This ->data[This ->max_len] == CANARY);
    }


void stack_dump (const stack* This)

    {
        printf ("Stack ");
        if (!stack_OK (This)) printf("not ");
        printf ("OK \n");
        printf ("HeMHoro o CTEKE\n\n");

        if (This ->can1 == CANARY) printf("Canary 1 from struct [OK] \n");
            else printf("Canary 1 = %lg [NOT OK ERROR 228] \n", This ->can1);


        if (This ->can1 == CANARY) printf("Canary 2 from struct [OK] \n");
            else printf("Canary 2 = %lg [NOT OK ERROR 228] \n", This ->can2);

        if (This ->data == NULL)
            {
                printf("ERROR: no pointer to data\n");
                return;
            }

        if (This ->data[-1] == CANARY) printf("Canary 1 in data [OK] \n");
            else printf("Canary 1 in data = %lg [NOT OK ERROR 228] \n", This ->data[-1]);


        if (This ->data[This ->max_len] == CANARY) printf("Canary 2 in data = %lg [OK] \n");
            else printf("Canary 2 in data [NOT OK ERROR 228] \n", This ->data[This ->max_len]);


        printf ("count %i \n", This ->count);

        printf ("Max length %i \n", This ->max_len);

        for (int i = 0; i < (This ->max_len); i++)
            {
                if (i < (This ->count)) printf("*");
                printf ("data[%i] = %lg \n", i, This ->data[i]);
            }
    }


















