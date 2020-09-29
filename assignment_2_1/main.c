#include <stdio.h>
#include <stdbool.h>

int main() {

    float count;
    float sum=0;
    float average;
    float input;

    while (true) {
        scanf("%g", &input);
        sum += input;
        if (input == 0){
            average = sum / count;
            printf("Count: %g\n", count);
            printf("Sum: %g\n", sum);
            printf("Average: %g\n", average);
            break;
        }
        count++;


    }

}

