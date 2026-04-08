/**

   ( Trial Division Prime Checking Algorithm ) :


🔹 Description:

This algorithm checks whether a given integer n is prime or not by testing divisibility with all integers starting from 2 up to n-1.

If n = 1, the function directly returns false (since 1 is not prime).

For every integer i in the range [2, n-1], it checks:

If n % i == 0, then n is divisible by i, hence not prime, and the function returns false.

If no divisor is found in this range, the function returns true, meaning n is prime.

🔹 Time Complexity:

Worst Case: O(n) → because it checks divisibility up to n-1.

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

       for (int i = 2; i < n  ; ++i) {

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


