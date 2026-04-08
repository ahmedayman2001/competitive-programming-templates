
/**

   ( Euclidean Algorithm for GCD and LCM ) :

 🔹 Description :

This program computes the Least Common Multiple (LCM) of two integers using the Greatest Common Divisor (GCD), which is calculated via the Euclidean algorithm (modulo method).

🔹 Example :
Input:
12 18

Steps:

gcd(12, 18) = 6

lcm(12, 18) = (12 × 18) / 6 = 216 / 6 = 36

Output:
36

🔹 Time Complexity : O(log(min( a , b ))) .

⚠️ Note about overflow:

  can cause overflow if x * y exceeds the range of long long (≈ 9e18).
✔ A safer version is:

return (x / gcd(x, y)) * y;


( Algorithm ): 

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
       return gcd (a % b , b );

   }

   ll lcm (ll x , ll y ) {


       return x*y / gcd(x , y );


   }



int main() {


       ll x , y ;

       cin >> x >> y ;

  cout << lcm(x , y) <<el ;



    return 0 ;

}

