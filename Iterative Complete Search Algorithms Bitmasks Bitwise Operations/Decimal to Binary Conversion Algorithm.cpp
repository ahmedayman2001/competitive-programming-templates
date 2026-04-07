/**

                      ( Decimal to Binary Conversion Algorithm ) : 

 
      Description

This algorithm converts a non-negative decimal integer into its binary representation.

The process works by repeatedly dividing the given number by 2 and storing the remainder at each step. Each remainder represents a binary digit (bit). Since the remainders are generated from least significant bit to most significant bit, they are stored first and then reversed to obtain the correct binary order.


Key Steps

1- Read an integer n.

2- While n > 0:

 Store n % 2 (the remainder) in a vector.

Divide n by 2.

3- Reverse the vector to correct the bit order.

4- Output the binary digits.


         ( Algorithm ) :

**/



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


     int n ;
     cin >> n ;

     vector<bool>v ;

     while ( n > 0 ){

          v.push_back(n%2) ;

         n/= 2 ;

     }


     reverse(v.begin() , v.end() ) ;

     for (auto it : v ) {

         cout<< it << "" ;
     }

      return 0 ;

}
