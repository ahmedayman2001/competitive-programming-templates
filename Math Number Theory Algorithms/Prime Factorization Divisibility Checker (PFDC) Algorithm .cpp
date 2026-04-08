/**
             
               Prime Factorization Divisibility Checker (PFDC) Algorithm : 


📖 Description:

This algorithm maintains the prime factorization exponents of one or more numbers and allows queries to check whether the combined factorization still represents a perfect integer power of a given exponent.

When a number is added (op = 1), it is factorized into its prime factors, and the exponent counts of those primes are accumulated in a global map.

When queried (op = 2 with value x), the algorithm verifies whether all stored prime exponents are divisible by x.

If true → the product of numbers added so far can be expressed as an exact x-th power of an integer.

If false → it is not an exact x-th power. 	


🔎 Example:

  n = 8   (prime factors = 2^3)
add(8) → m = {2 : 3}

Query: x = 3
Check: exponent of 2 = 3 (divisible by 3) → Integer

Add(4) → factors 2^2, so m = {2 : 5}
Query: x = 3
Check: exponent of 2 = 5 (not divisible by 3) → Not Integer

Time Complexity : O(nsqrt(n ) ) 

note : if n == 10^6  : 10^6 * 10^3 = 10^9 so : Time Limit Exceed !!! so we use Sieve of Eratosthenes Algorithm time (O(Nloglog(N))) .

This algorithm checks whether the product of inserted numbers can be represented as a perfect k-th power (for some query k), using prime factorization exponent divisibility.

  ( Algorithm ) :

     **/

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

  const int N = 1e5 + 5;
const int mod = 1e9+7 ;

     // Prime Factorization Divisibility Checker Algorithm

     map <ll , ll > m ;

     void add (ll n ) {

         for (ll i = 2; i <= n ; ++i) {

             if (n % i == 0 ){

                  ll cnt = 0 ;

                 while (n % i == 0 ) {

                     n/= i ;

                     cnt ++ ;

                 }

                 m[i]+= cnt ;

             }

         }

         if (n > 1 ) m[n]++ ;

     }



int main() {


         ll t ;

         cin >> t ;

         m.clear() ;

         ll n , q ;

         cin >> n >> q   ;


         add (n ) ;

    while (q -- ) {	

        ll op , x  ; cin >> op >> x  ;

        if (op == 1 ) add ( x ) ;

        else {

            string ans = "Integer\n" ;

            for (auto [a , b ] : m ) {

                if ( b % x != 0 ){

                    ans  = "Not Integer\n" ;

                break ;
               }
            }

            cout<< ans << el ;
        }
    }

    return 0 ;

}





    