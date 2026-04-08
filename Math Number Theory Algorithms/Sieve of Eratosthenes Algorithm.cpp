/**
    
     ( Sieve of Eratosthenes Algorithm )


  📖 Description :

    The Sieve of Eratosthenes is an ancient and efficient algorithm for finding all prime numbers up to a given integer n.

It starts by assuming all numbers are prime.

Then, beginning with the first prime (2), it marks all multiples of that prime as not prime.

It continues this process for the next unmarked (prime) number.

The process repeats until all numbers up to n are processed.

This avoids checking primality of each number individually and reduces redundant operations.

Time Complexity:

O(n log log n) (very efficient for large n).

Steps :

  vector<bool> is_Prime(N, 1) initializes all numbers as "prime".

You set is_Prime[0] and is_Prime[1] to false (not prime).

For each prime i, you eliminate its multiples (o = i+i).

Finally, you print the prime numbers up to 100


 ( Algorithm ):

**/

    
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

    const int N = 1e5 + 5   ;  //

//     const int mod = 1e9+7     ;  //

    // ***    Sieve of the Eratosthenes Algorithm to  find all Prime numbers from 1 to n    *** //

  vector < bool > is_Prime (N , 1 ) ;

  void sieve ( ) {

      is_Prime[1] = is_Prime[0] = 0 ;

      for (int i = 2; i < N ; ++i) {

          if (is_Prime[i]) {

              for (int o = i+i ; o < N ; o+= i) {

                  is_Prime[o] = 0 ;

              }
          }

      }
  }

int main() {

  sieve() ;

    for (int i = 1; i <=  100  ; ++i) {


        if ( is_Prime[i]) cout<< i << " " ;

    }

    return 0 ;

}




  