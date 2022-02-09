//write include statements
#include "variables.h"
#include <iostream>


//write namespace using statement for cout
using std::cin; using std::cout;


int main()
{
	int num;
    cout<<"Enter a number: ";
    cin>>num;

    int result;
    result = multiply_number(num);
    cout<<"Result is: "<<result<<"\n";

    int num1 = 4;
    result = multiply_number(num1);
    cout<<"Result is: "<<result<<"\n";

    return 0;

}
