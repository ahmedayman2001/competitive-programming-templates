/**

     ( Find 3 Distinct Worms Satisfying ai = aj + ak )


  ✅ Explanation :

1-Input Reading:

Read n — the number of worm forms.

Read an array a of length n, where a[i] is the length of the i-th worm.


2-Brute Force Search:

Loop over all combinations of i, j, k.

Skip any case where indices are not distinct.

Check if a[i] == a[j] + a[k].

If found, print the indices (1-based) and exit.


3-Output:

If no such triple exists, print -1.

✅ Start of Triple Loop:

Let’s go step by step and try all combinations.

🔁 Outer loop: x = 1

vec[x] = 1

⮞ Inner loop: y = 1 → skip (x == y)

⮞ y = 2 → vec[y] = 2

Now test all z values:


➤ z = 1 → skip (x == z)

➤ z = 2 → skip (y == z)

➤ z = 3 → vec[3] = 3

Check:

vec[3] == vec[1] + vec[2]

   3   ==   1    +   2  → ✅ TRUE


Also: 1 ≠ 2 ≠ 3 → valid


vec[1] = 1

vec[2] = 2

vec[3] = 3

1 + 2 = 3 → All indices are different → ✅


     Algorithm :

**/


  #include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لا تكفي ! يجب أن تمتلك ضوء شمس، حرية، أو زهرة صغيرة داخل قلبك ))


int main() {

    FastIO


    int n;

    cin >> n;

    vector<int> vec(n + 1);  // 1-based indexing

    // Input worm lengths

    for (int i = 1; i <= n; ++i) {

        cin >> vec[i];

    }

    // Try all triplets (x, y, z) such that vec[z] == vec[x] + vec[y]

    for (int x = 1; x <= n; ++x) {       //  x=1

        for (int y = 1; y <= n; ++y) {     // y =1

            for (int z = 1; z <= n; ++z) {     // z=1,2,3,4,...n 

                if (vec[z] == vec[x] + vec[y] && x != y && x != z && y != z) {

                    cout << z << " " << y << " " << x << "\n";

                    return 0;

                }

            }

        }

    }

    // If no valid triplet is found

    cout << -1 << "\n";

    return 0;
}





