/**
          Dynamic Prime Factorization Divisibility Checker (using Sieve Preprocessing)  :



/**
      📖 Description:
  
       This algorithm is designed to efficiently check whether a product of dynamically added integers remains an integer when taking its k-th root (or more generally, when testing divisibility of prime exponents by some number).

It works in two main phases:

Preprocessing with Sieve of Prime Factors

Using a modified Sieve of Eratosthenes, it precomputes the prime factorization for every integer up to N.

For each number, it stores its prime factors in pf[number].

This allows O(log n) prime factorization lookups instead of trial division.

Dynamic Updates and Queries

A global map m stores the cumulative prime factor exponents of all added numbers.

Operation 1 (op == 1) → Add a number x to the system by factorizing it and updating the exponents in m.

Operation 2 (op == 2) → Given an integer x, check if the current product of all added numbers is an exact x-th power of an integer.

This is done by verifying that each exponent in m is divisible by x.

If all exponents are divisible → output "Integer".

Otherwise → output "Not Integer".


 
- Time Complexity: O(N log log N) 


 - ( Algorithm ) :

    **/

 #include <bits/stdc++.h>

  using namespace std;

   #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

    #define ll long long
    #define el endl

    // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

           const int N = 1e5 + 5   ;  

     //     const int mod = 1e9+7     ;  //

    // ***    Sieve Prime Factorization Divisibility Checker Algorithm     *** //


    vector < int > pf[N] ;
    void sieve ( ) {


        for (int i = 2; i < N ; ++i) {

            if (pf[i].empty() ){

                for (int o = i; o < N; o+=i ) {

                    pf[o].push_back(i) ;


                }
            }

        }

    }  map <ll , ll > m ;

    void add ( ll n ) {

        ll x = n ;
        for (auto it : pf[n]) {

            while (x % it == 0 ) {

                m[it]++ ;
                x/=it ;

            }
        }

    }

int main() {

   sieve() ;

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

                if ( b % x != 0 ) {

                    ans = "Not Integer\n";

                    break;
                }
            }

            cout<< ans << el ;
        }
    }

    return 0 ;

}



