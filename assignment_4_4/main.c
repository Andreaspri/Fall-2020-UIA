#include <stdio.h>
int main()
{
    char string[20];
    int c = 0, count[26] = {0}, x;

    gets(string);

    while (string[c] != '\0') {

        if (string[c] >= 'a' && string[c] <= 'z') { //Bare kontrolerer at bokstaven er mellom a og z og ike æ ø å
            x = string[c] - 'a';                    // Tar verdien til bokstaven i listen og minuser den med a  "97" og får da et tall mellom 0 og 25
            count[x]++;                             // Plusser på 1 på en av indexene mellom 0 og 25. 0 er a og 25 er z.
        }
        c++;
    }
    for (c = 0; c < 26; c++)
        printf("'%c' : %d\n", c + 'a', count[c]);

    return 0;
}

