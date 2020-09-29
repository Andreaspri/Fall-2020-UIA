#include <stdio.h>



int minimum(float min){
    printf("Minimum: %g\n",min);
}
int maximum(float max){
    printf("Maximum: %g\n",max);
}
float average(float sum){
    printf("Average: %g\n",sum/10);
}
float median(float array[]){
    printf("Median: %g\n",(array[4]+array[5])/2);
}
int sum(float summ){
    printf("Sum: %g\n",summ);
}

int main()
{
    float min=1000,max,summ,hey,array[10];
    int p=0,n,i=0;
    while(i<10){
        scanf("%g",&array[i]);
        summ += array[i];
        if (array[i]<min){
            min = array[i];
        }
        if(array[i]>max){
            max = array[i];
        }
        i++;
    }
    while(p<10) {
        n = p;
        while (n < 10){
            if (array[p]>array[n]){
                hey = array[p];
                array[p]=array[n];
                array[n] = hey;
            }
            n++;
        }
        p++;
    }
    minimum(min);
    maximum(max);
    average(summ);
    median(array);
    sum(summ);
    printf("Sorted:");
    for(i=0;i<10;i++){
        printf(" ");
        printf("%g",array[i]);
    }
    printf("\n");

    return 0;
}