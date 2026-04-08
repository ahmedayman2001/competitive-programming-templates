/**


                   ( **  Binary Search Algorithm Implementation Basic Concept  ** ) :


**/

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

   // **  Stay strong & keep solving! 💪👨‍💻  ** //

// May your dreams be bug-free and your code compile on the first try tomorrow! 😴💻 //


   // **  Binary Search Algorithm Implementation Basic Concept  **    //

   // **  Time Complexity = O(Log(n) **  //

int main() {

    FastIO

    int a[]={1,5,10,15,22,23,31,35} ;

    int x ;
     cin>>x;

    int l = 0 , mid , ans =-1;


    int n =sizeof(a[0]);   // 4 byte  //

    int sz = sizeof(a);   // 32 bytes //

    int r = (sz/n)-1 ;    // 32/4 = 8 // 8-1 = 7 last index in array //

    while (l <= r){      //   while (l <= r)   //  OR  //  while (true)   //


        mid = (l + r)/2 ;


        cout<<l<<" "<<" "<<mid<<" "<<r<<" "<<a[mid]<<   endl;


        if (a[mid] == x){


            ans = mid;

           break;

        } else if(a[mid] > x){

            r=mid-1;

        }

          else {

            l = mid+1 ;

        }

    }

    if (ans!=-1){


        cout<<"Element Found"<<" "<<"value = "<<a[ans]<<" "<<"index = "<<ans<<"\n";


    } else{


        cout<<"Element Not Found\n";

    }


    return 0;

} 

/**

intput:

x=10 

output :

0  3 7 15
0  1 2 5
2  2 2 10
Element Found value = 10 index = 2

**/



