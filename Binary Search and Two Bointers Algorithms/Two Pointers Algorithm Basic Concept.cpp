/**

    ( Two Pointers Algorithm Basic Concept )  // Searching for 2 elements summation = x ??!

    
    Algorithm :

**/


     

#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// **  Stay strong & keep solving! 💪👨‍💻  ** //


// ***   "Two-Sum using Binary Search" on Array 0-based  ***** //
   //  **** Time Complexity = O(N LOG(N))  **** //

int main() {

    FastIO

    int a[]={1,5,10,15,21,23,30};

  int ans =0;
    int sum = 100 ;
    int p1 = 0;
    int p2 = 6 ;
    while (p1 < p2 ){

        if (a[p1] + a[p2] == sum){

            ans = 1;
            break;

        } else if (a[p1] + a[p2] < sum){

            p1++;

        } else{

            p2--;
        }

    }
    if (ans){

        cout<<"found at indexes :"<<p1<<"  "<<p2<<endl;

    } else{


        cout<<"Sorry not Found"<<endl;
    }




    return 0;

}

        ***********************************************************************************************************************************************************************


    Another way :

    Test case :

n = 6
arr = 5 5 5 2 8 0

target = 10

Sorted: 0 2 5 5 5 8

Pair: 2 + 8 = 10 or 5 + 5 = 10.



  ( Algorithm :)



  #include <bits/stdc++.h>

using namespace std;


#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);


#define ll long long


int main() {

    FastIO

    int n;

    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; ++i) {

        cin >> p[i];
    }

    sort(p, p + n);

    int *p1 = &p[0];       // pointer to first element

    int *p2 = &p[n - 1];   // pointer to last element

    int target;

    cin >> target;

    while (p1 < p2) {

        int sum = *p1 + *p2; // sum of the values pointed to

        if (sum == target) {

            cout << *p1 << " + " << *p2 << " = " << target << "\n";

            break;

        } else if (sum < target) {

            p1++; // move forward

        } else {

            p2--; // move backward

        }
    }

    delete[] p; // free memory


    return 0;

}







