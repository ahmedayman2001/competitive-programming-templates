/**

  (Algorithm to Verify Consecutive Alphabet Letters in a String) (Consecutive Alphabet Character Verification Algorithm ) :


    Algorithm Description :

     This algorithm checks whether the characters of a given string form a strictly consecutive sequence of lowercase alphabet letters.

     A string is considered consecutive if each character’s ASCII value is exactly one greater than the previous character, meaning the letters appear in continuous alphabetical order without repetition, gaps, or wrap-around.

    The algorithm iterates through the string from left to right and compares every pair of adjacent characters.
    If the difference between their ASCII values is exactly 1, the sequence remains valid.
    If any pair violates this condition, the algorithm immediately terminates and reports that the string is not consecutive.


     Examples :

    Valid Strings :


    "abc"      → a→b→c
    "lmno"     → l→m→n→o
    "xyz"      → x→y→z

  Invalid Strings :

   "abd"      → b→d (gap)

   "aabb"     → duplicates

   "ace"      → gaps

   "mnopqz"   → q→z (gap)

   "xyza"     → wrap-around not allowed




          Test Case (Input s) Explanation

"abc"	a→b→c (diff = 1)

"lmno"	l→m→n→o

"xyz"	x→y→z

"tuvwx"	All letters are consecutive


Test Case (Input s)	Explanation

"abd"	b→d (diff = 2)

"aabb"	a→a (diff = 0), a→b (1), b→b (0)

"ace"	a→c (diff = 2)

"mnopqz"	q→z (diff = 9)

"xyza"	a comes after z, not valid in sorted consecutive logic




  ( Algorithm ) :

  **/

   #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


  int main() {

    FastIO

      string s;
      cin >> s;

      bool isConsecutive = true;

      for (int i = 0; i < s.size() - 1; ++i) {
          if (s[i+1] - s[i] != 1) {
              isConsecutive = false;
              break;
          }
      }

      if (isConsecutive)

          cout << "Yes, all characters are consecutive." << endl;

      else

          cout << "No, characters are not consecutive." << endl;


      return 0;

  }


