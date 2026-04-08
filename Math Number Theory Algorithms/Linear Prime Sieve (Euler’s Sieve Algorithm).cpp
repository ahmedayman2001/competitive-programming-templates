/**

           Linear Prime Sieve (Euler’s Sieve Algorithm) 


    📝 Description

The Linear Prime Sieve, also known as Euler’s Sieve, is an optimized version of the classic Sieve of Eratosthenes that computes all prime numbers up to a given limit N in O(N) time complexity.

Unlike the traditional sieve (which may mark each composite number multiple times), this algorithm ensures that each composite number is marked exactly once, using its smallest prime factor.

The algorithm maintains:

A boolean array is_prime to mark primality.

A vector primes to store all found prime numbers.


⚙️ Core Idea

For every number i from 2 to N:

If i is still marked as prime → add it to the prime list.

For each prime p in primes:

Mark i * p as composite.

If i is divisible by p, stop — because p is the smallest prime factor of i * p, ensuring each composite is marked once.

⏱️ Time Complexity

O(N) — each number is processed only once.

O(N) space.

✅ Advantages

Faster than the traditional sieve for large N.

Prevents redundant work by leveraging smallest prime factor property.

Ideal for precomputing primes efficiently up to ~10⁷.


We’ll trace it for: N = 20


is_prime = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
primes = []
Then:
is_prime[0] = is_prime[1] = 0

🧩 Start main loop: for (i = 2; i < N; ++i)
i = 2:

is_prime[2] == 1 → ✅ prime
→ primes = [2]

Inner loop over primes:

it = 2

i * it = 4 < 20 → mark composite
→ is_prime[4] = 0

i % it == 0 → 2 % 2 == 0 ✅ → break inner loop


i = 3:

is_prime[3] == 1 → ✅ prime
→ primes = [2, 3]

Inner loop:

it = 2:
i * it = 6 < 20 → is_prime[6] = 0
3 % 2 != 0 → continue

it = 3:
i * it = 9 < 20 → is_prime[9] = 0
3 % 3 == 0 → break


i = 4:

is_prime[4] == 0 → skip (composite)

i = 5:

is_prime[5] == 1 → ✅ prime
→ primes = [2, 3, 5]

Inner loop:

it = 2: 5*2=10, mark is_prime[10]=0, 5%2!=0

it = 3: 5*3=15, mark is_prime[15]=0, 5%3!=0

it = 5: 5*5=25 >= 20 → break inner loop


i = 6:

is_prime[6] == 0 → skip


i = 7:

is_prime[7] == 1 → ✅ prime
→ primes = [2, 3, 5, 7]

Inner loop:

it = 2: 7*2=14, mark is_prime[14]=0, 7%2!=0

it = 3: 7*3=21 >= 20 → break


i = 8, 9, 10 … (all composite) → skip
i = 11:

is_prime[11]==1 → ✅ prime
→ primes=[2,3,5,7,11]

it=2: 11*2=22>=20 → break

…and so on up to i=19.


✅ Final results

primes = [2, 3, 5, 7, 11, 13, 17, 19]

is_prime array (for first 20 elements):

0 0 1 1 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 1


🧮 Verification

Indeed, primes up to 20 are:
2, 3, 5, 7, 11, 13, 17, 19 ✅

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

    // Linear Sieve Algorithm //

  vector < bool >is_prime (N , 1) ;

   vector<int> primes ;


  void Linear_Sieve ( ) {


      is_prime[0]=is_prime[1] = 0 ;

      for (ll i = 2; i < N ; ++i) {

          if (is_prime[i]) primes.push_back(i) ;

          for (auto it: primes ) {

              if (i*it>=N) break ;

              is_prime[i*it] = 0 ;

              if (i%it) break ;

          }

      }

  }


int main() {

      Linear_Sieve() ;


    for (auto it:primes) {

        cout<<it<<" " ;
    }



    return 0 ;

}



