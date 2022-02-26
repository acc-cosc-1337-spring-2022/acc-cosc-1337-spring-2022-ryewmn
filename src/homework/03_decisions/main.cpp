#include<iostream>
#include "decisions.h"
using std::cout; using std:cin; using std:string;

int main()
{
    // Declaration of Variables
    int menu;
    int grade;

    cout <<"\n\t Main Menu \t\n";
    cin >> menu;

    if (menu == 1 || menu == 2){
        cout <<"Enter a grade between 0-100:";
        cin>>grade;
    }
    switch(menu){
        case 1:
            cout <<"grade"<<"converts to letter grade" << get_letter_grade_using_if(grade);
            break;

        case 2:
            cout<<"grade"<<"converts to letter grade: "<< get_letter_grade_using_switch(grade);
            break;

        case 3:
        case 0:
            cout<<"End of program... ";
            break;
        default:
            cout<<"Menu choice must be between 1-3. \nEnding the program...";

    }
    return 0;





}