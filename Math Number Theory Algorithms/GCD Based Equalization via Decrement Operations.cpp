/**


      ( GCD Based Equalization via Decrement Operations ) :( Maximum Valid Decrement Step Algorithm) :



         Description

This algorithm determines the maximum possible positive integer k such that an array of even length can be transformed into a state where all elements become equal, using only operations that decrement any element by exactly k any number of times.

The solution is based on number theory. By observing that all elements must reach a common final value, the algorithm computes the greatest common divisor (GCD) of the differences between each element and the minimum element in the array. This GCD represents the largest valid step size k that preserves divisibility across all elements.

If all elements are already equal, the algorithm correctly identifies that k can be arbitrarily large and returns -1.


✅ Test Case:

  Input
1
6
1 5 3 1 1 5

Output
2
 
   Explanation

min = 1

differences = {0,4,2,0,0,4}

gcd = 2


 ✅ Test Case:

    Input
1
4
7 7 7 7

Output
-1

          ( Algorithm ) :

/**


   #include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;


    while (t--) {
        int n;

        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {

            cin >> a[i];
        }

        long long mn = *min_element(a.begin(), a.end());

        long long g = 0;

        for (int i = 0; i < n; i++) {

            g = gcd(g, a[i] - mn);
        }

        if (g == 0)

            cout << -1 << "\n";

        else
            cout << g << "\n";
    }

    return 0;
}

