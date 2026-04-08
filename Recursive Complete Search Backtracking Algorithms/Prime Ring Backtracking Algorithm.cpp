/**


   ( Prime Ring Backtracking Algorithm )

   Description:

    Systematically constructs and prints all circular permutations of 1..n where adjacent sums are prime, using backtracking. 

The algorithm generates all possible Prime Rings of size n.
A Prime Ring is a circular arrangement of the numbers 1 through n such that:

1- Each number appears exactly once.

2- The first number is always 1 (to remove rotational duplicates).

3- The sum of every two adjacent numbers in the ring is a prime number (including the last number and the first number).

The algorithm uses recursive backtracking:

* Start with the sequence {1} fixed.

* At each step, try adding an unused number i (from 2 to n) if the sum with the last number in the sequence is prime.

* Continue recursively until a full ring of length n is formed.

* If the final number also forms a prime sum with 1, print the sequence.

* Otherwise, backtrack and try other possibilities.

Because it explores all possibilities and undoes wrong choices, it guarantees all valid Prime Rings are generated.


test case :

n = 6

We need to arrange {1,2,3,4,5,6} in a ring where adjacent sums are prime.

Initialization

prime[] contains primes up to 31.

cant[1] = 1 → number 1 is fixed in the sequence.

Start: v = {1}.


Backtracking Trace :

We try candidates i = 2..6 step by step:

Step 1: Extend {1}

Try 2: 1+2=3 (prime ✅) → choose.

v = {1,2}, mark 2 used.

Step 2: Extend {1,2}

Candidates: 3..6

3: 2+3=5 (prime ✅) → choose.

v = {1,2,3}

4: 2+4=6 (not prime ❌)

5: 2+5=7 (prime ✅) → another branch.

6: 2+6=8 (not prime ❌)

Let’s follow the {1,2,3} path first.


Step 3: Extend {1,2,3}

Candidates left: 4,5,6

4: 3+4=7 (prime ✅) → choose.

v = {1,2,3,4}

5: 3+5=8 (not prime ❌)

6: 3+6=9 (not prime ❌)

So only {1,2,3,4} continues.


Step 4: Extend {1,2,3,4}

Candidates: 5,6

5: 4+5=9 (not prime ❌)

6: 4+6=10 (not prime ❌)

👉 Dead end → backtrack to {1,2,3}.


Back to {1,2,3}

Try 5 or 6: both invalid → backtrack to {1,2}.


Back to {1,2}

Try 5: 2+5=7 (prime ✅)

v = {1,2,5}

Step 3: Extend {1,2,5}

Candidates: 3,4,6

3: 5+3=8 (not prime ❌)

4: 5+4=9 (not prime ❌)

6: 5+6=11 (prime ✅)

v = {1,2,5,6}


Step 4: Extend {1,2,5,6}

Candidates: 3,4

3: 6+3=9 (not prime ❌)

4: 6+4=10 (not prime ❌)

Dead end → backtrack.


Eventually…

The algorithm keeps exploring all branches.
One valid prime ring for n=6 is:

1 4 3 2 5 6

Check sums:

1+4=5 ✅

4+3=7 ✅

3+2=5 ✅

2+5=7 ✅

5+6=11 ✅

6+1=7 ✅ (wrap-around check)

Output for n=6

Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

{1}
 ├─ 2 (1+2=3 prime)
 │   ├─ 3 (2+3=5 prime)
 │   │   ├─ 4 (3+4=7 prime)
 │   │   │   ├─ 5 (dead, 4+5=9 not prime)
 │   │   │   └─ 6 (dead, 4+6=10 not prime)
 │   │   ├─ 5 (dead, 3+5=8 not prime)
 │   │   └─ 6 (dead, 3+6=9 not prime)
 │   └─ 5 (2+5=7 prime)
 │       ├─ 3 (dead, 5+3=8 not prime)
 │       ├─ 4 (dead, 5+4=9 not prime)
 │       └─ 6 (5+6=11 prime)
 │           ├─ 3 (dead, 6+3=9 not prime)
 │           └─ 4 (dead, 6+4=10 not prime)
 │
 ├─ 3 (1+3=4 not prime ❌)
 │
 ├─ 4 (1+4=5 prime)
 │   ├─ 2 (4+2=6 not prime ❌)
 │   ├─ 3 (4+3=7 prime)
 │   │   ├─ 2 (3+2=5 prime)
 │   │   │   ├─ 5 (2+5=7 prime)
 │   │   │   │   └─ 6 (5+6=11 prime, 6+1=7 prime ✅ SOLUTION)
 │   │   │   └─ 6 (dead, 2+6=8 not prime)
 │   │   ├─ 5 (dead, 3+5=8 not prime)
 │   │   └─ 6 (dead, 3+6=9 not prime)
 │   ├─ 5 (dead, 4+5=9 not prime)
 │   └─ 6 (dead, 4+6=10 not prime)
 │
 ├─ 5 (1+5=6 not prime ❌)
 │
 └─ 6 (1+6=7 prime)
     ├─ 2 (6+2=8 not prime ❌)
     ├─ 3 (6+3=9 not prime ❌)
     ├─ 4 (6+4=10 not prime ❌)
     └─ 5 (6+5=11 prime)
         ├─ 2 (5+2=7 prime)
         │   ├─ 3 (2+3=5 prime)
         │   │   ├─ 4 (3+4=7 prime, 4+1=5 prime ✅ SOLUTION)
         │   │   └─ 6 (dead, 3+6=9 not prime)
         │   └─ 4 (dead, 2+4=6 not prime)
         └─ 4 (dead, 5+4=9 not prime)



   ( Algorithm ) :

**/


#include<bits/stdc++.h>   // includes all standard C++ libraries

#define ll long long

#define endl '\n'

using namespace std;

// -------------------- GLOBAL VARIABLES -------------------- //

int n;                    // number of circles (the size of the ring)

bool cant[20];            // cant[i] = true if number i is already used

bool prime[50];           // prime[x] = true if x is prime

vector<int> v = { 1 };    // current sequence, always starts with 1 (fixed at start)

// -------------------- BACKTRACKING FUNCTION -------------------- //

void solve()

{
    // ---- BASE CASE ----

    // If we filled all n numbers into the ring

    if (v.size() == n) {

        // Check if the last element + first element is prime (close the ring)

        if (prime[1 + v.back()]) {

            // Print current valid sequence

            for (int i = 0; i < n-1; ++i) {

                cout << v[i] << " ";

            }

            cout << v.back() << endl;
        }
    }

    // ---- RECURSIVE CASE ----

    // Try all candidates from 2..n (since 1 is fixed at start)

    for (int i = 2; i <= n; ++i) {


        // Condition: number not used yet AND sum with last element is prime

        if (!cant[i] && prime[i + v.back()]) {

            
            // ---- CHOOSE ----

            cant[i] = 1;       // mark i as used

            v.push_back(i);    // add i to the current sequence


            solve();           // recursive call (go deeper)

            // ---- UNDO (BACKTRACK) ----

            cant[i] = 0;       // unmark i (make it available again)

            v.pop_back();      // remove i from the sequence

        }
    }
}

// -------------------- MAIN FUNCTION -------------------- //

int main() {

    ios::sync_with_stdio(false);

    cout.tie(nullptr);

    cin.tie(nullptr);

    // ---- Initialize prime lookup table ----

    // Only primes up to 31 are needed because:

    // maximum possible sum = 16 + 15 = 31 (since max n = 16)

    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = 1;

    prime[13] = prime[17] = prime[19] = prime[23] = 1;

    prime[29] = prime[31] = 1;

    cant[1] = 1;   // mark 1 as used (fixed in the first position)

    int tc = 0;    // test case counter

    // Read multiple test cases until EOF

    while (cin >> n)

    {
        if (tc != 0)

            cout << endl;      // blank line between test cases

        tc++;

        cout << "Case " << tc << ":" << endl;

        solve();               // generate and print all valid prime rings

    }

    return 0;

}


