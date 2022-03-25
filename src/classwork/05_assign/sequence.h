#include <string>

// Function signatures
double get_gc_content(const std::string dna);
std::string get_dna_complement(std::string dna);
std::string reverse_string(std::string dna);



// Menu function signatures
void run_it_menu();
void display_menu();
void menu_handler(int choice);


// Function signature for string input
std::string get_dna_string();


// Function for validating the string
bool validate_dna_string(std::string dna);

// For display_content that takes one double and one string params
void display_content(double contents, std::string dna);

// For display_content two string params
void display_content(std::string contents, std::string dna);


