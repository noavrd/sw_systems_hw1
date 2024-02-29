#include <stdio.h>
#include "NumClass.h"

int main()
{
    int start = 0;
    int end = 0;
    int length = end - start + 1;
    int prime[length];
    int strong[length];
    int armstrong[length];
    int palindrom[length];
    int primeINDX = 0;
    int strongINDX = 0;
    int armstrongINDX = 0;
    int palindromINDX = 0;

    printf("enter a number:");
    scanf("%d", &start);

    printf("enter another number:");
    scanf("%d", &end);

    for (int i = start; i <= end; i++)
    {
        if (isPrime(i) == 1)
        {
            prime[primeINDX] = i;
            primeINDX++;
        }

        if (isArmstrong(i) == 1)
        {
            armstrong[armstrongINDX] = i;
            armstrongINDX++;
        }

        if (isStrong(i) == 1)
        {
            strong[strongINDX] = i;
            strongINDX++;
        }

        if (isPalindrome(i) == 1)
        {
            palindrom[palindromINDX] = i;
            palindromINDX++;
        }
    }

    printf("the prime numbers are :");
    for (int i = 0; i < primeINDX; i++)
    {
        printf("%d", prime[i]);
    }

    printf("\n the armstrong numbers are :");
    for (int i = 0; i < armstrongINDX; i++)
    {
        printf("%d", armstrong[i]);
    }

    printf("\n the strong numbers are :");
    for (int i = 0; i < strongINDX; i++)
    {
        printf("%d", strong[i]);
    }

    printf("\n the palindrom numbers are :");
    for (int i = 0; i < palindromINDX; i++)
    {
        printf("%d", palindrom[i]);
    }

    return 0;
}
