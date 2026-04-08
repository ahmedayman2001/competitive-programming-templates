
/**

  Prime Number Checker Algorithm (Optimized Trial Division) :

🔹 Description:

This algorithm checks if a number n is prime by testing divisibility only up to √n instead of all numbers up to n-1.

Step 1: If n = 1, return false (since 1 is not prime).

Step 2: For each integer i in [2, √n]:

If n % i == 0, then n is divisible by i, so it is not prime → return false.

Step 3: If no divisor is found, return true → meaning n is prime.


🔹 Time Complexity:

O(√n) → because we only check divisors up to the square root.

🔹Example :

Input: 29

Loop runs up to sqrt(29) ≈ 5.

No divisor found → returns true (prime).

Input: 30

Loop finds divisor i = 2.

Returns false (not prime).

 
           ( Algorithm ) :
**/

        
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

 //const int N = 1e5 + 5;
// const int mod = 1e9+7 ;

   // Divisors for any integer number

   bool isPrime (ll n ) {

       if (n == 1 ) return 0 ;

       for (int i = 2; i * i <=  n  ; ++i) {


           if (n % i == 0)

               return  0 ; // mean this not prime number //


       }

       return 1 ;  //  mean this is prime number //


   }


int main() {


       ll x  ;

       cin >> x ;

    cout<< isPrime( x ) << el  ;



    return 0 ;

}




