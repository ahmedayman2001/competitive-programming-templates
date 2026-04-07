

/**

  
               Maximum Subarray Sum using Prefix Minimum (Kadane’s Algorithm) : 



         📘 Description :

         This algorithm computes the maximum possible sum of any contiguous subarray in a sequence of integers using a prefix sum technique combined with tracking the minimum prefix value.

At each step, the algorithm maintains:

The current prefix sum

The minimum prefix sum encountered so far

The maximum subarray sum found so far

The maximum subarray ending at the current index is obtained by subtracting the minimum prefix sum from the current prefix sum. The global maximum is updated accordingly.

  
🧠 Core Idea (Mathematical Insight) :


  Let:

prefix[i] = sum of elements from index 1 to i

The sum of a subarray (l + 1 … r) is:

 prefix[r] − prefix[l]
To maximize this value for a fixed r, the algorithm always subtracts the smallest prefix sum seen before r.

      
      🧩 Algorithm Steps

1- Initialize :

    sum = 0 (current prefix sum)

    mn = 0 (minimum prefix sum)

   ans = −∞ (maximum subarray sum)


2- For each element in the array :

        Update the prefix sum

       Compute sum − mn as the best subarray ending at the current position

        Update the global maximum

       Update the minimum prefix sum


3- Output the maximum subarray sum.



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

      ll n ;

      cin >> n ;

      ll sum = 0 , ans = LLONG_MIN , mn = 0 ;

      for (int i = 1 ; i <= n  ; ++i) {

          ll a ; cin >> a ;

          sum+= a ;  //// current Prefix Sum : prefix[r]  ////

          ans = max( ans , sum-mn ) ; //// max Sub Array ////

           mn = min(mn , sum ) ;  //// Minimum prefix[l-1] ////

      }

      cout << ans <<el ;



    return 0 ;

}












