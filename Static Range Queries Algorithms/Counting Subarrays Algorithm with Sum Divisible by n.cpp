/**


     ( Counting Subarrays Algorithm with Sum Divisible by n ) :



   🔹Description

Given an integer array of size n, this algorithm efficiently counts the number of subarrays whose sum is divisible by n.


   🔹 Core Idea

The algorithm is based on the mathematical observation that:

If two prefix sums have the same remainder modulo n, then the subarray between them has a sum divisible by n.


  Formally:

   (prefix[R] − prefix[L-1]) % n == 0
   ⇔( prefix[R] % n - prefix[L-1] % n) % n == 0 
   Prefix[R] = Prefix[L-1] 


   🔹 Algorithm Explanation

1- Build Prefix Sum Modulo Array

Compute cumulative sums.

Store each prefix sum modulo n.

2- Use a Frequency Map

Track how many times each modulo value appears.

Every time the same modulo appears again, it forms valid subarrays.

3- Count Valid Subarrays

For each prefix value p:

Add the current frequency of p to the answer.

Increment its frequency.



       (  Algorithm ) :

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


  ll fix ( ll x , ll mod ){

      return  ( (x % mod) + mod ) % mod  ;

  }




int main() {


      int n ;
      cin >> n ;
      int prefix [n+1] = { } ;

    for (int i = 1; i <= n  ; ++i) {

        cin >> prefix[i] ;

        prefix[i]+= prefix[i-1] 
;
        //prefix[i]= fix( prefix[i] , n ) ;

        prefix[i] = prefix[i] %  n ;
    }

    map<ll , ll >m ;

    ll ans = 0 ;

    for (int i = 0; i <= n ; ++i) {


        ans+= m[prefix[i]] ;

        m[prefix[i]]++ ;

    }

    cout <<ans <<el ;




    return 0 ;

}

     






















 


