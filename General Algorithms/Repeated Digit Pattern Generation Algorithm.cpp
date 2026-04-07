/** 
   
       ( Repeated Digit Pattern Generation Algorithm ) :

   
      🔹Description :
  
       The algorithm generates all numbers whose digits are identical by iterating over digits from 1 to 9 and repeatedly appending the same digit to form numbers such as d, dd, ddd, etc. These numbers are stored in a vector and sorted.

Since the total number of such values is constant (81), each query is answered efficiently by counting how many generated values are less than or equal to the given input n.

// Generates all numbers with identical digits and counts how many are ≤ n


    🔹 Output :

       1 2 3 4 5 6 7 8 9

11 22 33 44 55 66 77 88 99

111 222 333 444 555 666 777 888 999

1111 2222 3333 4444 5555 6666 7777 8888 9999
...



     🔹( Algorithm ):

**/

       
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;




int main() {

     FastIO ;

    vector<ll> v ;

    for (int d = 1; d <= 9 ; ++d) {

        ll x = 0 ;
        for (int l  = 1; l  <= 9  ; ++l ) {

            x = x*10+d ;

            v.push_back(x) ;
        }
    }

    sort(v.begin() , v.end() ) ;

    int t ;
    cin >> t ;
    while (t-- ) {


        int n ;
        cin >> n ;
        int cnt = 0 ;
        for (int i = 0; i < v.size(); ++i) {

            if (v[i] <= n)
                cnt++;
            else
            break;
        }

        cout<<cnt << el ;

    }


    return 0 ;

}


