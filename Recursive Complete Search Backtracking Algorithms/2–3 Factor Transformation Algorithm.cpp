/**


  ( 2–3 Factor Transformation Algorithm ):

  🔹 Description:

This algorithm determines the minimum number of operations required to transform an integer n into another integer m, under the constraint that in each operation you can only multiply by 2 or multiply by 3.

Steps it follows:


1- Check if m is divisible by n.

🔹If not, the transformation is impossible → return -1.

2- Compute the ratio k = m / n.

3- Repeatedly divide k by 2 and count how many times this is possible.

4- Repeatedly divide k by 3 and count how many times this is possible.

5- If after removing all factors of 2 and 3, k = 1, then the transformation is possible.

🔹The answer is the total count of divisions (steps).

6- If any prime factor other than 2 or 3 remains, output -1.


Test case :

Input: n = 10, m = 40

m/n = 4 = 2 * 2 → two multiplications by 2 → output 2.

Input: n = 10, m = 60

m/n = 6 = 2 * 3 → one multiplication by 2 and one by 3 → output 2.

Input: n = 10, m = 25

m/n = 2.5 not integer → output -1.


  ( Algorithm ) :

**/


#include <bits/stdc++.h>   // include all standard C++ libraries

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

#define ll long long   // shorthand for long long

int main() {

    FastIO  // fast input/output

    ll n, m;

    cin >> n >> m;   // read input values n and m

    // Step 1: check if m can be divisible by n

    // If not divisible, it's impossible to transform n into m

    if (m % n != 0) { 

        cout << -1 << "\n";

        return 0;
    }

    // Step 2: compute ratio (what we need to multiply n by to reach m)

    ll k = m / n;

    int cnt = 0;  // counter for number of operations

    // Step 3: divide by 2 as many times as possible

    // each division by 2 means one multiplication by 2 in forward process

    while (k % 2 == 0) {

        k /= 2;

        cnt++;

    }

    // Step 4: divide by 3 as many times as possible

    // each division by 3 means one multiplication by 3 in forward process

    while (k % 3 == 0) {

        k /= 3;

        cnt++;

    }

    // Step 5: after removing all factors of 2 and 3,

    // if we still have something left (k != 1), then impossible

    if (k != 1) {

        cout << -1 << "\n";

    } else {

        // otherwise, cnt is the minimum number of steps required

        cout << cnt << "\n";

    }

    return 0;
}


