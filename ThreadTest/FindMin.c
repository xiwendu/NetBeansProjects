#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

/* N is the number of threads */
/* row */
#define N 2 
/* column */
#define M 10
int **matrix;

void display(void)
{
    int i, j;
    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            printf("%3d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void * thread_handler(void *thread_id)
{
    int *id = (int *) thread_id;
    int i = *id, j; 
    int min = matrix[i][0];

    for (j=1 ; j<M ; j++) {
        if (matrix[i][j] < min)
            min = matrix[i][j];
    }
    printf("array[%d] min[%d]\n", i, min);
    pthread_exit(NULL);
}

int main(void)
{
    int i, j, ret;
    pthread_t tids[N];
    int ids[N] = {0, 1};
    srand(time(NULL));

    matrix = (int **) malloc (sizeof(int *) * N);
    for (i=0 ; i<N ; i++) 
        matrix[i] = (int *) malloc (sizeof(int) * M);

    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            matrix[i][j] = rand() % 500;
        }
    }

    display();

    for (i=0 ; i<N ; i++) {
        printf("Creating thread #%d \n", ids[i]);
        ret = pthread_create(&tids[i], NULL, thread_handler, &ids[i]);
        if (ret) {
            printf("unable to create thread! \n");
            exit(-1);
        } 
    }

    for (i=0 ; i<N ; i++) {
        pthread_join(tids[i], NULL);
    }

    pthread_exit(NULL);     

    for (i=0 ; i<N ; i++) 
        free(matrix[i]);
    free(matrix);

    return 0;
}
