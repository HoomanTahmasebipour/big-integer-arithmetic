/***************************************************************************************************
* Module Name: Entrypoint for BigInt Arithmetic Application
* 
* Author: Hooman Tahmasebipour
* Date: September, 2023
* 
* Module Description: 
*   This is the entry point to the BigInt Arithmetic Application. This application solves the numerical
*   problem defined by: C = A ^ B , when A is a number entered by the user and B is A with its digits reversed.
*
*   The main function performs two tasks:
*       1. It runs the developed unit tests under the Doctest framework to ensure the correctness 
*          and reliability of the components within the overall software.
*       2. It initiates the BigInt Arithmetic Application where users can interact with the command
*          line, entering a value for A and receiving the resulting value for C in addition to information
*          regarding how long the computation takes.
***************************************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "BigIntArithmeticApp.hpp"

#include "BigIntTest.cpp"
#include "BigIntArithmeticAppTest.cpp"

int main() {
    // Run unit test framework
    doctest::Context context;
    int res = context.run(); // run all tests

    if (context.shouldExit()) // if the tests shouldn't continue
        return res;          // propagate the result of the tests

    // Begin application
    BigIntArithmeticApp app;
    app.Run();

    return res;
}