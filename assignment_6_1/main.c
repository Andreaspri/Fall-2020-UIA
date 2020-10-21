#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int compare(const void *int1,const void *int2)
{
    const int *int11 = int1;
    const int *int22 = int2;
    return *int11 - *int22;
}

void print_list(int *array,int count)
{
    for(int i=0;i<count;i++)
        printf("%i ",array[i]);
   printf("\n");
}



int main() {
    int count=0;
    printf("How many integers do you want to enter? ");
    scanf("%i",&count);
        getchar();
    if(count == 0){
        printf("No numbers were given");
        return 0;
    }
    int* array = malloc(count * (sizeof(int)));
    memset(array,0,count * sizeof(int));
    for(int i=0;i<count;i++)
        scanf("%i",&array[i]);
    getchar();
    printf("Count: %i\n",count);
    printf("Numbers: ");
    print_list(array,count);
    qsort(array,count,sizeof(int),compare);
    printf("Sorted: ");
    print_list(array,count);
    free(array);
    return 0;
}






