#include <stdio.h>
#include <limits.h>

void q1()
{
    printf("Enter 10 integers\n");
    int max1 = INT_MIN, max2 = INT_MIN;
    int input;

    for (int x = 0; x < 10; x++)
    {
        printf("Enter number\n");
        scanf("%d", &input);

        if (input > max1)
        {
            max2 = max1;
            max1 = input;
        }
        else if (input > max2)
        {
            max2 = input;
        }
    }

    printf("Max1: %d\n", max1);
    printf("Max2: %d\n", max2);
}

void q2()
{
    int input;
    int oddTotal = 0;
    int evenTotal = 1;
    int oddCount = 0;
    int total = 0;

    while (1)
    {
        printf("Enter input\n");
        scanf("%d", &input);

        if (input <= 0)
        {
            break;
        }

        total++;
        if (input % 2 == 0)
        {
            evenTotal *= input;
        }
        else
        {
            oddCount++;
            oddTotal += input;
        }
    }

    if (oddCount > 0)
    {
        printf("Average of odd numbers = %d\n", oddTotal / oddCount);
    }
    else
    {
        printf("No odd numbers were entered.\n");
    }
    printf("Product of even numbers = %d\n", evenTotal);
    printf("Total numbers you entered = %d\n", total);
}

void q3()
{
    int x = 1;
    while (x > 0)
    {
        x *= 2;
        printf("%d\n", x);
    }
}

void q4()
{
    float pi = 0.0;
    float temp;
    int term, i = 1;

    printf(" How many terms do you want to use? ");
    scanf("%d", &term);

    for (i = 1; i <= term; i++)
    {
        temp = 4.0 / (2.0 * i - 1.0);
        if (i % 2 == 0)
            temp *= -1;
        printf("\n i = %d, temp = %f", i, temp);
        pi += temp;
        printf("\n intermediate pi = %f \n", pi);
    }

    printf("\n\n final pi = %f \n", pi);
}
int main()
{

    q1();

    q2();

    q3();

    q4();

    return 0;
}
