#include "dna.h"
int factorial(int num)
{
    int sum = 1;
    while(num >0)
    {
        sum = num * sum;
        num -=1;
    }
    return sum;
}

int gcd(int num1, int num2)
{
    int Swap_Placeholder;

    while(num1 != num2)
    {
        if (num1 < num2)
        {
            Swap_Placeholder = num1;
            num1 = num2;
            num2 = Swap_Placeholder;
        }
        else if (num1 > num2)
        {
            num2 -= num1;
        }
    }
    return num1;
}