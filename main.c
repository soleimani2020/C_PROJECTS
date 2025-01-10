// Online C compiler to run C program online
#include <stdio.h>

// Function to calclulate the sum of squares of digits of a number

int Calculation(int num){

    int sum = 0;
    while (num != 0){
        int last_digit = num % 10;         // Find   the last digit
        sum +=  last_digit*last_digit;    // Square the last digit
        num = num /10;                     // Remove the last digit
    }
    return sum;
}



// Function to check if a number is a Happy Number
int isHappyNumber(int num){

    int slow = num , fast = num;

    // cycle detection algorithm

    do {
        slow = Calculation(slow);               // Move slow by one step
        fast = Calculation(Calculation(fast)); // Move fast by two steps
    } while (slow != fast);

    // The loop terminates when either:
    // 1. The pointers converge at 1
    // 2. The pointers converge at some other number (cycle)

    // After exiting the loop, the function checks if the value of slow is 1.
    return (slow==1);
}


int main() {
    int n;
    printf("Please enter a number:\n");
    scanf("%d", &n);

    // Calculate sum of squares of digits
    // int sum = sumOfSquaresOfDigits(n);
    // printf("The sum of squares of digits is: %d\n", sum);

    // Check if the number is a Happy Number
    if (isHappyNumber(n)) {
        printf("The number is happy, hurrah!\n");
    } else {
        printf("Ummm, the number is sad!\n");
    }

    return 0;
}
















