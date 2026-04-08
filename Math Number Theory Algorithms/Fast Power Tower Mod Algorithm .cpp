/**


      Modular Exponentiation with Exponent Reduction (using Fermat’s Little Theorem)  :   “Efficient Computation of a^b^c mod p :Algorithm Name: Fast Power Tower Mod Algorithm 

where 𝑝 is a prime number, and 𝑎,𝑏,𝑐 can be very large.

Directly computing 𝑏^𝑐 would overflow and is infeasible (because 𝑏^𝑐 grows exponentially).
So, the algorithm uses modular exponentiation and Fermat’s Little Theorem to reduce the problem.

🔹 Mathematical Idea:
p is prime, Fermat’s theorem says:

1️⃣  exp=𝑏^𝑐 mod(𝑝−1)


2️⃣ ans=a^exp mod p

🔹 Time Complexity: O(log b + log c) 

Input:2 3 2

Steps:
exp = 3^2 % (1e9+6) = 9
ans = 2^9 % (1e9+7) = 512

Output: 512 

// Algorithm: Algorithm Name: Fast Power Tower Mod 
// Description: Efficiently computes a^(b^c) % mod using Fermat's Little Theorem.
// Steps: exp = b^c % (mod - 1), then ans = a^exp % mod.
// Complexity: O(log b + log c)


  ( Algorithm ) :

   **/


#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

   const int N = 1e5+ 5    ;
   const int mod = 1e9+7 ;



ll powmod(ll a, ll b, ll m) {

    if (b == 0) return 1;                     // Base case: a^0 = 1

    ll half = powmod(a, b / 2, m);          // Recursive step: compute a^(b/2)

    half = (half * half) % m;               // Square it (mod mod)

    if (b & 1)                                // If b is odd → multiply by a once more

        half = (half * (a % m)) % m;

    return half;
}




int main() {

    ll a , b , c ;
    cin >> a >> b >> c ;

    ll exp = powmod(b , c , mod-1 ) ;
    ll ans = powmod(a , exp , mod ) ;

    cout<< ans<<el ;





    return 0 ;

}




     