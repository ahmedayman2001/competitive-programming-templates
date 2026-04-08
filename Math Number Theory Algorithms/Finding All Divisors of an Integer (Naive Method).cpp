
/**

              Finding All Divisors of an Integer (Naive Algorithm)  :


   🔹 Description

 	This algorithm finds all the positive divisors (factors) of a given integer n.

A divisor (or factor) of n is any integer d such that n % d == 0.

The algorithm checks every number from 1 to n.

If a number divides n evenly, it is added to the list of divisors.

Finally, all divisors are printed.


How It Works :


Read the input number n.

Initialize an empty vector divisors.

Iterate i from 1 to n.

If n % i == 0, then i is a divisor → push it into the vector.

Print all collected divisors.

If n = 12:

Check from 1 to 12.

Divisors found: 1, 2, 3, 4, 6, 12.

Output:
1 2 3 4 6 12

Time Complexity : O(n)

Loop goes from 1 to n.


  ( Algorithm ) : 

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


    for (int i = 1; i <= n; ++i) {


        if (n%i == 0 ) {

            diviisors.push_back(i) ;
        }

    }


    for (auto it :diviisors) {


        cout << it << " " ;

    }

}


