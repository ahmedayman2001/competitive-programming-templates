
/**

    ( Card Reordering to Maximize Deck Order Using Greedy Segments )
       ( Algorithm for Print Array Maximum as Possible Order )


     You’re given a deck of cards (vector v1) from bottom to top.

You want to build a new deck using the rule:
→ Take any number k > 0 of top cards and place them on top of the new deck, maintaining their order.

Your goal is to maximize the final deck's "order" value:


So you want big numbers deeper in the final deck (higher weight).


✅ Steps :

Build prefix max array:

v2[i] = max of v1[1..i]

Traverse the original deck from top to bottom (right to left).

When you find an element equal to the max seen so far (v1[i] == v2[i]), this means:

From position i to r is a valid block to move now.

Move it to the result and update r = i - 1.

This ensures we always move the segment ending at the largest unseen value, which gives us a greedy maximal order.

Test case :

   3

4

1 2 3 4

5

1 5 2 4 3

6

4 2 5 3 6 1


 output :

4 3 2 1

5 2 4 3 1

6 1 5 3 4 2



   ( Algorithm : )

 **/

      #include <bits/stdc++.h>

   using namespace std;

// أن تكون حيا فقط لا تكفي! يجب أن تمتلك ضوء شمس، حرية، أو زهرة صغيرة داخل قلبك :)


int main() {

    int t;

    cin >> t;   // Number of test cases


    while (t--) {

        int n;

        cin >> n;

        vector<int> v1(n + 1); // The original deck (1-based indexing)

        vector<int> v2(n + 1); // Prefix max array

        int mx = 0
;
        for (int i = 1; i <= n; ++i) {

            cin >> v1[i];             // Read each card

            mx = max ( mx , v1[i]);      // Track max so far

            v2[i] = mx ;               // Save max at position i

        }

        int r = n;  // Right pointer for block segment


        // Traverse from right to left ( top to bottom )

        for (int i = n; i >= 1; --i) {

            if (v1[i] == v2[i]) {

                // Found a segment to move: [i .. r]

                for (int j = i; j <= r; ++j) {

                    cout << v1[j] << " ";

                }

                r = i - 1; // Shrink the unprocessed part
            }
        }
    }

    cout << "\n"; // Final newline

    return 0;
}


