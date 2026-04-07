/**

  (  Dual-Sorted Set of Pairs Algorithm in C++ (By ID and Value) ) :



    Set of Pairs in C++

A Set in C++ stores unique elements in sorted order.

When using:

set<pair<int, int>>

Each pair is treated as a whole unique element, meaning:

{8, 1} is not equal to {8, 3} — even if the first value is the same.

Uniqueness is checked on the entire pair.

🔁 Sorting Behavior:

The set stores elements in ascending order by default.


Sorting is done based on the first element in the pair.


If two first elements are equal, sorting falls back to the second.

(Set 1):

{1, 8}

{2, 10}

{3, 6} 

   (Set 2) (Sorted by second value descending):

 {-10, 2}

{-8, 1}

{-6, 3}
   

     Algorithm : 

**/ 


     #include <bits/stdc++.h>

     using namespace std;


#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

#define ll long long


// "To be alive is not enough — you must have sunlight, freedom, or a small flower inside your heart."

int main() {

    FastIO


    int q; cin >> q;                  // Number of operations (queries)

    int cnt = 0;                      // Counter for each inserted element


    // Set 1: Stores pairs (ID, value), sorted by ID (insertion order)

    set<pair<int, int>> st1;

    // Set 2: Stores pairs (-value, ID), sorted by value in descending order

    set<pair<int, int>> st2;

    while (q--) {

        int op; cin >> op;           // Operation type (1: insert, 2: get min ID, 3: get max value)


        if (op == 1) {
            cnt++;                   // Increment unique ID

            int val; cin >> val;     // Read value

            st1.insert({cnt, val});               // Insert by ID

            st2.insert({-val, cnt});              // Insert by value (descending using -val)

        }

        else if (op == 2) {

            // Get and print the ID of the element with the smallest cnt (earliest inserted)

            pair<int, int> pr = *st1.begin();

            cout << pr.first << " ";

            // Remove from both sets

            st1.erase(pr);

            st2.erase({-pr.second, pr.first});
        }

        else {

            // Get and print the ID of the element with the largest value

            pair<int, int> pr = *st2.begin();

            cout << pr.second << " ";


            // Remove from both sets

            st2.erase(pr);

            st1.erase({pr.second, -pr.first});

        }

    }


    return 0;
}


 





