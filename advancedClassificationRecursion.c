#include "NumClass.h"

int countNumbersRecursive(int num) {
    if ( num <= 0) {
        return 0;
    } 
    return countNumbersRecursive(num /10) + 1;

}

int checkPowerOfNumRecursive(int totalNumbers, int digit) {
    if (totalNumbers == 0) {
        return 0;
    }

    return digit * checkPowerOfNumRecursive(digit, totalNumbers -1);

}

int armstrongRecursive(int num, int totalNumbers) {
    if (num == 0) {
        return 0;
    }

    int digit = num % 10;
    int digitPow = checkPowerOfNumRecursive(totalNumbers, digit);
    return digitPow + armstrongRecursive(num / 10, totalNumbers);
}

int isArmstrong(int num) {
    int total = 0;
    
    int numSum = num;
    int totalNumbers = 0;

    totalNumbers = countNumbersRecursive(num);

    num = numSum;

   total = armstrongRecursive(num, totalNumbers);

    if (numSum == total) {
        return 1;
    }

    return 0;
}

// int reverseNumRecursive(int num, int totalNumbers) {
//     if (num == 0) {
//         return 0;
//     }

//     return reverseNumRecursive()
// }

int isPalindrome(int num) {

    int originNum = num;
    int totalNumbers = 0;
    int palindromNum = 0;

    totalNumbers = countNumbersRecursive(num);

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