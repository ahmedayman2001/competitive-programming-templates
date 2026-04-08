/**


( Backtracking Subset Sum Algorithm ) :

Subset Sum: some unique numbers and a target sum are given. You are asked to print all the subset that sum up to the target sum

arr = {1, 2, 3}

target = 5

Each step: TAKE element → sum + arr[i] , LEAVE element → sum stays

Full Recursion Tree 🌳

                     idx=0 (arr[0]=1, sum=0)
                   /                           \
         TAKE 1 (sum=1)                    LEAVE 1 (sum=0)
            /       \                           /       \
   TAKE 2 (sum=3)  LEAVE 2 (sum=1)     TAKE 2 (sum=2)  LEAVE 2 (sum=0)
     /     \         /     \              /     \          /      \
T3(6)    L3(3)   T3(4)   L3(1)      T3(5)✅   L3(2)     T3(3)    L3(0)



Algorithm :

/**


#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

  int n , x  , sum = 0 ;

  int arr[100] ;

  vector < int > path ; 

  void solve (int idx ){

     // base case

      if (sum >= x ) {

          if (sum == x ){

              for (int i = 0; i < path.size(); ++i) {


                  cout<<path[i] <<" ";

              }  cout<<endl ;

          }

          return ;

      }

      if ( idx == n )

          return ;

      // take

      sum+= arr[idx] ;

      path.push_back(arr[idx]) ;

      solve ( idx + 1  ) ;

      sum-= arr[idx] ;

      path.pop_back() ;

      // leave

      solve(idx + 1 )  ;

  }


int main() {

    FastIO

cin>> n >> x ;

    for (int i = 0; i < n; ++i) {

        cin>>arr[i] ;
    }

    solve(0) ;

    return 0;

}

