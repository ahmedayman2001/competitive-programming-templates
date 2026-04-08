/**

       Divisor Sieve Algorithm (Precomputation of Divisor Counts) 


    Description:
     This algorithm precomputes the number of divisors
     for all numbers from 1 up to N - 1.

     Idea:
     For each number i, we visit all multiples of i (j = i, 2i, 3i, ...),
     and increment their divisor count since i divides j.

 Time Complexity:  O(N log N)
 Space Complexity: O(N)

 Example:
     Input:  N = 10
     Output: d[1..9] = {1, 2, 2, 3, 2, 4, 2, 4, 3}
------------------------------------------------------------

  Algorithm :

**/
 

   #include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    const int N = 1e6 + 5;  // upper limit

    vector<int> d(N, 0);    // d[i] = number of divisors of i

    // --- Divisor Sieve Algorithm ---

    for (int i = 1; i < N; ++i) {

        for (int j = i; j < N; j += i) {

            d[j]++;  // i is a divisor of j
        }
    }

    // Example: print first 10 results

    for (int i = 1; i <= 10; ++i)

        cout << "Number of divisors of " << i << " = " << d[i] << '\n';


    return 0;

} 

/**

        🔍 Sample Output:

 Number of divisors of 1 = 1
Number of divisors of 2 = 2
Number of divisors of 3 = 2
Number of divisors of 4 = 3
Number of divisors of 5 = 2
Number of divisors of 6 = 4
Number of divisors of 7 = 2
Number of divisors of 8 = 4
Number of divisors of 9 = 3
Number of divisors of 10 = 4

**/



