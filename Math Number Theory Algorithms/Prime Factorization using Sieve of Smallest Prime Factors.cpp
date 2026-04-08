/**

         ( Prime Factorization using Sieve of Smallest Prime Factors  )

   📘 Algorithm Description:

This algorithm efficiently computes the prime factorization of any integer number by leveraging a precomputed sieve of smallest prime factors.

Instead of performing trial division for each query (which can be slow for large numbers), it first builds a sieve that stores the list of prime factors for every integer up to N.
Then, using this precomputed information, it can quickly decompose any input number into its prime factors.


⚙️ Step-by-Step Explanation:

1- Sieve Construction (sieve()):

For every integer i starting from 2, if pf[i] is empty, it means i is a prime number.

The algorithm then marks all multiples of i (like 2i, 3i, 4i, …) and adds i to their list of prime factors.

After this step, every number x has a vector pf[x] containing all distinct prime factors of x.

2- Prime Factorization (add(n)):

To factorize a number n, it iterates over all its prime divisors stored in pf[n].

For each divisor it, it repeatedly divides n by it while it remains divisible, counting the exponent of that prime.

The counts are stored in a global map m, where the key is the prime number and the value is its exponent.

3- Output:

The program prints all prime factors of the number, repeated according to their exponent (i.e., multiplicity).


 🧮 Example:

Input: 60
   

   Process:

pf[60] = [2, 3, 5]

Divide step by step:

60 / 2 = 30 / 2 = 15

15 / 3 = 5

5 / 5 = 1

So, prime factors are 2 × 2 × 3 × 5

Output: 2 2 3 5

⏱️ Time Complexity:

Precomputation (Sieve): O(N log log N) 


   ( Algorithm ) : 
          
  **/

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

    const int N = 1e5 + 5   ;  //
//     const int mod = 1e9+7     ;  //

    // ***   Sieve Prime Factors for any integer number     *** //

     vector < int > pf[N] ;
     void sieve ( ) {

         for (int i = 2; i < N ; ++i) {

             if ( pf[i].empty() ) {

                 for (int o = i; o <  N ; o+=i ) {

                     pf[o].push_back(i) ;

                 }
             }
         }
     }
        map <ll , ll > m ;

      void add  ( ll n) {


          ll x = n ;
          for (auto it : pf[n]) {

              while (x % it == 0 ) {

                  m[it]++ ;

                  x/= it ;

              }

          }

      }


    int main() {

          sieve() ;

          ll number ;

          cin >> number ;

          add( number ) ;

    for (auto [a , b ] : m ) {

        while (b-- ){


            cout<< a << ' ' ;

        }
    }


    return 0 ;

}

    


  





  