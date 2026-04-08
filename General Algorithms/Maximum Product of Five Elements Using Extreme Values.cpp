/**

     ( Maximum Product of Five Elements Using Extreme Values ):

   Description:

To compute the maximum product of five elements, this algorithm leverages the fact that the optimal product must consist only of the array’s smallest or largest values, since large absolute values dominate multiplication.

The array is first sorted, then all sign-relevant extreme combinations of five elements are evaluated. The maximum among these candidates is selected as the final answer.


A large product can result from:

Five large positive numbers

Three large positives × two large negatives

One large positive × four large negatives

Five small (negative) numbers (if no positive result exists)


Test Case : 


 Input:

[-10, -10, -5, 1, 2, 3, 4]
 
 4×3×2×1×(-5)   = -120
4×3×2×(-10)×(-10) = 2400 ✅

Output:

2400


 ( Algorithm ) : 

**/

  #include <bits/stdc++.h>
 
using namespace std;
 
#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);
 
#define ll long long
#define el endl
//#define MOD 1073741824
 
// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;
 
// const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;
 
 
 // const int N = 1e5+ 5    ;
// const int mod = 1e9+7 ;


  
int main() {
 
    FastIO       //   input.txt   output.txt
 
     //freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
 
      int t ;
      cin >> t ;
    while ( t-- ) {
 
        int n ;
        cin >> n ;
 
        vector< int > vec ( n ) ;
        vector< ll  > res ;
 
        for (int i = 0; i < n; ++i) {
 
            cin >> vec[i] ;
 
        }
 
        sort(vec.begin() , vec.end() ) ;
 
        res.push_back( 1LL *vec[n-1] * vec[n-2] * vec[n-3] * vec[ n-4 ] * vec[ n-5]) ;
 
 
        res.push_back(1LL * vec[n-1] * vec[n-2] * vec[n-3] * vec[ 0 ] * vec[ 1]) ;
 
        res.push_back( 1LL * vec[n-1] * vec[0] * vec[1] * vec[ 2] * vec[ 3 ]) ;
 
        res.push_back(1LL * vec[0] * vec[1] * vec[2] * vec[ 3 ] * vec[ 4 ]) ;
 
 
        ll ans = *max_element(res.begin() , res.end() ) ;
 
        cout << ans <<el ;
    }
 
 
    return 0  ;
 
}
 