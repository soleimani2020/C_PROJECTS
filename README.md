A Happy Number is a number where repeatedly replacing the number with the sum of the squares of its digits eventually results in 1. If a number does not lead to 1 and instead forms a cycle, it is classified as a Sad Number.
This is an implementation of the Happy Number algorithm using Floyd's Tortoise and Hare cycle detection algorithm. 

1. Calculation:
Purpose: This function calculates the sum of the squares of the digits of a number. It performs one iteration of transforming a number into the next value in the sequence.
Logic://
Extract the digits of the number using the modulo operator % 10.
Square each digit and add it to the cumulative sum.
Remove the last digit of the number by integer division by 10.
Return Value: Returns the sum of the squares of digits.

2. isHappyNumber
Purpose: This function determines if the given number is happy by detecting cycles in the sequence of transformations using Floyd's Tortoise and Hare cycle detection algorithm.
Logic:
Two pointers (slow and fast) start at the given number.
The slow pointer advances by one step per iteration (computes the sum of the squares once).
The fast pointer advances by two steps per iteration (computes the sum of the squares twice).
If slow and fast pointers meet at 1, the number is happy.
If slow and fast pointers meet at any value other than 1, a cycle is detected, indicating the number is sad.
Return Value:
Returns 1 (true) if the number is happy.
Returns 0 (false) if the number is sad.

3. main
Purpose: Serves as the entry point of the program.
Logic:
Prompts the user to input a number.
Calls the isHappyNumber function to determine if the number is happy or sad.
Prints the result to the user.
   
   
