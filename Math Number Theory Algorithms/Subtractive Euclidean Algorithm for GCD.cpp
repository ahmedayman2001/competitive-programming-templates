/**

    ( Subtractive Euclidean Algorithm for GCD ) :


🔹 Description :

This algorithm computes the Greatest Common Divisor (GCD) of two integers using a subtractive version of the Euclidean algorithm.

Steps:

Input: x = 48, y = 18

gcd(48, 18) → gcd(30, 18) → gcd(12, 18) → gcd(6, 12) → gcd(6, 6) → gcd(0, 6)
Output: 6

Steps:

If b > a, swap them so that a ≥ b.

If b == 0, return a (base case).

Otherwise, replace a with a - b and call the function again.

Repeat until one number is zero.

time complexity is:  O( a/b ​) 


Algorithm :

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

   ll gcd (ll a , ll b ) {

       if (b > a ) swap(a , b ) ;

       if ( b == 0 )  return a ;

       return gcd (a-b , b );

   }



int main() {


       ll x , y ;

       cin >> x >> y ;

  cout << gcd (x , y) <<el ;



    return 0 ;

}

