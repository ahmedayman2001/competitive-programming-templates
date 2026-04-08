
/**

       ( Binary Exponentiation Algorithm )

What is the fastest way to calculate the power function with an integer exponent?

  📖 Description:

This algorithm efficiently computes

𝑥^𝑦(mod𝑀)

where:


x is the base,


y is the exponent,

𝑀
M is a modulus (in your code M=10^9+7 )
 Instead of performing 
y multiplications (which would take 𝑂(𝑦)
O(y) time), it reduces the problem by recursively halving the exponent.

If 
y is even:

𝑥^y=(𝑥^𝑦/2)^2


If 
y is odd:𝑥^𝑦=𝑥⋅(𝑥^𝑦/2)^2


This reduces the complexity to O(logy) multiplications.
The modulus is applied at every step to prevent overflow and keep values within range.


powmod(x, y) is a recursive implementation of fast modular exponentiation using binary exponentiation.



    ( Algorithm : )

**/
   
  
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

//  const int N = 1e5 + 5;

const int mod = 1e9+7 ;

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;                     // Base case: a^0 = 1

    ll half = powmod(a, b / 2, mod);          // Recursive step: compute a^(b/2)

    half = (half * half) % mod;               // Square it (mod mod)

    if (b & 1)                                // If b is odd → multiply by a once more

        half = (half * (a % mod)) % mod;

    return half;
}



int main() {


        ll x , y ;

        cin >> x >> y ;

        cout << powmod( x ,  y , mod  ) << el ;


    return 0 ;

}



**********************************************************************************************

   ll pow (ll x , ll y ) {

       if (y == 0 ) return  1 ;
       if (y == 1 ) return x ;

       ll ret = 1 ;
       if (y & 1) ret = x ;
        ll half = pow(x , y/2 ) ;
       return ret *half * half ;
       
   }

**********************************************************************************************





