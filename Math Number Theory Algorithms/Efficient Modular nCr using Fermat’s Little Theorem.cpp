/**

         ( Efficient Modular nCr using Fermat’s Little Theorem  ) :


    🔹 illustrative example that explains the difference between combinations (nCr) and permutations (nPr) 👇

     Let’s say you have 3 letters: A, B, C

and you want to choose 2 of them


   ✳️ Case 1: Combinations (nCr) — Order does NOT matter

Possible selections:

AB, AC, BC
So:
3C2=3     

     ✳️ Case 2: Permutations (nPr) — Order DOES matter

       Possible arrangements:
        AB, AC, BA, BC, CA, CB
         3P2=6  

    🔹 Relationship between them:

         nPr=nCr×r!

      Example: 5P2=5C2×2!=10×2=20



       🔹 Algorithm Description

This algorithm computes the binomial coefficient

nCr= n! ​/ r!(n−r)! under a modulus (mod), typically a large prime such as  10^9+7 using modular arithmetic to avoid overflow.

It leverages Fermat’s Little Theorem to efficiently find the modular inverse of the denominator instead of performing costly division (which is not directly possible under modular arithmetic).


    🔹 Time Complexity

O(n) to compute factorials

O(log mod) for modular exponentiation (inversion)

⚡ Total: O(n+log(mod))

Efficient for moderate  n ( e.g. up to 10^6 ) when precomputation is not used.


Key Features

Prevents integer overflow using modular operations.

Works for large 
𝑛
 and 
𝑟
when mod is prime.

Uses fast power for modular inverse calculation.

test case : 5 2

5C2 = 5!​/ 2!*(5−2)! =120 / 2×6​ = 10 



✅ Summary
Concept	Formula
Choose r from n freely	C(n, r)
Choose r from n when the first element is fixed	C(n - 1, r - 1)
Split n items into r non-empty groups	C(n - 1, r - 1)

📘 Classic example

Suppose you want to split a line of x candies into y non-empty boxes.

You need to choose (y−1) places to put separators among the (x−1) gaps between candies.

👉 The number of ways = C(x−1,y−1)



( Algorithm ) :

**/



ll nCr_exact(ll n, ll r) { 

    if (r < 0 || r > n) return 0;

    if (r == 0 || r == n) return 1;

    if (r > n - r) r = n - r;            // use symmetry

    __int128 res = 1;

    for (ll i = 1; i <= r; ++i) {

        // multiply then divide using 128-bit intermediate to avoid overflow

        res = res * (n - i + 1);

        res = res / i;

    }

    return (ll)res;

}

*************************************************************************************************

   // ( Algorithm ) :

    
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

   const int N = 1e5+ 5    ;
   const int mod = 1e9+7 ;


ll fac(ll x, ll m){

    ll ret = 1 ;

    for(int i=2;i<=x;++i) ret = (ret*i) % m;

    return ret ;
}

ll powmod(ll a, ll b, ll m) {

    if (b == 0) return 1;                     // Base case: a^0 = 1

    ll half = powmod(a, b / 2, m);          // Recursive step: compute a^(b/2)

    half = (half * half) % m;               // Square it (mod mod)

    if (b & 1)                                // If b is odd → multiply by a once more

        half = (half * (a % m)) % m;

    return half;

}

// ---------- nCr ----------

ll nCr(ll n, ll r, ll m) {

    if (r > n) return 0;

    ll numerator = fac(n, mod);

    ll denominator = (fac(r, mod) * fac(n - r, mod)) % mod;

    return (numerator * powmod(denominator, mod - 2 , mod)) % mod; // Fermat’s theorem

}



int main( ) {

    FastIO

    ll x , y ;

    cin >> x >> y ;

   cout<< nCr(x , y , mod ) ;


    return 0 ;

}

