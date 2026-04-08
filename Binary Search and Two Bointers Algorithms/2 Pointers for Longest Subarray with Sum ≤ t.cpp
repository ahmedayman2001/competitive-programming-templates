/**

( Sliding Window for Longest Subarray with Sum ≤ t ) :
  


Input:

n = 4, t = 5
vec = [3, 1, 2, 1]


Initial State:

s = 0        // current window sum

ans = 0      // best window length found

j = 0        // window start index



Step-by-step tracing :


i = 0 (element = 3)

s + vec[i] = 0 + 3 = 3 <= 5 → OK

s = 3

ans = max(0, 0 - 0 + 1) = 1 ✅

Window = [3] → sum = 3, ans = 1




i = 2 (element = 2)
s + vec[i] = 4 + 2 = 6 > 5 → Too big, go to else

Add anyway first: s = 6

While s > 5:

s -= vec[j] → s = 6 - 3 = 3

j = 1

Now s = 3 (OK)

ans = max(2, 2 - 1 + 1) = 2 ✅

Window = [1, 2] → sum = 3, ans = 2




i = 3 (element = 1)
s + vec[i] = 3 + 1 = 4 <= 5 → OK

s = 4

ans = max(2, 3 - 1 + 1) = 3 ✅

Window = [1, 2, 1] → sum = 4, ans = 3


Final Output:
ans = 3

✅ Meaning the longest subarray with sum ≤ 5 is of length 3 (example: [1, 2, 1]).



( Algorithm ) :

**/



#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// **  Stay strong & keep solving! 💪👨‍💻  ** //


         int main() {

          FastIO


          int n , t ;

          cin>>n>>t;

             vector<int>vec(n);

             for (int i = 0; i < n; ++i) {

                 cin>>vec[i] ;
             }

             int s = 0 , ans = 0 ;


             for (int i = 0 , j = 0; i < n ; ++i) {

                 // i end ;

                 // j start

                 if (s + vec[i] <= t){

                     s+=vec[i];

                 }

                 else

                 {
                     s+=vec[i];

                     while (s > t ){


                         s-=vec[j];

                         j++;

                     }

                 }

                 ans = max(ans , i-j+1 );


             }

             cout<<ans<<endl;



    return 0;

}

// ******************************************************************************************************************************************************** //


     #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long
  #define el endl
#define ld long double
 //#define MOD 1073741824

 // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

  // const int N = 1e5+ 5    ;
  //const int mod = 1e9+7 ;
    //const ll mod = 1000000007LL;




 int main() {


     int n , t ;

     cin >> n >> t ;

     vector< int > v ( n ) ;

     for (int i = 0; i < n ; ++i) {

         cin >> v[i] ;
     }


     ll sum = 0  , mx = 0  , l = 0 ;

     for (int r = 0; r < n; ++r) {

         sum += v[r] ;


         while (sum > t) {

             sum -= v[l];
             l++;

         }

         mx = max( r-l+1 , mx ) ;

     }



     cout << mx << el ;

      return 0 ;

}







