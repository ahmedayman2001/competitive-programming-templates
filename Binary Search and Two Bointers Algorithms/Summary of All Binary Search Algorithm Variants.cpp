/**


( 🔁 Summary of All Binary Search Variants ) : 


| Goal                           | Condition     | Direction     | What to Save |

| ------------------------------ | ------------- | ------------- | ------------ |

| First `>= x` (**lower bound**) | `a[mid] >= x` | `r = mid - 1` | `ans = mid`  |

| First `> x` (**upper bound**)  | `a[mid] > x`  | `r = mid - 1` | `ans = mid`  |

| Last `< x`                     | `a[mid] < x`  | `l = mid + 1` | `ans = mid`  |

| Last `<= x`                    | `a[mid] <= x` | `l = mid + 1` | `ans = mid`  |



✅ Problem:

Given a sorted array, implement the following binary search functions:

firstGreaterEqual(x) → First element ≥ x

firstGreater(x) → First element > x

lastLess(x) → Last element < x

lastLessEqual(x) → Last element ≤ x


**/





#include <bits/stdc++.h>

using namespace std;

int a[] = {1, 5, 10, 15, 22, 23, 31, 35};

int n = sizeof(a) / sizeof(a[0]);

// First element >= x

int firstGreaterEqual(int x) {

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] >= x) {

            ans = mid;

            r = mid - 1;  // go left

        } else {

            l = mid + 1;
        }

    }

    return ans;

}

// First element > x


int firstGreater(int x) {

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] > x) {

            ans = mid;

            r = mid - 1;  // go left

        } else {

            l = mid + 1;
        }
    }
    return ans;
}

// Last element < x

int lastLess(int x) {

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] < x) {

            ans = mid;

            l = mid + 1;  // go right

        } else {

            r = mid - 1;
        }

    }

    return ans;
}

// Last element <= x

int lastLessEqual(int x) {

    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] <= x) {

            ans = mid;

            l = mid + 1;  // go right

        } else {

            r = mid - 1;

        }

    }

    return ans;

}

int main() {

    int x = 22;

    int idx1 = firstGreaterEqual(x);

    int idx2 = firstGreater(x);

    int idx3 = lastLess(x);

    int idx4 = lastLessEqual(x);

    cout << "Array: ";

    for (int i = 0; i < n; ++i) cout << a[i] << " ";

    cout << "\n\nTarget x = " << x << "\n\n";

    if (idx1 != -1)

        cout << "First element >= " << x << " is " << a[idx1] << " at index " << idx1 << '\n';

    else
        cout << "No element >= " << x << '\n';


    if (idx2 != -1)

        cout << "First element > " << x << " is " << a[idx2] << " at index " << idx2 << '\n';

    else

        cout << "No element > " << x << '\n';

    if (idx3 != -1)

        cout << "Last element < " << x << " is " << a[idx3] << " at index " << idx3 << '\n';

    else

        cout << "No element < " << x << '\n';

    if (idx4 != -1)

        cout << "Last element <= " << x << " is " << a[idx4] << " at index " << idx4 << '\n';

    else

        cout << "No element <= " << x << '\n';


    return 0;

}


