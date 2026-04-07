/**

      ( Merged Order Book Using Maps in C++ (BuySell Aggregation) )


    Merged Map :

  You are building a "merged map" where:

If you have multiple entries with the same key, you sum their values.

Example:
    
Input: keys: 50, 50, 50    values: 2, 6, 3

Result: (50, 11)



    ✅ Input:

n = 6, s = 2

B 10 3   → Buy 3 units at price 10

S 50 2   → Sell 2 units at price 50

S 40 1   → Sell 1 unit  at price 40

S 50 6   → Sell 6 units at price 50 (merged with previous one)

B 20 4   → Buy 4 units at price 20

B 25 10  → Buy 10 units at price 25


 🧠 After Merging in Maps:

m1 (Buy Orders):

10 → 3

20 → 4

25 → 10


   m2 (Sell Orders):

40 → 1

50 → 2 + 6 = 8

📤 Output:

Sell Orders (Lowest Prices First, Up to s = 2 entries, printed in reverse order):

Sorted ascending: 40 → 1, 50 → 8

Reversed for output:


S 50 8  

S 40 1  



Buy Orders (Highest Prices First, Up to s = 2 entries):

Sorted descending: 25 → 10, 20 → 4

B 25 10  

B 20 4  

🧾 Final Output:

S 50 8

S 40 1

B 25 10

B 20 4




   Algorithm : 

**/ 


  #include <bits/stdc++.h>

using namespace std;

int main() {

    int n, s;

    cin >> n >> s;  // n = number of orders, s = max number of lines to display per type (B/S)

    map<int, int> m1, m2;  // m1 for Buy orders (B), m2 for Sell orders (S)


    char c;  // Order type: 'B' for Buy, 'S' for Sell

    int p, v; // p = price, v = volume


    // Input loop to read and merge orders

    for (int i = 0; i < n; i++) {

        cin >> c >> p >> v;


        if (c == 'B') {

            m1[p] += v;  // Merge Buy orders by summing volumes at the same price

        } else {

            m2[p] += v;  // Merge Sell orders by summing volumes at the same price

        }
    }

    // Output top s Sell orders (lowest prices first, printed in reverse to match order book)

    if (m2.size()) {

        int idx = 0;

        auto itr = m2.begin();  // Start from lowest sell price


        // Move itr s steps forward or until the end

        for (; idx < s && itr != m2.end(); itr++, idx++);

        itr--;  // Move back to the last valid element


        // Print s Sell orders in descending price order

        for (; itr != m2.begin(); itr--) {

            cout << "S " << itr->first << " " << itr->second << "\n";

        }
        cout << "S " << itr->first << " " << itr->second << "\n"; // Print the first one

    }

    // Output top s Buy orders (highest prices first)

    if (m1.size()) {

        int idx = 0;

        auto itr = m1.rbegin();  // Start from highest buy price


        // Print up to s Buy orders

        for (; idx < s && itr != m1.rend(); itr++, idx++) {

            cout << "B " << itr->first << " " << itr->second << "\n";

        }
    }

    return 0;
}


