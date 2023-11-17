/***************************************************************************************************
* Module Name: BigIntArithmeticApp Class Implementation
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description:
*   The BigInt Arithmetic Application offers an interactive command-line interface where users can
*   explore the power of large number arithmetic operations. Utilizing the BigInt class, this 
*   application provides a real-world scenario for testing the BigInt arithmetic operations, 
*   specifically exponentiation. Users are prompted to input a number between a specific range. The 
*   app then calculates the exponentiation of this number to a power derived from its reverse and 
*   measures the time taken for this computation. The results and computation time are then displayed 
*   back to the user. The application continues prompting the user until a negative number is entered.
*
* Notes:
*   - The application uses the BigInt class to handle large number operations, solving the numerical
*     problem C = A ^ B, where A is a number entered by the user and B is A with the digits reverse.
*   - Timing measurements are made using the C++ chrono library to record how long each computation 
*     took.
*   - The app ensures input validity and continues prompting until a valid input is received.
*   - The app continues to run until the user enters -1.
*
***************************************************************************************************/

#include "BigInt.hpp"
#include "BigIntArithmeticApp.hpp"
#include <iostream>
#include <string>
#include <chrono>

void BigIntArithmeticApp::Run() {
    // Prompt the user to enter a number between 0 and 99999, then store it as a string
    int num = 0;
    std::cout << "Enter a number (0 - 99999): ";
    std::cin >> num;
    while (!isValidInput(num)) {
        std::cout << "Input number was outside of specified range." << std::endl << "Enter a number(0 - 99999) : ";
        std::cin >> num;
    }

    // Loop until the user enters a negative number
    while (num >= 0) {
        // Initialize A matrix and its exponent B
        std::pair<std::string, std::string> numStrAndNumRevStr = GetStrAndRevStrFromNum(num);
        BigInt A(numStrAndNumRevStr.first);
        int B = std::stoi(numStrAndNumRevStr.second);

        // Perform C = A^B and time how long it takes
        auto timeStart = std::chrono::high_resolution_clock::now();
        BigInt C = A.powerOf(B);
        auto timeStop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeStop - timeStart);

        // Print the results and the duration
        std::cout << "Result: " << A.GetBigIntFullString() << " ^ " << B << ": " << std::endl << C.GetBigIntFullString() << std::endl;
        std::cout << "This computation took " << duration.count() << " milliseconds to execute." << std::endl;

        // Prepare for the next iteration
        std::cout << "To exit, enter any negative number. Otherwise enter a number (0 - 99999): ";
        std::cin >> num;
        while (!isValidInput(num)) {
            std::cout << "Input number was outside of specified range." << std::endl << "Enter a number(0 - 99999) : ";
            std::cin >> num;
        }
    }
    return;
}

bool BigIntArithmeticApp::isValidInput(int num) {
    // -1 is reserved for exiting the application
    bool ret = true;
    if (num < -1 || num > 99999)
        ret = false;
    return ret;
}

std::pair<std::string, std::string> BigIntArithmeticApp::GetStrAndRevStrFromNum(int num) {
    std::string numStr = std::to_string(num);
    std::string numRevStr = numStr;
    std::reverse(numRevStr.begin(), numRevStr.end());
    return { numStr, numRevStr };
}