/**

     ( Optimized Divisor Enumeration Algorithm ) :


    🔹 Description :

   This algorithm efficiently finds all positive divisors (factors) of an integer n.

Instead of checking every number from 1 to n, it only checks up to √n.

Why? Because divisors always come in pairs:

If i divides n, then n / i is also a divisor.

Example: For n = 36, when you find i = 6 as a divisor, 36 / 6 = 6 is its pair.

This reduces the time complexity from O(n) to O(√n).

🔹 Example

If n = 36:

Loop goes from 1 to 6 (since √36 = 6).

Found pairs:

1 and 36

2 and 18

3 and 12

4 and 9

6 (only once, since 6*6=36)


Output :

1 36 2 18 3 12 4 9 6

🔹 Time Complexity : O(√n) (much faster than O(n) for large n). 


Algorithm :

**/



#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

#define el endl

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

 const int N = 1e5 + 5;
// const int mod = 1e9+7 ;

   // Divisors for any integer number

int main() {

ll n ;

 cin >> n;


    vector<ll>diviisors ;


    for (int i = 1; i*i <= n; ++i) {



        if (n%i == 0 ) {

            diviisors.push_back(i) ;


            if (i*i != n) diviisors.push_back( n / i )  ;

        }

    }

    for (auto it :diviisors) {


        cout << it << " " ;

    }


}



