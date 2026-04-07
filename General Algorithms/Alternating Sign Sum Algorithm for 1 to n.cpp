 /*

   ( Alternating Sign Sum Algorithm for 1 to n )

    You're given an integer n, and you want to compute the result of this pattern:

     −1+2−3+4−5+⋯±n

       That is:

      Odd numbers are negative

        Even numbers are positive

      Test case: 4

       −1+2−3+4=2


      Test case: 5

       −1+2−3+4−5=−3

        ✅ Mathematical logic:

           1. If n is even:

             ✅ Result = n / 2


           2. If n is odd:

        ✅ Result = -((n + 1) / 2)




         (  Algorithm :)

         */



       #include <bits/stdc++.h>   // Includes all standard C++ libraries

       using namespace std;

       // Fast input/output to speed up cin/cout

      #define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

        // Define shorthand for long long type

           #define ll long long

int main() {

    FastIO  // Enable fast input/output

    int n;

    cin >> n;     // Read an integer input from the user


    /*
      Goal: Calculate the alternating sign sum from 1 to n
      Pattern: -1 + 2 - 3 + 4 - 5 + ... ± n
      Logic:
        - If n is even: result = n / 2
        - If n is odd:  result = -((n + 1) / 2)
    */


    if (n % 2 == 0) {

        // Even case: result is simply n / 2

        cout << n / 2 << "\n";

    } else {

        // Odd case: result is negative of (n + 1) / 2

        cout << (n + 1) / 2 * -1 << "\n";

    }

    return 0; // End of program

}




