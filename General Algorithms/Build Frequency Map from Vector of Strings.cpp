
/**
     ( Build Frequency Map from Vector of Strings )

    🧠 What It Does:
Takes t strings as input and stores them in a vector.

Traverses the vector backward (from end to start).

Prints each unique string only once, keeping the last occurrence first.

Uses a map<string, bool> to keep track of what's already printed.


Test case Input:

6
apple

banana

apple

orange

banana

grape


 Output :

grape

orange

apple

banana

These are the last unique occurrences, printed in reverse input order.


     Algorithm :
**/



    #include <bits/stdc++.h>              // Includes all standard C++ libraries

using namespace std;


#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr); // Fast input/output

#define ll long long                  // Alias for long long data type


// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// "To be alive is not enough, you must have sunlight, freedom, or a small flower inside your heart."


int main() {

    FastIO // Enable fast input/output

    int t;

    cin >> t; // Read number of strings

    vector<string> vec(t); // Vector to store input strings

    map<string, bool> mp;  // Map to track which strings have already been printed (seen)


    // Read t strings from input

    for (int i = 0; i < t; ++i) {

        cin >> vec[i];

    }

    // Traverse the vector from the last element to the first

    // This helps us capture the **last occurrence** of each unique string

    for (int i = t - 1; i >= 0 ; --i ) {


        // If the string hasn't been seen/printed before

        if (mp[vec[i]] == 0) {

            cout << vec[i] << "\n";   // Print the string


            mp[vec[i]] = 1 ;           // Mark the string as seen

        }
    }

    return 0; // End of program
}



