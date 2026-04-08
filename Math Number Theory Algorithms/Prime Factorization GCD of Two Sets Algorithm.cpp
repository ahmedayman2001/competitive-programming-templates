/**

         ( Prime Factorization GCD/LCM  of Two Sets Algorithm ) :

( 👉 For the LCM we do the opposite: we take the maximum exponent of each prime between the two sets. )

  🔹 Description

This algorithm computes the Greatest Common Divisor (GCD) of two sets of integers by using prime factorization.

It factors all numbers in each set into primes.

Counts the exponent of each prime across the entire set.

Then, for every prime, it selects the minimum exponent between the two sets.

Finally, it reconstructs and outputs the prime factorization of the GCD.


 🔹 What the Code Does

1- Prime Factorization Counting

For every number in the first list (size n), it factors it into primes and stores the frequency of each prime factor in frq1[].

For every number in the second list (size m), it factors it into primes and stores frequencies in frq2[].

2- Find Common Prime Factors

After reading both groups of numbers, it loops over all possible primes up to N.

For each prime i, it takes min(frq1[i], frq2[i]).

This gives the shared exponent of prime i between the two sets.

It then prints that prime repeated as many times as the minimum count.

→ In other words, it prints the prime factorization of the GCD of the product of the first set and the product of the second set.

🔹 Example :

   We have two sets (first set and second set).
Suppose:

First set = {2, 4}

Second set = {8}

Step 1: Factorize each number into primes

First set {2, 4}

2 = 2¹

4 = 2²

So in total for the first set:
frq1[2]=1+2=3

(all other primes = 0)

Second set {8}

8 = 2³

So in total for the second set:


frq2[2]=3

(all other primes = 0)

Step 2: Compare frequencies


min(frq1[2],frq2[2])=min(3,3)=3


Step 3: Print common factors


The algorithm prints prime 2 three times:

2 2 2

Step 4: Meaning

That corresponds to:


2×2×2=8

So the GCD of the products is:


gcd(2×4,8)=gcd(8,8)=8

✅ Final Output:

2 2 2
   
 
   ( Algorithm ) :

    **/


#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

 const int N = 1e5 + 5;
// const int mod = 1e9+7 ;

   //  Prime Factorization GCD of Two Sets Algorithm //


    int frq1[N] , frq2[N] ;

     void add (ll n , int frq[ ] ) {


         for (int i = 2; i* i <= n ; ++i) {


             if (n % i == 0 ) {

                 int cnt = 0 ;

                 while (n % i == 0 ) {

                     n/= i ;
                     cnt++ ;

                 } 
               frq[i]+=cnt ;

             }

         }

         if (n > 1 ) frq[n]++ ;

         return;
     }




int main() {


         int n ;

         cin >> n ;

    while (n-- ) {

        int x ;

        cin >> x ;

        add ( x, frq1  ) ;

    }

    int m ;

    cin >> m ;

    while (m-- ){


        int y ;

        cin >> y ;

        add (y , frq2) ;


    }

    for (int i = 1; i < N ; ++i) {

        int mn = min(frq1[i] , frq2[i]) ;

        while (mn --){


            cout<< i <<" " ;

        }

    }

    return 0 ;

}





   