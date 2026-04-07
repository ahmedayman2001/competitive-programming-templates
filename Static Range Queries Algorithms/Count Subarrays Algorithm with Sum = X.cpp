   
/**
 
  ( Count Subarrays Algorithm with Sum = X ) : 

    
       🧠 Description :


        Goal:
Count the number of contiguous subarrays whose sum is exactly x.

Idea:
Instead of checking all subarrays (which is O(n power 2 )), we use:
Prefix Sum to represent cumulative sums

Hash Map / Map to store how many times each prefix sum appeared

This allows us to solve the problem in linear time.

 🧩 How the Algorithm Works (Step-by-Step)

Build the prefix sum array p[]

Use a map m where:

key = prefix sum

value = how many times it appeared

Initialize:

m[0] = 1 implicitly by starting from i = 0

For each i from 0 to n:

Check how many times p[i] - x appeared

Add that count to the answer

Store p[i] in the map



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





int main() {

    /*
Algorithm Name:
Prefix Sum + Frequency Map (Counting Subarrays with Given Sum)

Description:
This algorithm counts the number of contiguous subarrays
whose sum equals a given value x using prefix sums and a map.

For each prefix sum p[i], we check how many times (p[i] - x)
appeared before. Each occurrence represents a valid subarray
ending at index i.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/




    ll n , x ;

    cin >> n >> x ;

    ll p[n+1] = { } ;

    for (int i = 1; i <= n  ; ++i) {

        cin >> p[i] ;

        p[i]+=p[i-1] ;

    }

    map<ll , ll > m ;

    ll ans = 0 ;

    for (int i = 0; i <= n ; ++i) {

        ll ser = p[i]-x ;

        ans+= m[ser] ;

        m[p[i]]++ ;

    }

    cout<<ans <<el ;


    return 0 ;

}







 



 

