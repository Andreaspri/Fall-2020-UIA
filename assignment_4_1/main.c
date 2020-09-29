#include <stdio.h>
#include <stdbool.h>


void string_reverse(char input[],char new[])
{
    printf("The word reversed is '");
    for(int i=0;input[i];i++){
        printf("%c",new[i]);
    }
    printf("'");
}



bool is_palindrome(char input[],char new[],int count)
{
    int p=0;
    for(int q=0;input[q];q++){
        if(input[q]==new[q]){
            p++;
        }
    }
    if(p==count){
        return true;
    }
    else
        return false;
}








int main() {

    char input[20];
    char new[20];
    int count=0,s;
    scanf("%s", input);

    for (int i = 0; input[i]; i++) {
        count++;
    }
    s = count - 1;
    printf("The word contains %i letters\n", count);
    for (int f = 0; input[f]; f++) {
        new[f] = input[s];
        s--;
        if (s < 0)
            break;
    }

    int true_false = is_palindrome(input,new,count);
    if(true_false)
        printf("The word is a palindrome\n");
    else
        printf("The word is not a palindrome\n");
    string_reverse(input,new);

    return 0;
}
