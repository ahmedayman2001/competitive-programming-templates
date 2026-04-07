/*
    ( Array of Strings Algorithm ) :

    Days of the Week Example :



 ( Algorithm )  :

 */


 #include <bits/stdc++.h>
  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


  int main() {

    FastIO

        // Array of strings Algorithm

        const int Days = 7;  // Number of Strings must constant integer


        const int MAX = 10;  // Maximum Size of each String must constant integer


        char star[Days][MAX] = {"Saturday" ,"sunday" ,"Monday" , "Tuesday" , "wednesday" , "Thursday" , "Friday" } ;


                    for (int i = 0; i < Days; ++i) {

                       cout<<star[i]<<" ";

                      }


               return 0;

  }


