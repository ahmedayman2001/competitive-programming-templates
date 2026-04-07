
/**
(Compute Difference Between First and Last Elements in Each Window of a Sorted Array)

Test Case :

Let's assume:

n = 3  (window size)  and m = 6

Sorted array: [3, 4, 6, 9, 15, 17]

Indices: 0 1 2 3 4 5

🔹 Array and Indices:

Index:     0   1   2   3   4   5
Array:    [3,  4,  6,  9, 15, 17]

🔸 Sliding Windows with Arrows:

1️⃣ First window: 3 → 6

       ↓       ↓       ↓
Index: 0   1   2   3   4   5
Array: [3,  4,  6,  9, 15, 17]
         ↖-------↗
     diff = 6 - 3 = 3

2️⃣ Second window: 4 → 9

           ↓       ↓       ↓
Index: 0   1   2   3   4   5
Array: [3,  4,  6,  9, 15, 17]
             ↖-------↗
         diff = 9 - 4 = 5

3️⃣ Third window: 6 → 15

               ↓       ↓       ↓
Index: 0   1   2   3   4   5
Array: [3,  4,  6,  9, 15, 17]
                 ↖-------↗
             diff = 15 - 6 = 9

4️⃣ Fourth window: 9 → 17

                   ↓       ↓
Index: 0   1   2   3   4   5
Array: [3,  4,  6,  9, 15, 17]
                     ↖-------↗
                 diff = 17 - 9 = 8

✅ Final Answer:

The minimum difference from all windows of size n = 3 is:

min(3, 5, 9, 8) = 3



✅ Approach (Algorithm):

🔹 Goal:

1- Find the minimum difference between the maximum and minimum number of pieces among any group of n puzzles.

🔹 Steps:

Input n, m, and the array f of m puzzle piece counts.

2- Sort the array f in ascending order.


3- Slide a window of size n across the sorted array and for each window:

Compute the difference between the last and first element (max - min).

4- Track the minimum difference found.

5- Output that minimum.



 ( Algorithm: )

 **/


    #include <bits/stdc++.h>

  using namespace std;

// Fast I/O for competitive programming

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

// Define long long shortcut

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوء شمس، حرية، أو زهرة صغيرة داخل قلبك :)

int main() {
    FastIO

    // Declare two vectors (vec2 is unused)

    vector<int> vec;

    vector<int> vec2;

    int n, m;
    cin >> n >> m;  // Input number of students and number of puzzles

    // Read puzzle piece counts into vec

    for (int i = 0; i < m; ++i) {

        int x;
        cin >> x;
        vec.push_back(x);
    }

    // Sort the puzzle pieces in ascending order

    sort(vec.begin(), vec.end());

    // Initialize the minimum difference to a large number

    int mn = INT_MAX;

    // Iterate through all windows of size n in the sorted array

    for (int i = 0; i + n - 1 < m; ++i) {


        // Compute the difference between the max and min in the current window
        // Since the array is sorted, the window is from vec[i] to vec[i+n-1]

        mn = min(abs(vec[i + n - 1] - vec[i]), mn) ;

    }

    // Output the minimum difference found

    cout << mn << "\n";


    return 0;
}
