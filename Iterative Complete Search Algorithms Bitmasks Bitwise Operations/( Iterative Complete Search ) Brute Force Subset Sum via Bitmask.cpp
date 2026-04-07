
/**



       ( Brute Force Subset Sum via Bitmask Iterative Complete Search )
 


   Iterates over all possible subsets of Array of size[ n ] elements using a bitmask:


  For each subset (each mask), you calculate the sum and check if it equals the target.

This is a classic approach to solving Subset Sum in small n (usually n ≤ 20), and it's called:


✅ Test Input:

n = 3  
target = 3  
arr = [1, 2, 3]


🧠 Total subsets = 2³ = 8

(Enumerated by mask from 0 to 7)

We’ll go through each mask, see which elements are selected, their sum, and whether it matches target = 3.


    🔍 Tracing Table:
mask (binary)	mask (decimal)	Selected Elements	Sum	Matches target?
  000	            0	                 ∅	         0	   ❌ No
  001	            1	                 [1]	         1	   ❌ No
  010	            2	                 [2]	         2	   ❌ No
  011	            3	                 [1, 2]	         3	  ✅ Yes ✅
  100	            4	                 [3]	         3	  ✅ Yes ✅
  101	            5	                 [1, 3]	         4	   ❌ No
  110	            6	                 [2, 3]	         5	   ❌ No
  111	            7	                 [1, 2, 3]                          6	   ❌ No

    
   ✅ Final Output:

There are 2 subsets with sum = 3:

[1, 2] → mask = 011

[3] → mask = 100

So, the output will be: 2

✅ How the mask works:

mask & (1 << i) checks whether bit i is set (meaning arr[i] is included).

We sum up those included elements.

If the sum equals the target, we count it.




 ( Algorithm : )

**/


#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

   int arr[100000] ;



int main() {

    FastIO

    int n , target;
    cin>> n >>target ;

    for (int i = 0; i < n; ++i) {

        cin>>arr[i] ;

    }

    int cnt = 0;

    for (int mask = 0; mask < ( 1 << n ); ++mask) {

        int sum = 0 ;

        for (int i = 0; i < n; ++i) {

            if (mask & (1<< i))  // 0 : 0 0 0   // 1 : 0 0 1 // 2: 0 1 0 // 3: 0 1 1

                sum+= arr[i] ;

        }

        if (sum == target )

            cnt++;

    }

    cout<<cnt<<"\n" ;

    return 0;

}




