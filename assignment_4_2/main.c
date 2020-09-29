#include <stdio.h>
#include <ctype.h>



char input[100],new1[10],new2[10];
int i,p,o=0;




int main() {


    scanf("%s", input);
    printf("The string in lowercase is '");
    while (input[i]) {
    putchar(tolower(input[i]));
    i++;
    }
    printf("'");
    printf("\n");
    printf(("The string in uppercase is '"));
    while(input[p]){
        putchar(toupper(input[p]));
        p++;
    }
    printf("'");
    printf("\n");

    while(o<p/2){
        new1[o]=input[o];
        o++;
    }
    p/=2;
    o=0;
    while(p<i){
        new2[o]=input[p];
        p++;
        o++;
    }

    i=0;
    printf("The string split in two is '");
    for(int q=0;new1[q];q++){
        printf("%c", new1[q]);
    }
    printf(" - ");
    for(int q=0; new2[q]; q++) {
        printf("%c", new2[q]);
    }
    printf("'");
    return 0;
}
