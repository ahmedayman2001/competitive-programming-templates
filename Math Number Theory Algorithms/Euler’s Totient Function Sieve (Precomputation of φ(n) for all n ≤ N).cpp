/**


      Euler’s Totient Function Sieve (Precomputation of φ(n) for all n ≤ N) :

   
   🧠 Algorithm Description:

This algorithm efficiently computes Euler’s Totient Function (φ) for all integers from 1 to N − 1 using a modified Sieve of Eratosthenes technique.

φ(n) is the number of integers from 1 to n that are coprime with n.

In other words, it counts all numbers ≤ n that have GCD = 1 with n.

We are finding numbers coprime with 9 (numbers from 1 to 9 that have GCD = 1 with 9).

Numbers 1 to 9: 1, 2, 3, 4, 5, 6, 7, 8, 9

GCD with 9:

1 → GCD(1,9) = 1 ✅

2 → GCD(2,9) = 1 ✅

3 → GCD(3,9) = 3 ❌

4 → GCD(4,9) = 1 ✅

5 → GCD(5,9) = 1 ✅

6 → GCD(6,9) = 3 ❌

7 → GCD(7,9) = 1 ✅

8 → GCD(8,9) = 1 ✅

9 → GCD(9,9) = 9 ❌

✅ Coprime numbers: 1, 2, 4, 5, 7, 8 → 6 numbers



⚙️ Algorithm Steps (Sieve Version):

Initialization:
Set phi[i] = i for all i from 0 to N-1.
(Each number initially assumes itself as its own totient.)

Sieve Process:
For each integer i from 2 to N-1:

If phi[i] == i, then i is a prime number.

For every multiple o of i (i.e., o = i, 2i, 3i, …):


(Because i divides o, it contributes a factor (1 - 1/i).)

Result:
After the sieve completes, phi[i] will contain the value of φ(i) for all i ≤ N.

🧩 Example Output (first 10 numbers):

n	φ(n)	Explanation
1	1	Only 1 is coprime to 1
2	1	{1} coprime to 2
3	2	{1,2} coprime to 3
4	2	{1,3} coprime to 4
5	4	{1,2,3,4} coprime to 5
6	2	{1,5} coprime to 6
7	6	{1,2,3,4,5,6} coprime to 7
8	4	{1,3,5,7} coprime to 8
9	6	{1,2,4,5,7,8} coprime to 9
10	4	{1,3,7,9} coprime to 10



🕒 Time Complexity: O(NloglogN)

(similar to the Sieve of Eratosthenes)

💾 Space Complexity:
𝑂(𝑁)

(for storing the phi array)


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
 // const int mod = 1e9+7 ;

   ll phi[N] ;

   void sieve ( ) {

       for (ll i = 0; i < N; ++i) phi[i]= i ;

       for (ll i = 2; i < N ; ++i) {

           if (phi[i] == i ) {

               for (int o = i; o <N ; o+=i ) {

                   phi[o]-=phi[o]/i ;

               }

           }
       }
   }



int main() {

       sieve( ) ;

    for (int i = 1; i <= 10 ; ++i) {

        cout << i <<" "<< phi[i] <<"\n" ;

    }


    return 0 ;

}



