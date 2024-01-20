#include "NumClass.h"

int isPrime(int num) {
    if (num == 0 || num ==1 ){
        return 0;
    }

    for (int i = 2; i <= num / 2 ; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int isStrong(int num)  {
    int totalFactorial = 0;
    int numSum = num;
    
    while (num > 0) {
        int digit = num % 10;
        int digitFactorial = 1;
        for (int i = 1; i <= digit; i++) {
            digitFactorial *= i;
        }

        totalFactorial += digitFactorial;
        num /= 10;
    }

    if (totalFactorial == numSum) {
        return 1;
    }

    return 0;
}