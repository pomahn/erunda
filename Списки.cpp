#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <ctype.h>
#include <assert.h>

#define TRASH 0xFEFEFEFE
#define CANARY 0xBADF00D
#define MAX_STR_LEN 100
#define HASH_TABLE_SIZE 10




typedef struct ListElem
    {
        double can1;
        int info;
        ListElem* next;
        ListElem* prev;
        double can2;
    };

typedef struct List
    {
        double can1;
        int elem_amount;
        ListElem* head;
        ListElem* tail;
        double can2;
    };


void ListElem_ctor(ListElem* This, int info)   ;
void ListElem_dtor(ListElem* This);
bool List_OK(const ListElem* This);
void Head_insert(List* This, ListElem* Insert) ;
void Tail_insert(List* This, ListElem* Insert)    ;
void Insert_before(ListElem* This, ListElem* Insert) ;
void Insert_after(ListElem* This, ListElem* Insert)  ;
void Elem_delete(ListElem* This)                     ;
void Do_test(int* hash_int_table, int (*Hash_function) (char*)) ;
int Word_read (FILE* file, char* s)      ;
//void Hash_end_insert(List_elem* *hash_table, int position, List_elem* This) ;
int Hash_func1(char* word);
void Hash_table_show(int* hash_int_table);
void Do_test_with_num(int fnum);



int main()
    {

        int hash_int_table[HASH_TABLE_SIZE];

        for (int i = 0; i < HASH_TABLE_SIZE;)
            {
                hash_int_table[i] = 0;
                i++;
            }
        int which_func = 0;
        printf("Enter num of function\n");
        scanf("%i\n", &which_func);

        Do_test_with_num(which_func);
        //Do_test(hash_int_table, Hash_func1);
        Hash_table_show(hash_int_table);

    }




void ListElem_ctor(ListElem* This, int info)
    {
        This->can1 = CANARY;
        This->info = info;
        This->next = NULL;
        This->prev = NULL;
        This->can2 = CANARY;
    }


void ListElem_dtor(ListElem* This)
    {
        This->info = TRASH;
        This->next = NULL;
        This->prev = NULL;
    }

bool List_OK(const ListElem* This)
    {
        return (This ->can1 == CANARY) &&
           (This ->can2 == CANARY) ;

    }

void Head_insert(List* This, ListElem* Insert)
    {
        Insert->next = This->head;
        This->head = Insert;
        (Insert->next)->prev = Insert;
    }

void Tail_insert(List* This, ListElem* Insert)
    {
        Insert->prev = This->tail;
        (Insert->prev)->next = Insert;
        This->tail = Insert;
    }

void Insert_before(ListElem* This, ListElem* Insert)
    {
        (This->prev)->next = Insert;
        Insert->prev = This->prev;
        Insert->next = This;
        This->prev = Insert;
    }

void Insert_after(ListElem* This, ListElem* Insert)
    {
        (This->next)->prev = Insert;
        Insert->next = This->next;
        Insert->prev = This;
        This->next = Insert;
    }

void Elem_delete(ListElem* This)
    {
        (This->prev)->next = This->next;
        (This->next)->prev = This->prev;
        ListElem_dtor(This);
    }


void Do_test(int* hash_int_table, int (*Hash_function) (char*))
    {
        int position = 0;
        FILE* file = fopen("test_text.txt", "r");
        char word[MAX_STR_LEN];

        while (1)
            {
                if (Word_read(file, word) == -1) break;
                position = Hash_function(word) % HASH_TABLE_SIZE ;
                //printf("word = %s \n",  word);
                //if (word == '\0') break;

                //ListElem* a = (ListElem*)calloc(1, sizeof(ListElem));
                //ListElem_ctor(a, word);
                //printf("dad\n");
                hash_int_table[position]++;
                //Hash_end_insert(hash_table, position, &a);

            }
        fclose(file);
    }



int Word_read (FILE* file, char* s)
    {
        char c = fgetc (file);

        if (c == EOF) return -1;

        int i=0;
        while ((c != ' ') && (c != '\n') && (c != EOF ))
            {
                s[i] = c;

                c = fgetc (file);
                if (c == EOF) return -1;

                i++;
            }
        s[i] = '\0';
        return 0;
    }


/*void Hash_end_insert(List_elem* *hash_table, int position, List_elem* This)
    {
        List_elem* pointer;
        if (hash_table[position] = NULL)
            {
                hash_table[position] = This;
            }

        else
            {
                pointer = hash_table[position];

                while (pointer->next != NULL)
                    {
                        pointer = pointer->next;
                    }
                pointer->next = This;
            }
    }*/

void Hash_table_show(int* hash_int_table)
    {
        for (int i = 0; i < HASH_TABLE_SIZE ; )
            {
                printf("Hash num. %i got %i words in it. \n",  i,  hash_int_table[i]);
                i++;
            }
    }



int Hash_func1(char* word)
    {
        return (int)word[1];
    }


Do_test_with_num(int fnum)
{
    switch (fnum)
    {
        case 1:
            Do_test(hash_int_table, Hash_func1); break;
        case 2:
            Do_test(hash_int_table, Hash_func2); break;
        case 3:
            Do_test(hash_int_table, Hash_func3); break;
        case 4:
            Do_test(hash_int_table, Hash_func4); break;

        default: assert(!"Wrong function");
    }
}

