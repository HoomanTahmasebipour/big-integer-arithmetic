/***************************************************************************************************
* Module Name: Unit Tests for BigIntArithmeticApp Class Methods using the Doctest Framework
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description:
*   This module focuses on testing the functionality of the BigIntArithmeticApp class. The test cases
*   are built upon the Doctest framework and primarily concentrate on the validation of user inputs
*   and the extraction of a number and its reverse as string representations.
*
* Notes:
*   - The module is a suite of test cases designed to validate the two methods in the BigIntArithmeticApp 
*     class that provide an output given an input: 'isValidInput' and 'GetStrAndRevStrFromNum'.
*   - Test cases address boundary conditions, typical input values, and edge cases to ensure the correctness
*     and robustness of the application.
*
***************************************************************************************************/

#include "BigIntArithmeticApp.hpp"
#include "doctest.h"

TEST_CASE("BigIntArithmeticApp isValidInput input number is less than -1...") {
    int num = -2;
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == false);
}

TEST_CASE("BigIntArithmeticApp isValidInput input number greater than 99999...") {
    int num = 100000;
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == false);
}

TEST_CASE("BigIntArithmeticApp isValidInput input number is between 0 and 99999...") {
    int num = 123;
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == true);
}

TEST_CASE("BigIntArithmeticApp isValidInput input number is -1...") {
    int num = -1; // -1 is used to exit application, so it is a valid input
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == true);
}

TEST_CASE("BigIntArithmeticApp isValidInput input number is 0...") {
    int num = 0;
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == true);
}

TEST_CASE("BigIntArithmeticApp isValidInput input number is 99999...") {
    int num = 99999;
    BigIntArithmeticApp app;
    REQUIRE(app.isValidInput(num) == true);
}

TEST_CASE("BigIntArithmeticApp GetStrAndRevStrFromNum stores and reverses input number...") {
    int num = 123;
    BigIntArithmeticApp app;
    REQUIRE(app.GetStrAndRevStrFromNum(num).first == "123");
    REQUIRE(app.GetStrAndRevStrFromNum(num).second == "321");
}