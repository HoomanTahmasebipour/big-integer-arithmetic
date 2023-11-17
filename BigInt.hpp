/***************************************************************************************************
* Module Name: BigInt Class Definition
*
* Author: Hooman Tahmasebipour
* Date: September, 2023
*
* Module Description:
*	The BigInt class header provides the interface definition for the BigInt Class. Internally, 
*	BigInt splits large numbers into smaller chunks, represented in a vector, which facilitates 
*	various arithmetic operations.
*
* Notes:
*   - The chunk size for breaking down numbers is defined as a macro with a default value of 3.
*   - All internal calculations are performed using vectors, with their string representations
*	  maintained within the object for external usage.
*	- The class provides overloaded constructors for initialization from a string or a vector.
*	- Operator overloading is utilized to provide a more intuitive interface for some operations,
*	  such as multiplication and printing.
*
***************************************************************************************************/

#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define CHUNK_SIZE_DEFAULT 3

class BigInt {
private:
	std::vector<int> bigIntVecChunks;
	std::string bigIntStr;
	int chunkSize;
public:
	// Default constructor, use default string "0" to initialize bigInt
	BigInt() {
		std::string numStr = "0";
		chunkSize = CHUNK_SIZE_DEFAULT;
		bigIntStr = "0";
		SetBigIntVecChunksFromStr(bigIntStr);
	}

	// Overloaded constructor 1, use input string to initialize bigInt
	BigInt(std::string numStr) {
		chunkSize = CHUNK_SIZE_DEFAULT;
		bigIntStr = numStr;
		SetBigIntVecChunksFromStr(numStr);
	}

	// Overloaded constructor 2, use input vector to initialize bigInt
	BigInt(std::vector<int>& numVec) {
		chunkSize = CHUNK_SIZE_DEFAULT;
		SetBigIntStrFromVec(numVec);
		bigIntVecChunks = numVec;
	}

	// Operator overrides for printing to terminal using <<
	friend std::ostream& operator<<(std::ostream& os, const std::vector<int>& bigIntVectoredChunks);
	friend std::ostream& operator<<(std::ostream& os, const BigInt& bigInt);

	// Functions to fetch class parameters
	std::vector<int> GetBigIntVectoredChunks();
	std::string GetBigIntFullString();
	int GetChunkSize();
	
	// Functions to set class parameters
	void SetBigIntVecChunksFromStr(std::string fullNumStr);
	void SetBigIntStrFromVec(std::vector<int>& numVec);
	void SetChunkSize(int newChunkSize);

	// Functions for solving the numerical problem, requiring one for multiplication and one for exponentiation
	std::vector<int> multiply(const std::vector<int>& num1, const std::vector<int>& num2) const;
	BigInt powerOf(const int exponent) const;

	// Operator override for multiplication
	BigInt operator*(const BigInt& rhsOfMultiplyOperator) const;
};