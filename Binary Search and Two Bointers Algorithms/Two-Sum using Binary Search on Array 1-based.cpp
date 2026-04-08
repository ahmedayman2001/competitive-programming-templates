
/**

Two-Sum using Binary Search on Array 1-based : searching for summation 2 elements in array == sum input

or
"Fixed element + Binary Search"

   //  **** Time Complexity = O(N LOG(N))  **** //

test case :

10
1 3 5 7 8 9 11 14 16 19
Found: 1 + 11 = 12
1 7     <<--<<-index




( Algorithm ):

**/



#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// **  Stay strong & keep solving! 💪👨‍💻  ** //


// ***   Algorithm Implementation [ 2 Pointers on Array 1-based : searching for summation 2 elements in array == sum input ]  ***** //

   //  **** Time Complexity = O(N LOG(N))  **** //

int main() {

    FastIO


    int n;
    cin>>n ;

    vector<int>vec(n+1);



    for (int i = 1; i <= n; ++i) {

        cin>>vec[i];
    }

    int sum = 12;

    for (int i = 1; i <= n-1; ++i) {

        int res =sum-vec[i];

        int l =i+1 , r = n ;

        while (l <= r) {

        int mid = l + (r - l) / 2 ;

            if (vec[mid] == res ){

            cout<<"Found: "<<vec[i]<< " + "<< vec[mid]<<" = "<<sum<<endl;

            cout<<i<<" "<<mid<<" "<<endl;

                return 0;

            } else if (vec[mid] < res ){


                l = mid + 1 ;

            }else {

                r = mid - 1 ;

            }
        }

        }

    cout << "No such pair found.\n";



    return 0;

}

