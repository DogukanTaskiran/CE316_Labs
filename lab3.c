#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_NUMBERS 20
#define ARRAY_SIZE 20
#define SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Q3() {
    int arr[ARRAY_SIZE];
    srand(time(0)); // Random number generator

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1; // Random numbers between 1 and 100
    }

    printf("Original array:\n");
    printArray(arr, ARRAY_SIZE);

    bubbleSort(arr, ARRAY_SIZE);

    printf("Sorted array:\n");
    printArray(arr, ARRAY_SIZE);
}

void Q2() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    int num;

    printf("Enter 20 numbers between 10 and 100:\n");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        scanf("%d", &num);
        bool isDuplicate = false;

        for (int j = 0; j < count; j++) {
            if (numbers[j] == num) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            numbers[count++] = num;
            printf("%d ", num);
        }
    }
    printf("\n");
}

void printArrayPointer(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Q1() {
    int A[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int* p;
    int size = sizeof(A) / sizeof(A[0]);

    // Part a
    p = A; // Initialize p to point to the initial element of array A
    printf("Initial:\np = %p, *p = %d\n", (void*)p, *p);
    printf("A = ");
    printArrayPointer(A, size);

    *p += 5; // Increment *p by 5
    printf("\nAfter incrementing *p by 5:\np = %p, *p = %d\n", (void*)p, *p);
    printf("A = ");
    printArrayPointer(A, size);

    p += 3; // Increment p by 3
    printf("\nAfter incrementing p by 3:\np = %p, *p = %d\n", (void*)p, *p);
    printf("A = ");
    printArrayPointer(A, size);

    // Part b
    p = A;
    printf("\nArray elements and their addresses:\n");
    while (p < A + size) {
        printf("Address: %p, Value: %d\n", (void*)p, *p);
        p++;
    }

    // Part c
    printf("\nOvershooting target (printing 30 times):\n");
    p = A;
    for (int i = 0; i < 30; i++) {
        printf("Address: %p, Value: %d\n", (void*)p, *p);
        p++;
    }
}

void Q4() {
    bool isPrime[SIZE];
    for (int i = 0; i < SIZE; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false; 

    for (int p = 2; p * p < SIZE; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i < SIZE; i += p) {
                isPrime[i] = false;
            }
        }
    }

    printf("Prime numbers between 1 and 999:\n");
    for (int i = 2; i < SIZE; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    Q1();
    Q2();
    Q3();
    Q4();
    return 0;
}
