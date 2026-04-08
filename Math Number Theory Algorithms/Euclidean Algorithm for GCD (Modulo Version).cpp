/**

Euclidean Algorithm for GCD (Modulo Version) :


🔹 Description :

This algorithm calculates the Greatest Common Divisor (GCD) of two integers using the classical Euclidean algorithm with the modulus operator:

🔹 Example

nput: a = 48, b = 18

gcd(48, 18) → gcd(18, 12) → gcd(12, 6) → gcd(6, 0)
Output: 6

🔹Steps : 

If b > a, swap them so that a ≥ b.

If b == 0, return a (base case).

Otherwise, recursively call gcd(b, a % b).

This version is much more efficient than the subtractive approach because instead of subtracting many times, it reduces the problem size in one step using modulus.

🔹 Time Complexity : O(log(min(a,b))) 


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

   // GCD for any integer number

   ll gcd (ll a , ll b ) {

       if (b > a ) swap(a , b ) ;

       if ( b == 0 )  return a ;
       return gcd (a % b , b );

   }



int main() {


       ll x , y ;

       cin >> x >> y ;

  cout << gcd (x , y) <<el ;




    return 0 ;

}



