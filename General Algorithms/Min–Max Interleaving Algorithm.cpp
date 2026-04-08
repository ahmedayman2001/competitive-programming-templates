/**
   

           (  Min–Max Interleaving Algorithm  ) : 


   Description : 


This algorithm rearranges an array by alternately selecting the smallest and largest remaining elements, then reverses the final sequence to achieve the desired output order.


  Steps:

1- Sort the array in non-decreasing order.

2- Use two pointers:

    l → points to the smallest remaining element

    r → points to the largest remaining element

3- Iterate n times:

   If the index is even → take a[l], then increment l

   If the index is odd → take a[r], then decrement r

4- Reverse the constructed array.

5- Output the result.


🔹 What Pattern Does It Produce?
    

 Given:
  
 a = [1, 2, 3, 4, 5, 6]

   Intermediate (before reverse):

   [1, 6, 2, 5, 3, 4]


  Final output:

   [4, 3, 5, 2, 6, 1]
   
  ➡️ Elements oscillate between extremes, creating a balanced zigzag distribution.


   (  Algorithm ) :

**/

    
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;

  

 int main() {

     FastIO ;


     int t ;
     cin >> t ;
     while (t--) {

         int n ;
         cin  >> n ;

         vector<int> v(n) ;

         vector<int> ans ;

         for (int i = 0; i < n; ++i) {

             cin >> v[i] ;
         }

         sort(v.begin() , v.end() ) ;

         int l = 0 , r = n-1 ;

         for (int i = 0; i < n  ; ++i) {

             if (i%2 == 0 )

                 ans.push_back(v[l++]) ;

             else
                 ans.push_back(v[r--]) ;

         }

         reverse(ans.begin() , ans.end()) ;

         for (auto it: ans ) {

             cout << it <<" " ;

         }cout<<el ;


     }





    return 0 ;

}



     





  

   