/***************************************************************************************************
* Module Name: BigIntArithmeticApp Class Definition
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description:
*   The BigInt Arithmetic Application Header provides the interface definition for the BigIntArithmeticApp
*   class. 
*
* Notes:
*   - The main function 'Run' initiates the application loop, interacting with the user until they decide to exit.
*   - The 'isValidInput' function ensures that the user inputs a number within the specified range.
*   - 'GetStrAndRevStrFromNum' is an utility function that extracts the string representation of a number 
*     and its reverse.
*
***************************************************************************************************/

#pragma once
#include "BigInt.hpp"

class BigIntArithmeticApp {
public:
    BigIntArithmeticApp() {}

    void Run();

    bool isValidInput(int num);

    std::pair<std::string, std::string> GetStrAndRevStrFromNum(int num);
};