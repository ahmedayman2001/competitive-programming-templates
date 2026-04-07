/**
     (  Frequency Map Algorithm )


   💡 Problem:
If you have a group of strings and want to know how many times each string was repeated, you can use a map for that.


✅ Input and Output:

Input	Output	Explanation

First	OK	First time to appear, so we print "OK" and add to map

First	First1	It's in the map → increment count → print string + count

Second	OK	First appearance → print OK

Second	Second1	Already exists → print Second1

Third	OK	First appearance → print OK

Third	Third1	Already exists → print Third1



     Algorithm :  

**/ 


#include <bits/stdc++.h>       // Includes all standard libraries
using namespace std;

int main() {
    int t;                     // Declare an integer to store the number of inputs

    cin >> t;                  // Read the number of strings to process

    map<string, int> mp;       // Declare a map to store each string and its frequency


    while (t--) {              // Loop t times (for each input string)

        string s;              // Declare a string to hold the current input

        cin >> s;              // Read the string from input

        if (mp[s] == 0) {      // If the string is not in the map yet (first occurrence)

            cout << "OK" << "\n";   // Print "OK"

            mp[s]++;                // Increment its frequency (now becomes 1)

        } else {

            // If the string already exists in the map

            cout << s << mp[s] << "\n";  // Print the string + its current count (e.g. First1)

            mp[s]++;                     // Increment the frequency for the next occurrence

        }
    }

    return 0;                  // End of the program
}
