# Big Integer Arithmetic Application
Author: Hooman Tahmasebipour
Date: September, 2023
  
This application solves the numerical problem defined by: C = A ^ B, when A is a 
number entered by the user and B is A with its digits reversed, and the input number is between 0 and 
99,999. The exponentation of large numbers using native data types is not supported due to bit overflow
as the value exceeds 2^64 - 1. There are standard libraries that aid in computing this, like GMP and 
Boost. This program is an attempt to solve the same problem from first principles, as nothing more than
a problem-solving exercise in C++.

To run this application, clone the repository into a directory of your choosing and run the bash script
to spin up the docker container (labelled "run_dockerized_solution.sh"). This automated script will attach 
a terminal to the run and enable an interactive session. Alternatively, the solution can be compiled using 
an IDE of your choosing, although be wary of compiler mismatches resulting in phantom errors. Running the 
docker container will not result in this.
  
Notes:
- The current implementation, although not as efficient as the standard libraries like GMP and Boost
  uses two key techniques that had drastic impacts on its time efficiency.
- The first is applied to how multiplication and addition are performed. The foundation of the approach
  is precisely how hand multiplication was taught in grade school, with the important caveat that 
  each operation is done 3 digits at a time instead of 1 digit at a time. This means that the memory-intensive
  string representation of very large numbers can be avoided, and instead a vector of integers,
  with each element being a value from 0 to 999 in the hundreds, hundreds of thousandths, hundreds of millions,
  etc. place. This technique resulted in improvements in more than twofold increase in time efficiency, 
  which was highly impactful for large numbers.
- The second key technique is by using Exponentiation by Squares rather than the conventional method.
  The conventional method uses the following.
  $A ^ 4 = A \times A \times A \times A$
  
  In Exponentiation by Squares, the number of computations is drastically reduced by capitalizing on 
  the property that any number can be represented as a sum of powers of two. The effect is increased 
  when formulating the problem recursively, as can be seen through the below formulation.
  
  if m is even: $A ^ m = A ^ \frac{m}{2} \times A ^ \frac{m}{2}$          
  if m is odd: $A ^ m = A \times A ^ {m - 1}$

  Looking at the above, it can be seen that by identifying whether or not the exponent is odd or even, 
  the number of computations necessary to reach an answer for A^m becomes reduced by half. 
  This technique resulted in improvements in time efficiency of more than tenfold, which was yet another
  a drastic impact.
- The next big step in optimizations comes from upgrading the "Vector Chunk" modified school-book 
  multiplication algorithm implemented in this solution to use the more advanced algorithms that have been
  derived. These include the Karatsuba, Toom-Cook, Schonhage-Strassen, and GMP MUL_FFT multiplication 
  algorithms. Each of these is best used for different orders of magnitude for operands, but implementing 
  one of them would likely have a large impact on the efficiency of the current solution.
- Future optimizations can use the following methods:
    - Parallel processing on a multicore processor, splitting up large numbers and working on
      sufficiently far portions of it at once
    - Memory optimization through efficient allocation and deallocation techniques can reduce memory
      overhead when performing these operations, which is one of the bottlenecks to the speed.
    - Caching and Memoization by storing the results of expensive function calls and reusing
      them when the same inputs again, which reduces the number of calculations and further improves
      efficiency.
