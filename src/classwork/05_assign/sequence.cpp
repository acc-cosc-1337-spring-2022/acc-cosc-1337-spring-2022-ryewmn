#include "sequence.h"
#include <iostream>
#include <iomanip>
class test{
// Func. block for get_gc_content
double get_gc_content(const std::string dna) {
    double sum = 0;
    double gc_sum = 0;
    for (char ch:dna){
        sum++;
        if (ch == 'G' || ch == 'C'){
            gc_sum++;
        }
    }
    return gc_sum / sum;
}


// Func.block reverse string
std::string reverse_string(std::string dna) {
    std::string temp_st;
    for (int i = dna.length()-1; i >= 0; i--) {
        temp_st += dna[i];
    }
    return temp_st;
}

// Func. block for dna complement
std::string get_dna_complement(std::string dna) {
    dna = reverse_string(dna);
    for (int i = dna.length()-1; i >= 0; i--) {
        switch (dna[i]) {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
        }
    }
    return dna;
}

// Func. block for Menu
void run_it_menu(){
    int choice;
    do {

        display_menu();

        std::cout << "Please enter a number for Gc content or DNA complement: ";
        std::cin >> choice;
        std::cout << "\n";

        menu_handler(choice);
    } while (choice != 3);
}

// Func. block for Displaying the menu
void display_menu() {
    std::cout << "\ntOptions to choose\t\n";
    std::cout << "Opt 1 - Get GC Content\n";
    std::cout <<" Opt 2 - Get DNA Complement\n";
    std::cout <<" Opt 3 - Exit the program\n\n";
}

// Func. block for Menu Handler
void handle_menu_choice(int choice) {
    std::string dna;
    double gc_content;
    std::string dna_complement;

    switch (choice) {
        case 1:
            dna = get_dna_string();
            gc_content= get_gc_content(dna);
            display_contents(gc_content, dna);
            break;
        case 2:
            dna = get_dna_string();
            dna_complement = get_dna_complement(dna);
            display_contents(dna_complement, dna);
            break;
        case 3:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid Entry\n";
    }
}

// Func. block DNA String
std::string get_dna_string(){
    std::string dna_st;
    std::cout << "Enter a DNA string: ";
    std::cin >> dna_st;
    bool invalid = validate_dna_string(dna_st);
    while (invalid) {
        std::cout << "Invalid DNA string. Must contain (A, T, C, or G.) \n\n";
        std::cout << "Enter a DNA string: ";
        std::cin >> dna_st;
        invalid = validate_dna_string(dna_st);
    }
    return dna_st;
}

// Func. block validation of string
bool validate_dna_string(std::string dna) {
    bool invalid = false;
    for(int i = 0; i < dna.length(); i++){
        if (dna[i] != 'A' && dna[i] != 'T' &&
            dna[i] != 'C' && dna[i] != 'G') {
            invalid = true;
        }
    }
    return invalid;
}

// Func. block for double and a string argument
void display_contents(double contents, std::string dna){
    std::cout << "The GC Content of " << dna << " is: " << std::setprecision(2) << (contents *100) << "%" << "\n";
}
// Func. Block for  two string arguments
void display_contents(std::string contents, std::string dna){
    std::cout << "The DNA Complement of " << dna << " is: " << contents << "\n";
}
};