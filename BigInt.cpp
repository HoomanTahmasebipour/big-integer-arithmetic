/***************************************************************************************************
* Module Name: BigInt Class Implementation
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description:
*	This module contains the implementation details of the BigInt class. The BigInt class enables
*	the representation and manipulation of large integers that exceed the capacity of standard
*	integer types. Internally, BigInt splits large numbers into smaller chunks, represented in a
*	vector, which facilitates various arithmetic operations. This module includes methods to retrieve
*	and set internal parameters, as well as core mathematical functions like multiplication and
*	exponentiation. 
*
* Notes:
*   - The class BigInt primarily interacts with its data through chunked vectors. These vectors
*	  store segments of the large number.
*   - The multiplication method uses traditional schoolbook multiplication, adjusted for chunked
*	  data.
*	- The powerOf method implements the Exponentiation by Squaring technique.
*	- Operator overloads are included for intuitive usage of operations like multiplication.
*
***************************************************************************************************/

#include "BigInt.hpp"

// Operator overrides for printing to terminal using <<
std::ostream& operator<<(std::ostream& os, const std::vector<int>& bigIntVectoredChunks) {
    for (int chunk : bigIntVectoredChunks) {
        os << chunk << std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const BigInt& bigInt) {
    os << "BigInt Full String is: " << bigInt.bigIntStr << std::endl;
    os << "BigInt Vectored Chunks are: " << std::endl;
    for (int chunk : bigInt.bigIntVecChunks) {
        os << chunk << std::endl;
    }
    return os;
}

// Functions to fetch class parameters
std::vector<int> BigInt::GetBigIntVectoredChunks() {
    return this->bigIntVecChunks;
}
std::string BigInt::GetBigIntFullString() {
    return this->bigIntStr;
}
int BigInt::GetChunkSize() {
    return this->chunkSize;
}

// Functions to set class parameters
void BigInt::SetBigIntVecChunksFromStr(std::string numStr) {
    // First make sure that numStr has a length of 3
    while (numStr.size() % chunkSize != 0) {
        numStr = "0" + numStr;
    }

    // Next, split numStr into chunks of three digits and store it in bigIntVectoredChunks
    for (int i = 0; i < numStr.size(); i += chunkSize) {
        bigIntVecChunks.push_back(std::stoi(numStr.substr(i, chunkSize)));
    }
}
void BigInt::SetBigIntStrFromVec(std::vector<int>& numVec) {
    bigIntStr = "";
    for (int chunk : numVec) {
        std::string chunkStr = std::to_string(chunk);
        while ((chunk != numVec[0]) && (chunkStr.size() % chunkSize != 0)) {
            chunkStr = "0" + chunkStr;
        }
        bigIntStr += chunkStr;
    }
}
void BigInt::SetChunkSize(int newChunkSize) {
    this->chunkSize = newChunkSize;
}

// Functions for solving the numerical problem, requiring one for multiplication and one for exponentiation
// Note: Adding the const keyword to ensure that this object is not altered, nor are the two integer vectors
//       that are being passed in.
/* "Chunks" Multiplication Algorithm Overview:
*   - The below function uses the grade-school approach to multiplication, which has been modified to 
*     work with integer vectors.
*   - The flow of operations is exactly the same as how grade-school multiplication is performed, with 
*     the difference being that each multiplied entity has a number of digits defined by the CHUNK_SIZE_DEFAULT
*     parameter defined in BigInt.hpp. 
*/
std::vector<int> BigInt::multiply(const std::vector<int>& num1, const std::vector<int>& num2) const {
    size_t num1VectorSize = num1.size();
    size_t num2VectorSize = num2.size();
    std::vector<int> result(num1VectorSize + num2VectorSize, 0);

    for (int i = num2VectorSize - 1; i >= 0; i--) {
        for (int j = num1VectorSize - 1; j >= 0; j--) {
            int positionOfCarryOver = i + j;
            int positionOfMultiplication = i + j + 1;
            int multiplicationOfChunks = num1[j] * num2[i];
            multiplicationOfChunks += result[positionOfMultiplication];

            result[positionOfMultiplication] = multiplicationOfChunks % (int)std::pow(10, chunkSize);
            result[positionOfCarryOver] += multiplicationOfChunks / (int)std::pow(10, chunkSize);
        }
    }

    // Remove leading zero elements from the result vector.
    // I.e if result = [0, 0, 0, 1, 123], after this it will be result = [1, 123]
    // Find the first non-zero element using a simple lambda function
    std::vector<int>::iterator it = std::find_if(result.begin(), result.end(), [](int num) {
        return num != 0;
        });

    // Erase the elements before the first non-zero element
    if (it != result.end()) {
        result.erase(result.begin(), it);
    }
    return result;
}

/* Exponentiation by Squaring technique:
*   This approach takes advantage of the fact that any number can be represented as a sum of powers of 
*   two. Further, it is a recursive implementation that drastically reduces the number of computations.
*/
BigInt BigInt::powerOf(const int exponent) const {
    int halfOfExp = exponent / 2;
    BigInt result("1");
    if (exponent == 0) {
        return result;
    }

    BigInt powerToHalfOfExp = this->powerOf(halfOfExp);

    if (exponent % 2 == 0) {
        // even exponent
        result = powerToHalfOfExp * powerToHalfOfExp;
        return result;
    }
    else {
        // odd exponent
        result = powerToHalfOfExp * powerToHalfOfExp;
        result = (*this) * result;
        return result;
    }
    return result;
}

// Operator override for multiplication
BigInt BigInt::operator*(const BigInt& rhsOfMultiplyOperator) const {
    std::vector<int> multiplyResult = multiply(this->bigIntVecChunks, rhsOfMultiplyOperator.bigIntVecChunks);
    return BigInt(multiplyResult);
}