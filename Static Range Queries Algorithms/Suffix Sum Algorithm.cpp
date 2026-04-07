/**


 ( Suffix Sum Algorithm )

Summation from last element of the array to any index of the array 

test case :

  6
1 2 3 4 5 6
21 20 18 15 11 6 


Algorithm :

**/

   

#include <bits/stdc++.h>
using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



int main() {

    FastIO


    // Suffix Sum Algorithm

    int n;

    cin>>n;

    int a[n+2];

    for (int i = 1; i <=n ; ++i) {

        cin>>a[i];
    }
        int suff[n+2];

    suff[n+1]=0;

    for (int i = n; i >=1 ; --i) {

        suff[i]=suff[i+1]+a[i];
    }

    for (int i = 1; i <=n ; ++i) {

        cout<<suff[i]<<" ";

    }


return 0;

}


