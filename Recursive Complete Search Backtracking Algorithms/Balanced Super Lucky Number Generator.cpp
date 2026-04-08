/**


  ( Balanced Super Lucky Number Generator ) :
 

Petya loves lucky numbers. Everybody knows that positive integers are lucky if their decimal representation doesn't contain digits other than 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Lucky number is super lucky if it's decimal representation contains equal amount of digits 4 and 7. For example, numbers 47, 7744, 474477 are super lucky and 4, 744, 467 are not.

One day Petya came across a positive integer n. Help him to find the least super lucky number which is not less than n.

Input :

The only line contains a positive integer n (1 ≤ n ≤ 109). This number doesn't have leading zeroes.


Output:

Output the least super lucky number that is more than or equal to n.

Please, do not use the %lld specificator to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specificator.

TEST CASES :

4500
4747

47
47



   This algorithm is a generator + search algorithm for a special class of numbers . 

  1- Generates numbers made only of digits 4 and 7 (like 47, 7744, 4477).

2- While generating, it tracks the difference (dif) between how many 4s and 7s are in the number:

Adding a 4 → dif + 1

Adding a 7 → dif - 1

3- Only numbers with equal counts of 4s and 7s (dif == 0) are accepted.

Example: ✅ 47, 7744 (same number of 4s and 7s).

❌ 444, 777 (not balanced).

4- Stores all such numbers (superlucky) up to 1e10.

5- Sorts them and finds the smallest "super lucky" number ≥ n.


🔹 Description : 

  This algorithm generates and finds the smallest “super lucky” number greater than or equal to a given integer n.

A super lucky number is defined as a positive integer consisting only of digits 4 and 7, with an equal count of 4s and 7s.

🔹Generation is done recursively, building numbers digit by digit:

🔹Append 4 → increase balance counter.

🔹Append 7 → decrease balance counter.

🔹A number is valid if it has the same number of 4s and 7s (dif == 0).

🔹After generation, all super lucky numbers are sorted, and the algorithm outputs the first super lucky number ≥ n.




Algorithm steps :

1- The recursion (gen) builds numbers digit by digit using only 4 and 7.

2- dif ensures the number has equal counts of 4s and 7s.

3- Valid numbers are collected in superlucky.

4- After generation + sorting, the program outputs the smallest one ≥ n



    (  Algorithm ) : 

/**


   
#include <bits/stdc++.h>   // Import all standard C++ libraries

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


// Vector to store all "super lucky" numbers

vector<ll> superlucky;

/*
   Recursive function to generate "super lucky numbers"
   Parameters:
   - x   : current number being formed
   - dif : difference between count of '4's and '7's
           (each '4' increases dif, each '7' decreases dif)
*/

void gen(ll x, int dif) {

    // Stop if the number becomes larger than 1e10

    if (x > 1e10) {

        return;

    }

    // If the number is not zero and has equal 4's and 7's (dif == 0)
    // then it is a valid "super lucky number"

    if (dif == 0 && x != 0) {

        superlucky.push_back(x);

    }

    // Recursive step:

    // Try to add digit '4' → increase dif

    gen(x * 10 + 4, dif + 1);

    // Try to add digit '7' → decrease dif

    gen(x * 10 + 7, dif - 1);

}

int main() {

    FastIO   // Fast input/output

    // Generate all possible "super lucky numbers" starting from 0

    gen(0, 0);

    // Sort all generated numbers in ascending order

    sort(superlucky.begin(), superlucky.end());

    ll n;

    cin >> n;   // Input: the target number

    // Find and print the smallest super lucky number >= n

    for (auto x : superlucky) {

        if (x >= n) {

            cout << x;

            return 0; // Exit after finding the first valid number

        }

    }

    return 0;
}


     



