
/**
         ( Minimum Adjacent Swap Algorithm to Position Extremes ) :



Algorithm to Calculate the Minimum Number of Adjacent Swaps Required to Reposition the Maximum Element at the Beginning and the Minimum Element at the End of an Unsorted Array

You are given an unsorted array, and you want to know:

How many swaps (between adjacent elements) are needed to:

Move the maximum element to the beginning of the array

Move the minimum element to the end of the array

NOTE: You are allowed to only swap adjacent elements, and each swap takes 1 second.


     ✅ Algorithm Steps:


Find the index of the first occurrence of the maximum height (from the left)

Find the index of the last occurrence of the minimum height (from the right)


Compute:

Moves to bring the max height to the front → max_index

Moves to bring the min height to the end → (n - 1 - min_index)

If max_index > min_index, subtract 1, because their paths will cross once during the swaps AND MAKE Duplicates in number of Swaps .


 ✅ Test Case 1: index of max < index of min

Initial Array: [4, 3, 5, 2, 1]

max = 5, index = 2

min = 1, index = 4

🔁 Step-by-step Swap Plan:

1. Move 5 to the front (index 0):


[4, 3, 5, 2, 1]
       ↑
   Swap 5 and 3 → [4, 5, 3, 2, 1]

   Swap 5 and 4 → [5, 4, 3, 2, 1]

✅ 5 is now at the front (2 swaps)


2. Move 1 to the end (already at index 4, so 0 swaps)

✅ Result:
Total swaps = 2 + 0 = 2

Final array: [5, 4, 3, 2, 1]


✏️ Test Case 2: index of max > index of min
🔢 Initial Array:


[2, 4, 1, 3, 3, 5]

max = 5, index = 5

min = 1, index = 2

🎯 Goal:
Move 5 to the start (index 0)

Move 1 to the end (index 5)

Because max_index > min_index, they will cross, so we'll subtract 1 swap at the end.

🔁 Step-by-Step Swaps:

🔹 Move 5 to the front
Current:


[2, 4, 1, 3, 3, 5]
                         ↑
Step 1 – Swap 5 and 3:


[2, 4, 1, 3, 5, 3]


Step 2 – Swap 5 and 3:

[2, 4, 1, 5, 3, 3]


Step 3 – Swap 5 and 1:

[2, 4, 5, 1, 3, 3]

Step 4 – Swap 5 and 4:

[2, 5, 4, 1, 3, 3]


Step 5 – Swap 5 and 2:

[5, 2, 4, 1, 3, 3]

✅ Now 5 is at index 0 (front).
🕒 Swaps used: 5

🔹 Move 1 to the end
Now 1 is at index 3:


[5, 2, 4, 1, 3, 3]
             ↑
Step 1 – Swap 1 and 3:

[5, 2, 4, 3, 1, 3]


Step 2 – Swap 1 and 3 again:

[5, 2, 4, 3, 3, 1]


✅ Now 1 is at the end.
🕒 Swaps used: 2

🧮 Total Swaps
Swaps for 5 = 5

Swaps for 1 = 2

They crossed, so subtract 1
✅ 5 + 2 - 1 = 6 swaps

✅ Final Array:

[5, 2, 4, 3, 3, 1]



   ( Algorithm :)

   **/

     #include <bits/stdc++.h>
using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long

// أن تكون حيا فقط لا تكفي ! يجب أن تمتلك ضوء شمس، حرية، أو زهرة صغيرة داخل قلبك ))

int main() {

    FastIO

    int n;
    cin >> n;                    // Read the number of soldiers

    vector<int> vec(n);         // Vector to store soldiers' heights


    for (int i = 0; i < n; ++i) {


        cin >> vec[i];          // Read heights

    }

    // Find the index of the first occurrence of the maximum height

    int id_mx = max_element(vec.begin(), vec.end()) - vec.begin();

    int id_mn = 0;              // To store the index of the last occurrence of the minimum height
    int mn = INT_MAX;

    // Traverse the array to find the last (rightmost) index of the minimum height

    for (int i = 0; i < vec.size() ; ++i) {

        if (mn >= vec[i]) {

            mn = vec[i] ;

            id_mn = i ;

        }
    }

    // If max is after min, they will cross during swapping → subtract 1 from total

    if (id_mx > id_mn) {

        int res = id_mx + (vec.size() - id_mn - 1);

        cout << res - 1 << "\n";

    } else {

        cout << id_mx + (vec.size() - id_mn - 1) << "\n";
    }

    return 0;
}













