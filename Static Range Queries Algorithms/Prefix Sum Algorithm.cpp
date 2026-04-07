/**


( Prefix Sum Algorithm )

summation of elements from starting of array to any index of array .

6  
1 2 3 4 5 6
1 3 6 10 15 21 


(note:)

if you want to summations of elements from any index(L) to another index (R) in array , summation not start from the first element.
example : summation of elements from index:3 to index:5

( pref[R] - pref[L-1];)
 the result = pref[5]- pref[3-1]; == 15 - 3 =12 Done = (3+4+5)=12




   Algorithm :

**/

  

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



int main() {

    FastIO


    // Prefix Sum Algorithm

    int n;

    cin>>n;

    int a[n+1];

    for (int i = 1; i <=n ; ++i) {


        cin>>a[i];
    }
        int pref[n+1];


    pref[0]=0;


    for (int i = 1; i <=n ; ++i) {

        pref[i]=pref[i-1]+a[i];
    }

    for (int i = 1; i <=n ; ++i) {

        cout<<pref[i]<<" ";
    }

return 0;
}

