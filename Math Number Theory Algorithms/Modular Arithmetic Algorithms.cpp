/**

    (  Modular Arithmetic Algorithms  )

**/


   #include <bits/stdc++.h>
using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

#define ll long long
const int mod = 1e9 + 7;

//─────────────────────────────────────────────
// mod_pow → Binary Exponentiation (Modular Power)
//─────────────────────────────────────────────
ll pow(ll a, ll b) {
   

    if (b == 0 )
        return 1 ;
    if (b == 1 ) return  a ;

    if (b % 2 == 0 )
        return pow(a , b/2 )* pow(a , b/2 ) ;
    else 
        return a* pow(a , b/2 ) * pow (a , b/2 ) ; 
}

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;                     // Base case: a^0 = 1
    ll half = powmod(a, b / 2, mod);          // Recursive step: compute a^(b/2)
    half = (half * half) % mod;               // Square it (mod mod)
    if (b & 1)                                // If b is odd → multiply by a once more
        half = (half * (a % mod)) % mod;
    return half;
}


//─────────────────────────────────────────────
// mod_add → Modular Addition
//─────────────────────────────────────────────
ll mod_add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

//─────────────────────────────────────────────
// mod_sub → Modular Subtraction
//─────────────────────────────────────────────
ll mod_sub(ll a, ll b) {
    return (((a % mod) - (b % mod)) % mod + mod) % mod;
}

//─────────────────────────────────────────────
// mod_mul → Modular Multiplication
//─────────────────────────────────────────────
ll mod_mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

//─────────────────────────────────────────────
// mod_div → Modular Division (using Fermat's Little Theorem)
//─────────────────────────────────────────────
ll mod_div(ll a, ll b) {
    return (a * powmod(b, mod - 2, mod)) % mod;
}

//─────────────────────────────────────────────
// main → Example usage
//─────────────────────────────────────────────
int main() {
    FastIO;

    ll x, y;
    cin >> x >> y;

    cout << "mod_add(x, y): " << mod_add(x, y) << '\n';
    cout << "mod_sub(x, y): " << mod_sub(x, y) << '\n';
    cout << "mod_mul(x, y): " << mod_mul(x, y) << '\n';
    cout << " powmod(x, y): " <<  powmod(x, y , mod) << '\n';
    cout << "mod_div(x, y ): " << mod_div(x, y) << '\n';

    return 0;
}
