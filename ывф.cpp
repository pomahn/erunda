#include <conio.h>
#include <stdio.h>

#include "enumtest.cpp"

int main() {
    enum Gender a, b;
#undef enum Gender
    a = MALE;
    b = FEMALE;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    getch();
    return 0;
}
