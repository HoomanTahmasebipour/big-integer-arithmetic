/***************************************************************************************************
* Module Name: Unit Tests for BigInt Class Methods using the Doctest Framework
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description: 
*   This module performs unit testing for the BigInt class. The BigInt class is designed to handle 
*   large integer arithmetic operations using string representations. The tests here are designed 
*   to validate various features and capabilities of the class, such as the default constructor 
*   behavior, string-based initialization, arithmetic operations, and power calculations.
*
* Notes:
*   - This module uses the "doctest" framework for writing the test cases.
*   - Test cases are designed to cover both common and edge-case scenarios.
*   - The edge case of 99999 is not included as a test case in this unit test as the result is too 
*     large of a string, and thus its value is truncated by the compiler. It was run through the 
*     application manually, and it was seen that after 27 minutes the correct answer is produced 
*     for 99999 ^ 99999. 
*     
***************************************************************************************************/

#include "BigInt.hpp"
#include "doctest.h"

TEST_CASE("BigInt Default Constructor initializes to zero...") {
    BigInt bigInt;
    REQUIRE(bigInt.GetBigIntFullString() == "0");
    REQUIRE(bigInt.GetBigIntVectoredChunks().size() == 1);
    REQUIRE(bigInt.GetBigIntVectoredChunks()[0] == 0);
}

TEST_CASE("BigInt Constructor initializes from string...") {
    BigInt bigInt("12345");
    REQUIRE(bigInt.GetBigIntFullString() == "12345");
    REQUIRE(bigInt.GetBigIntVectoredChunks().size() == 2);
    REQUIRE(bigInt.GetBigIntVectoredChunks()[0] == 12);
    REQUIRE(bigInt.GetBigIntVectoredChunks()[1] == 345);
}

TEST_CASE("BigInt Constructor initializes from vector...") {
    std::vector<int> vec = { 12, 345 };
    BigInt bigInt(vec);
    REQUIRE(bigInt.GetBigIntFullString() == "12345");
    REQUIRE(bigInt.GetBigIntVectoredChunks() == vec);
}

TEST_CASE("BigInt A * B with A = B = 123, 123 * 123...") {
    BigInt A("123");
    BigInt B("123");
    BigInt C = BigInt(A * B);
    REQUIRE(C.GetBigIntFullString() == "15129");
}

TEST_CASE("BigInt C = A ^ 2 with A = 123, C = 123 ^ 2...") {
    BigInt A("123");
    BigInt result = A.powerOf(2);
    REQUIRE(result.GetBigIntFullString() == "15129");
}

TEST_CASE("BigInt C = A ^ B with B = rev(A) and A = 123, C = 123 ^ 321...") {
    std::string testStr = "123";
    std::string revTestStr = testStr;
    std::reverse(revTestStr.begin(), revTestStr.end());
    BigInt A(testStr);
    BigInt result = A.powerOf(std::stoi(revTestStr));
    REQUIRE(result.GetBigIntFullString() ==
        "72367033806371673149109894141163778628811792657571658906010558390395870363798401744095280686155507736404921657070284961721828960592977909542637098897697223102622628566787654091327825453991595140205701412961364188732408936197890553699715836951569999800431957769217006743321026257517932764164662319487914962533302741368207211189494615326552790667720411285474162636765168907211924134973374304496019635376665858559941735703924836467756917247995469583487467791524582153744522107597865277798136080074161485280424274076931083994487111719562249702540362855712911132265966235754355353516703339043001506118520760359577737869472018617942120590873170710805078696371738906375721785723"
    );
}