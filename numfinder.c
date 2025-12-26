#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define num_elements  1000000
int current_lowest_number = 99999999;

void lowestNumber(int array[], int length){

    for(int i = 0; i < length; i++){

        if(array[i] < current_lowest_number){
            current_lowest_number = array[i];
        }
    }
    

}


int main(){

    srandom(42);
    int array[num_elements];

    for(int i = 0 ; i < num_elements; i++){
       array[i] = random() & 1;
       //printf("%d \n", array[i]);
    }

    //int array[num_elements] = {5,10,1,3,2,5,4};

    lowestNumber(array, num_elements);

    printf("lowest Number %d \n",current_lowest_number);

}