
/**

      Optimized Prime Factorization using Trial Division up to √n


🔹 Description:

This algorithm computes the prime factors of a number n by checking only divisors up to √n instead of going all the way to n.

Steps:

Iterate i from 2 to √n.

If i divides n, keep dividing until n % i != 0, counting the exponent (cnt).

Store (i, cnt) in a vector.

After the loop, if the remaining n > 1, then n itself is prime and added as a factor.

Print each prime factor with its exponent.


🔹Time Complexity: O(√n) 


✅ Example:
Input: n = 60

2 divides → exponent = 2 (60 → 30 → 15)

3 divides → exponent = 1 (15 → 5)

remaining = 5 → exponent = 1


🔹Output: 

2 Power of 2
3 Power of 1
5 Power of 1
    
🔹 What this algorithm does

Reads a number n.

Finds its prime factors and how many times each appears in the factorization.

Prints them in the format: prime Power of exponent.


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

   // Prime Factors Algorithm


   vector < pair<ll , ll >> Prime_Factors ;


    void Prime_Divisors (ll x) {

        for (ll i = 2; i*i <= x  ; ++i) {

            if (x % i == 0 ) {

                int cnt = 0 ;

                while (x % i == 0 ) {

                    x/=i ;

                    cnt++ ;

                }

                Prime_Factors.push_back({i,cnt}) ;

            }

        }

        if (x > 1 ) Prime_Factors.push_back({x , 1 }) ;

        for (auto it : Prime_Factors) {


            cout << it.first << " Power of " << it.second << el ;

        }

        return ;
    }


int main() {

         ll n ;
        cin >> n ;

    Prime_Divisors(n) ;


    return 0 ;

}






 