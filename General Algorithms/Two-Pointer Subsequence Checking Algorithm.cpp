/*

      (Algorithm to Check if Array B is a Subsequence of Array A)



     Algorithm Description :

      This algorithm determines whether array B is a subsequence of array A.

     A subsequence is formed by deleting zero or more elements from array A without changing the relative order of the remaining elements.



         Algorithm Steps :

   Initialize a pointer j = 0 to track position in array B.

   Iterate through array A with index i from 0 to N-1:

   If A[i] == B[j], move j to the next element in B (j++).

   After the loop, if j == M (length of B), then B is a subsequence of A.

   Otherwise, it is not.



      Example :

   A = [1, 3, 5, 7, 9]
   B = [3, 7, 9]


    ( Algorithm ) :

   */

 #include <bits/stdc++.h>
  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;




  int main() {

    FastIO

      int N , M ;
      cin>>N>>M;

      int A[N] , B[M] ;

      for (int i = 0; i < N; ++i) {

          cin>>A[i];

      }


           for (int i = 0; i < M; ++i) {

           cin>>B[i];
        }
           int j =0 ;

        for (int i = 0; i < N; ++i) {

          if (j<M && A[i]==B[j])

              j++;

      }

         if (j==M){

          cout<<"YES\n";


      }   else {

          cout<<"NO\n";
      }


             return 0;

  }

