
/**

         ( Euler’s Totient Function (φ(n)) — Co-Prime Counter ) :


     📜 Algorithm Description

Purpose:
The algorithm calculates the number of integers from 1 to n that are coprime (relatively prime) with n.
That number is called Euler’s Totient Function, denoted as φ(n).


Formally:

φ(n) = count of integers 1 ≤ k ≤ n such that gcd(k, n) = 1


🧩 Mathematical Formula

(where  𝑝𝑖 are distinct prime factors),
then

φ(n)=n×(1−1/p1​​)×(1−1/p2​​)×…×(1−1/pk​​)

⚙️ Algorithm Steps (inside phi(n))

Initialize ret = n

Loop i from 2 to sqrt(n)

For each i:

If i divides n, it’s a prime factor

Divide out all factors of i from n

Update: ret -= ret / i

If there’s any prime factor > sqrt(n) left, also subtract its contribution: ret -= ret / n

Return ret

🧪 Trace Example

Let’s trace it for n = 10

✅ Brute-force count (the first loop in main)

We check all numbers 1..10:


 (  Algorithm ) :

**/

      
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

   const int N = 1e6+ 5    ;
 // const int mod = 1e9+7 ;

    ll phi ( ll n ) {  // Co-prime with n //

        ll ret = n  ;

        for (ll i = 2; i*i  <= n  ; ++i) {

            if (n % i == 0 ) {

                while ( n % i == 0) n/= i;

                ret-= ret / i;

            }
        }

        if (n > 1) ret-=ret/n ;

        return  ret ;
    }


int main() {


         ll n ;  cin >> n ;

         ll c = 0 ;

    for (int i = 1; i <= n; ++i) {

        if (__gcd((ll) i , n )==1)  c++ ;    // Time Complexity :O(nlog(n))

    }
    cout << c << " " ;
         
         
         cout << phi(n) <<el ;   // Time Complexity : O (sqrt(n)) 




    return 0 ;

}





   


