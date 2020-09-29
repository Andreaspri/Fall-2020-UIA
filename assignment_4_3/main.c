#include <stdio.h>
#include <string.h>

char liste[20];
char liste2[20];

int main() {
    gets(liste);
    gets(liste2);
    if(strcmp(liste, liste2)==0)
        printf("The strings are equal\n");
    else
        printf("The strings are not equal\n");
    if(strstr(liste,liste2) != NULL)
        printf("It is a substring!");
    else if(strstr(liste2,liste) != NULL)
        printf("It is a substring!");
    else
        printf("It is not a substring!");



    return 0;
}
