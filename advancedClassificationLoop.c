#include "NumClass.h"

int isArmstrong(int num) {
    int total = 0;
    int numSum = num;
    int totalNumbers = 0;

    while (num > 0) {
        totalNumbers++;
        num /= 10;
    }

    num = numSum;

    while (num > 0) {
        int digit = num % 10;
        int digitPow = 1;

        for (int i = 1; i <= totalNumbers; i++) {
            digitPow *= digit;
        }

        total += digitPow;
        num /= 10;
    }

    if (numSum == total) {
        return 1;
    }

    return 0;
}

int isPalindrome(int num) {

    int originNum = num;
    int totalNumbers = 0;
    int palindromNum = 0;

    while (num > 0) {
        totalNumbers++;
        num /= 10;
    }

    num = originNum;

    while (num > 0) {
        int findFirst = 1;
        for (int i = 1; i < totalNumbers; i++) {
            findFirst *= 10;
        }

        findFirst *= (num % 10);
        palindromNum += findFirst; 
        totalNumbers--;
        num /= 10;
    }

    if (palindromNum == originNum) {
        return 1;
    }

    return 0;
}