/**
         
         ( Sieve of Divisors Algorithm ) :


    📝 Algorithm Description:

The Sieve of Divisors is an efficient precomputation algorithm used to find all divisors for every integer in a given range [1, N).
It works by iterating through all integers i from 1 to N - 1, and for each i, it adds i as a divisor to all of its multiples.

This approach is inspired by the Sieve of Eratosthenes, but instead of marking primes, it builds a list of divisors for each number.

    ⚙️ Algorithm Steps:

Initialize a vector of vectors d[N], where d[x] will store all divisors of x.

For every integer i from 1 to N - 1:

Loop through all multiples of i (i.e., i, 2i, 3i, ...)

Append i to d[multiple] because i divides every multiple of itself.

After the sieve finishes, d[x] contains all divisors of x in sorted order.

⏱ Time Complexity:
O(NlogN)

Each number contributes to about N / i multiples, summing up to roughly N log N operations overall. 
   
🧩 Example:

If N = 10, then after running the sieve:

              d[1] = {1}  
d[2] = {1, 2}  
d[3] = {1, 3}  
d[4] = {1, 2, 4}  
d[5] = {1, 5}  
d[6] = {1, 2, 3, 6}  
d[7] = {1, 7}  
d[8] = {1, 2, 4, 8}  
d[9] = {1, 3, 9}

   
     ( Algorithm ):

      **/

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

    const int N = 1e6 + 5   ;  
//     const int mod = 1e9+7     ;  //

    // ***   Sieve Divisors Algorithm  for any integer number     *** //

     vector < int > d[N] ;

     void sieve ( ) {

         for (int i = 1; i < N ; ++i) {


                 for (int o = i; o <  N ; o+=i ) {

                     d[o].push_back(i) ;

                 }

         }
     }

int main() {



          sieve() ;

          ll number ;

          cin >> number ;


    for (auto it : d[number] ) {

      cout<< it << " " ;

    }


    return 0 ;

}

