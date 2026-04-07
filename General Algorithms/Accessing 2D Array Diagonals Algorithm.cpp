
/***

       ( Accessing and Summing Both Diagonals in a Matrix (Accessing 2D Array Diagonals Algorithm) )  :


🔵1   2   🟥3
 4  🔵5   6
🟥7   8  🔵9


    Main Diagonal Sum = 15   // 1 + 5 + 9
    Secondary Diagonal Sum = 15  // 3 + 5 + 7


       ✅ Step 1: Input matrix size n
       → This is how many rows/columns the matrix has.



     ✅ Step 2: Fill the matrix using nested loops
     → Loop through i and j to input every value into arr[i][j]



    ✅ Step 3: Calculate main diagonal sum d1
    → Loop: for (i = 0; i < n; i++)
    → Use arr[i][i] to access main diagonal elements
    → Add them to d1




   ✅ Step 4: Calculate secondary diagonal sum d2
   → Loop: for (i = 0, j = n-1; i < n && j >= 0; i++, j--)
   → Use arr[i][j] to access secondary diagonal elements
   → Add them to d2




   ( Algorithm )  :


   ***/


#include <bits/stdc++.h>
  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;




  int main() {

    FastIO

    int n;
    cin >> n;

    // Step 1: Input matrix values

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            cin >> arr[i][j];

        }
    }



    // Step 2: Calculate main diagonal sum

    int d1 = 0;
    for (int i = 0; i < n; ++i) {

        d1 += arr[i][i];

    }



    // Step 3: Calculate secondary diagonal sum

    int d2 = 0;

    for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {

        d2 += arr[i][j];

    }




    // Output result (optional)

    cout << "Main Diagonal Sum = " << d1 << "\n";

    cout << "Secondary Diagonal Sum = " << d2 << "\n";



  return 0;

}

