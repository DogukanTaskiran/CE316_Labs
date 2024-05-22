#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int call_by_value(int n)
{
    n = n * n;
    return n;
}

void call_by_reference(int *n)
{
    *n = *n + 2;
}

void Q1()
{
    int input;
    printf("Enter the number\n");
    scanf("%d", &input);

    input = call_by_value(input);
    call_by_reference(&input);

    printf("After call_by_value: %d\n", input);
    printf("After call_by_reference: %d\n", input);
}

bool Q2()
{
    int integer1, integer2;
    printf("Enter first integer number\n");
    scanf("%d", &integer1);
    printf("Enter second integer number\n");
    scanf("%d", &integer2);

    int temp;
    if (integer1 > integer2)
    {
        temp = integer2;
        integer2 = integer1;
        integer1 = temp;
    }
    if (integer2 % integer1 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Q3()
{
    int number;

    printf("Enter a number\n");
    scanf("%d", &number);

    int reversed = 0;
    while (number != 0)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    printf("Reversed: %d\n", reversed);
}

void Q4()
{
    int number, guess, attempts = 0;

    srand(time(0));
    number = rand() % 1000 + 1;

    printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess: ");

    do
    {
        scanf("%d", &guess);
        attempts++;

        if (guess < number)
        {
            printf("Too low. Try again: ");
        }
        else if (guess > number)
        {
            printf("Too high. Try again: ");
        }
        else
        {
            printf("Excellent! You guessed the number in %d attempts!\n", attempts);
            if (attempts <= 10)
            {
                if (attempts == 10)
                {
                    printf("Ahah! You know the secret!\n");
                }
                else
                {
                    printf("Either you know the secret or you got lucky!\n");
                }
            }
            else
            {
                printf("You should be able to do better!\n");
            }
        }
    } while (guess != number);
}

int main()
{
    Q1();
    
    if (Q2()) {
        printf("The second number is a multiple of the first number.\n");
    } else {
        printf("The second number is not a multiple of the first number.\n");
    }

    Q3();
    
    char play_again;

    do {
        Q4();
        printf("Would you like to play again (y or n)? ");
        scanf(" %c", &play_again);
    } while (play_again == 'y');
    
    return 0;
}
