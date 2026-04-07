/**

(2D- Prefix Sum Algorithm )


test case : 

input:

4 5 
5 4 2 5 1
3 1 2 5 4
1 2 5 4 1
4 1 5 4 4

**************************************** (2D- Prefix Sum Algorithm ) ******************************************
5 9 11 16 17 
8 13 17 27 32 
9 16 25 39 45 
13 21 35 53 63 

2 2 3 4
**************************** (     to find Summation of any part of grid without Starting of the Grid .) *************************
19


Algorithm :

**/




#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



int main() {

    FastIO

    int n,m;
    cin>>n>>m;

    int a[n+1][m+1];

    for (int i = 1; i <=n ; ++i) {

        for (int j = 1; j <=m ; ++j) {

            cin>>a[i][j];

        }
    }
    cout<<"**************************************** (2D- Prefix Sum Algorithm ) ******************************************\n";

     int pref[n+1][m+1];

    memset(pref,0,sizeof pref);


    //first Row

    for (int i = 1; i <=m ; ++i) {

        pref[1][i] = pref[1][i-1] + a[1][i];

    }

    // first Column

    for (int i = 1; i <=n ; ++i) {

        pref[i][1] = pref[i-1][1] + a[i][1];

    }
    for (int i = 2; i <=n ; ++i) {

        for (int j = 2; j <=m ; ++j) {

            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j];

        }
    }

    for (int i = 1; i <=n ; ++i) {

        for (int j = 1; j <=m ; ++j) {


            cout<<pref[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<endl;


    cout<<"**************************** (     to find Summation of any part of grid without Starting of the Grid .) *************************\n";


    int i1,j1,i2,j2;

    cin>>i1>>j1>>i2>>j2;

    cout<< pref[i2][j2] - pref[i1-1][j2] - pref[i2][j1-1] + pref[i1-1][j1-1]<<"\n";


return 0;


}
