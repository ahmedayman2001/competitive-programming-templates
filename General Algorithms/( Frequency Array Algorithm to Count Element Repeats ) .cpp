
/*


     ( "Frequency Array Algorithm to Count Element Repeats" ) :

   GOAL:

      Count how many times each number appears in an array using a single loop.


      STEPS:

    1- Create a frequency array
        We call it farr[].

       The size should be as big as the largest number in the input array.

        Set all its values to 0 at the beginning.

       Example: max number = 6

farr =   [0, 0, 0, 0, 0, 0, 0]
          0  1  2  3  4  5  6   ← index



       2- Original array:

      arr =       [2, 3, 4, 3, 6, 4, 1]
      Indexes:     0  1  2  3  4  5  6     ← index




    3- Loop over each element in arr[]:


    4 -After loop, farr[] will become:

     farr =   [0, 1, 1, 2, 2, 0, 1]
               0  1  2  3  4  5  6    ← index



         Means:

      1 appears once.

      2 appears once.

      3 appears twice.

      4 appears twice.

      6 appears once.



     ( Algorithm ):
*/



     #include <bits/stdc++.h>

     using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long


   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



    int main() {

    FastIO


  for (int i = 0; i < 7; ++i) {

          cin>>arr[i];    //arr = [2, 3, 4, 3, 6, 4, 1]

               //        Indexes:  0  1  2  3  4  5  6

      }

      for (int i = 0; i < 7; ++i) {

          farr[arr[i]]++;
      }

      for (int i = 0; i < 7; ++i) {

          cout<<farr[i]<<" ";
      }


             return 0;

  }




