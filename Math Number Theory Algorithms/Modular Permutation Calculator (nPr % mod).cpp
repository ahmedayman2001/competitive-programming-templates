
/**

      Modular Permutation Calculator (nPr % mod)   :


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



   🧩 Algorithm Description:

This algorithm efficiently computes the number of permutations of r elements selected from a total of n elements, under a given modulus (mod) to prevent overflow.
In mathematical terms, it calculates:


   nPr=n! /(n−r)! ​(modmod) 
    ⚙️ How It Works:

Input:
Two integers n and r (where 0 ≤ r ≤ n).

Computation:
Instead of calculating full factorials (which can overflow), it multiplies only the last r terms:  nPr=n×(n−1)×(n−2)×⋯×(n−r+1)

Each multiplication is taken modulo mod to keep the result within range.

Output:
Returns the computed value of nPr % mod.

 🧮 Example:

For n = 5, r = 3
  5P3 = 5 × 4 × 3=60

If mod = 1e9+7
5P3%mod=60

   🚀 Algorithm Complexity:

Time Complexity: O(r)

Space Complexity: O(1)

     ( Algorithm ):

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


ll nPr(ll n,ll r, ll mod){

    ll ret = 1 ;

    for(int i= n-r+1 ; i<= n ; ++i) ret = (ret * i) % mod;  // ret (5P3)=  3 * 4 * 5  // Time Complexity O ( r ) //

    return ret ;
}

int main() {

    FastIO

    ll n , r ;

    cin >> n >> r ;


    cout << nPr(n , r , mod ) ;


    return 0 ;

}




