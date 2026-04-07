
 /**

     (🔷 "Next Lexicographic Permutation" Algorithm )

   Lexicographic Order Example

   For N = 3:

   All permutations of [1, 2, 3] in lexicographic order are:

[1, 2, 3]

[1, 3, 2]

[2, 1, 3]

[2, 3, 1]

[3, 1, 2]

[3, 2, 1]

So, for example:

[1, 3, 2] is 2nd

[3, 1, 2] is 5th

|2 - 5| = 3


    🔢 Algorithm Plan:

   Generate all permutations of [1..N]

  Sort them in lexicographic order

   Find the 1-based index of permutation P and Q

  Return abs(index_P - index_Q)


  test case :

3 : array size
1 3 2 : random permution  : idx1
3 1 2 : random permution :idx2

( Algorithm :)

**/



#include<bits/stdc++.h>
using namespace std;

/*
 أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;
*/

int main()
{
    int n;

    cin >> n;


    // Declare three arrays:

    // arr1 and arr2 for input permutations

    // arr for generating all permutations starting from [1, 2, ..., n]

    int arr1[n], arr2[n], arr[n];


    // Input first permutation

    for (int i = 0; i < n; ++i) {

        cin >> arr1[i];
    }

    // Input second permutation

    for (int i = 0; i < n; ++i) {

        cin >> arr2[i];
    }

    // Initialize arr = [1, 2, ..., n]

    for (int i = 0; i < n; ++i) {

        arr[i] = i + 1;
    }

    int idx1, idx2, i = 1; // i represents the current permutation index (1-based)


    // Generate all permutations in lexicographic order

    do {

        bool flag = 0;

        // Check if current permutation == arr1

        for (int i = 0; i < n; ++i) {

            if (arr[i] != arr1[i]) {

                flag = 1;

                break;
            }
        }

        // If match found, store the index

        if (flag == 0) {

            idx1 = i;
        }

        flag = 0;

        // Check if current permutation == arr2


        for (int i = 0; i < n; ++i) {

            if (arr[i] != arr2[i]) {

                flag = 1;

                break;
            }
        }

        // If match found, store the index

        if (flag == 0) {

            idx2 = i;
        }

        i++;  // Move to next permutation index

    } while ( next_permutation ( arr, arr + n ) ) ;   // Continue while next permutation exists


    // Output the absolute difference between the two positions


    cout << abs(idx1 - idx2) << "\n";


    return 0;

}
