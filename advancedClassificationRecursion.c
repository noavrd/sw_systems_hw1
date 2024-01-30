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

int reverseNum (int num)  // פונקציית עזר לפלינדרום שמחזירה את המספר הפוך
{
    int reverse = 0;
    while(num!=0)
    {
        int digit = num%10;
        reverse = reverse *10 + digit;
        num = num/10;
    }
    return reverse;

}

int isPalindromehelper(int num,int temp)  //פונקציית עזר לפולינדרום 
{
                             
    if(num == temp)   // אם המספר ההפוך שווה למספר הרגיל
    {
        return 1;
    }
    if (num%10 != temp%10)
    {
       return 0;
    }
    else return isPalindromehelper (num/10, temp/10);
}

int isPalindrome(int num) {

    int temp = reverseNum(num); 
    return isPalindromehelper (num,temp);
    
}
