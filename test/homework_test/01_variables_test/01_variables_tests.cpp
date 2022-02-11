#define CATCH_CONFIG_MAIN  // These tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "variables.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

TEST_CASE("Verify product_numbers function")
{
    REQUIRE(multiply_number(2) == 10);
    REQUIRE(multiply_number(10) == 50);



}