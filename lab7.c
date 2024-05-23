#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int MAX = 3;
int PRODUCT_COUNT = 0;

pthread_mutex_t mutex;

void *producer(void *vargp)
{

    int sleep_time;

    printf("\n hello. i am PRODUCER. \n");

    while (1)
    {

        if (PRODUCT_COUNT >= MAX)
        {
            printf("\n too much product. PRODUCER sleeping for 2 seconds... \n");
            sleep(2);
        }

        pthread_mutex_lock(&mutex);

        if (PRODUCT_COUNT < MAX)
        {
            PRODUCT_COUNT++;
            printf("\n PRODUCER increased product count to: %d", PRODUCT_COUNT);
        }
        else
        {
            printf("\n too much product. not enough space. \n");
        }

        pthread_mutex_unlock(&mutex);

        sleep_time = 1 + rand() % 2;
        printf("\n PRODUCER is tired. sleeping for %d seconds... \n", sleep_time);
        sleep(sleep_time);
    }
}

void *consumer(void *vargp)
{

    printf("\n hello. i am CONSUMER. \n");

    while (1)
    {

        if (PRODUCT_COUNT <= 0)
        {
            printf("\n not enough product. CONSUMER sleeping for 3 seconds... \n");
            sleep(3);
        }

        pthread_mutex_lock(&mutex);

        if (PRODUCT_COUNT > 0)
        {
            PRODUCT_COUNT--;
            printf("\n CONSUMER decreased product count to: %d", PRODUCT_COUNT);
        }
        else
        {
            printf("\n not enough product to consume. \n");
        }

        pthread_mutex_unlock(&mutex);
    }
}

int numbers[5];

void SelectionSort(int A[], int size)
{
    int i, j, Imin, temp;
    for (i = 0; i < size - 1; i++)
    {
        Imin = i;
        for (j = i + 1; j < size; j++)
        {
            if (A[j] < A[Imin])
            {
                Imin = j;
            }
        }
        temp = A[Imin];
        A[Imin] = A[i];
        A[i] = temp;
    }
}

void *getNumbers(void *vargp)
{
    int j;
    printf("Please Enter 5 numbers\n");
    for (j = 0; j < 5; j++)
        scanf("%d", &numbers[j]);
}

void *sorting(void *vargp)
{
    int n;
    printf("Sorting numbers\n");
    n = sizeof(numbers) / sizeof(numbers[0]);
    SelectionSort(numbers, n);
}

void *printResult(void *vargp)
{
    int i;
    printf("Sorted numbers\n");
    for (i = 0; i < 5; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}

void Q1()
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    pthread_create(&t1, NULL, getNumbers, (void *)&t1);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, sorting, (void *)&t2);
    pthread_join(t2, NULL);

    pthread_create(&t3, NULL, printResult, (void *)&t3);
    pthread_exit(NULL);
}

void Q2()
{

    pthread_mutex_init(&mutex, NULL);

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, producer, (void *)&t1);
    pthread_create(&t2, NULL, consumer, (void *)&t2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_exit(NULL);

    pthread_mutex_destroy(&mutex);
}
int main()
{
    Q1();
    Q2();
    return 0;
}