#include <stdio.h>
#include <stdlib.h>

int porovnej(char *t1, char *t2);
int main()
{
    char* slovo1 = "Abc";
    char* slovo2 = "ab";
    int vys = porovnej(slovo1,slovo2);
    printf("%d",vys);
    return 0;
}

int porovnej(char *t1, char *t2)
{
    while(*t1 != '\0' || *t2 != '\0')
    {
        if(*t1 > *t2)
            return 1;
        else if(*t2 > *t1)
            return -1;
        t2++;
        t1++;
    } return 0;
}
