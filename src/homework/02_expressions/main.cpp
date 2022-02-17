//write include statements
#include<iostream>
#include"expressions.h"

//write namespace using statement for cout

using std::cin; using std::cout;


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
    // input

    double meal_amount, tip_rate, tip_amount, tax_amount, total;
    cout << "Please enter the meal amount: ";
    cin >> meal_amount;
    tax_amount = get_sales_tax_amount(meal_amount);
    cout << "Please enter the Tip Rate";
    cin >> tip_rate;

    // Process
    tip_amount = get_tip_amount(meal_amount, tip_rate);
    total = meal_amount+tax_amount+tip_amount;


    // Output
    cout<<"Meal Amount: ";
    printf("%16f\n",meal_amount);
    cout<<"Sales Tax: ";
    printf("%18f\n",tax_amount);
    cout<<"Tip Amount: ";
    printf("%17f\n",tip_amount);
    cout<<"-------------------" << "\n";
    cout<<"Total: ";
    printf("%22f\n",total);
	return 0;
}
