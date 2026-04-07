
/**
     ( Brute-Force Algorithm to Find Longest Repeated Substring )


    The algorithm finds the length of the longest substring that appears at least twice in the given string (i.e., the Longest Repeated Substring).


Given a string s, find the length of the longest substring that appears at least twice in s.

Test case :

banana


Substrings that repeat:

"a" (3 times)

"an" (2 times)

"na" (2 times)

Longest repeating substring: "ana" → Length = 3

Output:

3


✅ Step 1: Input


s = "ababa"
n = 5

✅ Step 2: Generate all substrings and count frequencies

We loop over all starting positions i from 0 to n-1, and for each i, we try all lengths j from 1 to n.

We only take substrings such that i + j <= n.


➤ i = 0:
j = 1 → "a" → mp["a"] = 1

j = 2 → "ab" → mp["ab"] = 1

j = 3 → "aba" → mp["aba"] = 1

j = 4 → "abab" → mp["abab"] = 1

j = 5 → "ababa" → mp["ababa"] = 1


➤ i = 1:
j = 1 → "b" → mp["b"] = 1

j = 2 → "ba" → mp["ba"] = 1

j = 3 → "bab" → mp["bab"] = 1

j = 4 → "baba" → mp["baba"] = 1

j = 5 → "baba" → skipped (out of bounds)


➤ i = 2:
j = 1 → "a" → mp["a"] = 2 ✅ ← now repeated

j = 2 → "ab" → mp["ab"] = 2 ✅

j = 3 → "aba" → mp["aba"] = 2 ✅

j = 4 → "aba" → skipped (out of bounds)


➤ i = 3:
j = 1 → "b" → mp["b"] = 2 ✅

j = 2 → "ba" → mp["ba"] = 2 ✅

j = 3 → "ba" → skipped

j = 4 → skipped


➤ i = 4:
j = 1 → "a" → mp["a"] = 3 ✅

j = 2 → "a" → skipped

j = 3 → skipped


✅ Final Frequency Map (mp):

Substring	Count

"a"	        3 ✅

"ab"	        2 ✅

"aba"	        2 ✅

"abab"	        1

"ababa"  	1

"b"	        2 ✅

"ba"	        2 ✅

"bab"	        1

"baba"	        1


✅ Step 3: Find the maximum length among substrings with count >= 2

We check each entry:

"a" → length = 1 ✅


"ab" → length = 2 ✅


"aba" → length = 3 ✅ (max so far)


"b" → length = 1


"ba" → length = 2


✅ So the longest repeated substring is "aba" with length = 3.



✅ Final Output:

3


   ( Algorithm ) :

   **/



  #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


  int main() {

    FastIO


    string s ,t;

      map<string,int>mp;

      cin>>s;

      int n =s.size();


      for (int i = 0; i < n;++i) {  //Start Position


          for (int j = 1; j <= n; ++j) {   // Take j Characters


              if (i+j<=n){

                  t=s.substr(i,j);   //  Store Substring in (t)


                  mp[t]++;  // Make Frequency Map on each Substring .


              }
          }
      }

          int ans =0;


      auto itr =mp.begin();


      while (itr!=mp.end()){


          t=itr->first;

          if (itr->second>=2) {


              ans = max(ans, (int) t.length());

          }

          itr++;

      }

      cout<<ans<<"\n";



      return 0;
  }



  // vector<vector<int>> a(5, vector<int>(5));
//vector<vector<int>>vc(5,vector<int>(5));


  // const int N=1000005;

