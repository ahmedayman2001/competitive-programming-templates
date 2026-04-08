
/**

     ( Lucky Number Range Summation Algorithm )


🔹 Description:

  The algorithm calculates the sum of all integers in a given range [l, r], but with a twist:

Each integer is assigned the value of the next lucky number greater than or equal to it.

A lucky number is defined as a number consisting only of digits 4 and 7 (e.g., 4, 7, 44, 47, 74, 77, 444,


🔹 How it works:

1- Generate all lucky numbers up to 1e10 using recursion (solve() function).

🔹Start from 0 and recursively build numbers by appending 4 or 7.

🔹Store all generated lucky numbers in the vector lucky.

2- Sort the lucky numbers for binary search usage.

3- Iterate through the range [l, r]:

🔹Use lower_bound to find the next lucky number v ≥ l.

🔹Compute the segment [l, right] where right = min(r, v).

🔹For all numbers in this segment, each contributes with value v.

🔹Add the contribution: (right - l + 1) * v.

🔹Move l to the next position right + 1 and continue until reaching r.

4- Print the total sum.

🔹 Example:

If l = 8, r = 10:

Next lucky numbers are: 44, 44, 44.

Contribution = (10 - 8 + 1) * 44 = 3 * 44 = 132.

Test case :
 input :
2 7

output :
33
 next(2) + next(3) + next(4) + next(5) + next(6) + next(7) = 4 + 4 + 4 + 7 + 7 + 7 = 33

 input :
7 7

output :
7  
next(7) = 7 .



   🔹Algorithm Steps: 

 1- Generate all lucky numbers (numbers with digits only 4 and 7) up to 1e10.

2- Sort them for quick access.

3- For each number in [l, r], replace it with the next lucky number ≥ that number.

4- Compute the weighted sum efficiently by processing intervals instead of looping through every number.



let’s trace it step by step with an example.

l = 8, r = 10


🔹 Lucky numbers generated (smallest ones relevant here):

4, 7, 44, 47, 74, 77, …


🔹 Trace Table:

| Step | Current `l` | `r` | `lower_bound(l)` → `v` | `right = min(r, v)` | Contribution `(right - l + 1) * v` | `ans` (cumulative) | Next `l = right + 1` |
| ---- | ----------- | --- | ---------------------- | ------------------- | ---------------------------------- | ------------------ | -------------------- |
| 1    |         8               |    10                          |         44                 |     min(10, 44) = 10              | (10 - 8 + 1) \* 44 = 3 \* 44 = 132 |            132                         |                      11                   |

🔹 Loop exit condition:

Now l = 11, but r = 10, so l > r.
The while loop ends.

🔹 Final Output:
132




 ( Algorithm ) :

**/


 #include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


// A vector to store all lucky numbers

vector<ll> lucky;

// Recursive function to generate all lucky numbers up to 1e10

void solve(ll x) {

    // Stop recursion if number exceeds the upper limit

    if (x > 1e10) return;

    // Recursively build numbers by appending digit '4'

    solve(x * 10 + 4);

    // Recursively build numbers by appending digit '7'

    solve(x * 10 + 7);

    // Store the number x (this will include 0 initially, but will be sorted later)

    lucky.push_back(x);
}

int main() {

    FastIO // Fast input/output

    // Generate all lucky numbers (starting from 0)

    solve(0);

    // Sort the list of lucky numbers for binary search operations

    sort(lucky.begin(), lucky.end());

    ll l, r; 

    cin >> l >> r;   // Input the range [l, r]


    ll ans = 0;      // To accumulate the final answer

    // Process the range from l to r

    while (l <= r) {

        // Find the smallest lucky number >= l

        auto it = lower_bound(lucky.begin(), lucky.end(), l);

        ll v = *it;   // v is the next lucky number

        // The right boundary of this segment: either r or v (whichever is smaller)

        ll right = min(r, v);

        // For all numbers in [l, right], each contributes with value v

        // Contribution = count of numbers * v

        ans += (right - l + 1) * v;

        // Move l to the next position after "right"

        l = right + 1;
    }

    // Print the final accumulated sum

    cout << ans << "\n";

    return 0;
}



















