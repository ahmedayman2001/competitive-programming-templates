
/**
( "Reverse Engineering Prefix Cyclic Right Shifts to Recover Original Shift Counts" ) :



✅ Algorithm Description :

* In general, if I have a sorted array and the same array but in a shuffled (not sorted) version,
I want to know
How many operations (or shifts) are needed for each element in the sorted array
so that it reaches its new position in the final (not sorted) array

In other words
For every element in the sorted array, how many steps (or moves) do I need to make
to bring it to its position in the not sorted array.



* this idea is related to circular arrays only if all elements are rotated by the same number of steps (i.e., a circular shift).
If each element moves differently, then it's not a circular array, but it's still valid to calculate the shift (movement) for each element individually.





summary of the Logic:


Step	Action

1	Read the final array and map values to positions

2	Work from end (n) to start (1)

3	For each i, calculate how many shifts put i in its current position

4	Undo those shifts on previous elements

5	Store the shifts in ans[i]

6	Output the result

Test case :

Given:

Final array: [3, 2, 5, 6, 1, 4]


Initial sorted array:

[1, 2, 3, 4, 5, 6]


 algorithm outputs:

   0 1 1 2 0 4




Which means:

Step 1 → 0 shifts

Step 2 → 1 shift on [1,2]

Step 3 → 1 shift on [1,2,3]

Step 4 → 2 shifts on [1,2,3,4]

Step 5 → 0 shifts

Step 6 → 4 shifts on [1,2,3,4,5,6]

And if we apply these shifts forward, we get the final array!



  ( Algorithm ) :

  **/



   #include <bits/stdc++.h>

   using namespace std;

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوء شمس، حرية، أو زهرة صغيرة داخل قلبك ))) ;

int main() {

    int t;

    cin >> t;  // Read number of test cases

    while (t--) {

        int n;

        cin >> n; // Read size of the array

        vector<int> vec(n + 1); // vec[x] will store the current index of element x in the final array

        vector<int> ans(n + 1); // ans[i] will store number of right shifts done at step i


        // Read the final array and store the index of each element

        for (int i = 1; i <= n; ++i) {

            int x;

            cin >> x;

            vec[x] = i; // element x is at position i in the final array
        }

        // Reverse simulation from step n down to step 1

        for (int i = n; i >= 1; --i) {

            // vec[i] gives the current position of value i

            // Calculate how many right shifts were done at step i (modulo i to wrap around)

            ans[i] = vec[i] % i;

            // Reverse the effect of the right shift:

            // simulate how positions looked before this operation

            for (int j = 1; j < i; ++j) {

                // Move elements to the left to undo the right shift

                vec[j] = (vec[j] + (i - ans[i])) % i;
            }
        }

        // Output the answer array (number of shifts at each step)

        for (int i = 1; i <= n; ++i) {

            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

