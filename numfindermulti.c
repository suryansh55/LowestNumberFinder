#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


#define NTHREADS 2
#define num_elements  1000000
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int current_lowest_number = 99999999;


struct ThreadArgs {
    int* array;
    int size;
};


void *lowestNumber(void *arguments){
    struct ThreadArgs *args = (struct ThreadArgs *)arguments;
    int* array = args->array;
    int size = args->size;

    for(int i = 0; i < size; i++){

        if(array[i] < current_lowest_number){
            pthread_mutex_lock( &mutex1 );
            current_lowest_number = array[i];
            pthread_mutex_unlock( &mutex1 );
        }
    }
    free(args);
    free(args->array);

}


int main(){

    srandom(42);
    int array[num_elements];

    for(int i = 0 ; i < num_elements; i++){
       array[i] = random() & 1;
       //printf("%d \n", array[i]);
    }
    pthread_t thread_id[NTHREADS];
    //lowestNumber(array, 6);
    int counter = 0;

    /*
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < num_elements/2; j++){
            newarray[j] = array[counter];
            counter++;
            printf("%d\n", newarray[j]);
        }
        
    }
       */

    for(int i=0; i < NTHREADS; i++)
    {
        struct ThreadArgs *args = malloc(sizeof(struct ThreadArgs));
        //args->array = array[i:];
        args->size = num_elements/NTHREADS;
        args->array = malloc(args->size * sizeof(int)); 
        for(int j = 0; j < num_elements/NTHREADS; j++){
             args->array[j]=array[counter];
             counter++;
        }

        pthread_create( &thread_id[i], NULL, lowestNumber, (void *)args);
    }

    for(int j=0; j < NTHREADS; j++)
    {
      pthread_join( thread_id[j], NULL); 
    }

    
    printf("lowest Number %d \n",current_lowest_number);

}