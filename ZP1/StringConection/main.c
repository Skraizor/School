#include <stdio.h>
#include <stdlib.h>

char *Connect(char* a, char* b);

int main()
{
    char* a = "Ahoj iaiua\cs n asiuh dhLKDA Id KLJD SBD LFPiuh";
    char* b = "blahblahblahblahblah";
    char* c;
    c = Connect(a,b);
    printf("Spojeni slov \"%s\" a \"%s\" je \"%s\".\n",a,b,c);
    return 0;
}

char *Connect(char* a, char* b)
{
    int i,j,counter,delkaA,delkaB;
    delkaA = strlen(a);
    delkaB = strlen(b);
    counter = 0;
    char *vys = (char*)malloc((delkaA+delkaB+1)*sizeof(char));
    for(i = 0; i != delkaA;i++)
    {
        vys[i] = a[i];
    }
    for(j = delkaA; j != delkaA+delkaB;j++)
    {
        vys[j] = b[counter];
        counter++;
    }
    vys[j] = '\0';
    return vys;
}
