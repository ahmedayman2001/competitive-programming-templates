/** 

  ( Finds the minimum subarray length that contains duplicate elements.)


 ✅ Algorithm Description :

   Use a map mp to store the last occurrence index of each element.

Traverse the array from left to right.

For each element:

If it has appeared before:

Calculate the subarray length
length = current_index − previous_index + 1

Store this length.

Update the element’s last seen index.

Return the minimum recorded length.

If no duplicates exist, return -1.



     Test Case :


    n = 9
arr = [4 1 2 4 5 4 3 2 1]


Step-by-step:

i = 0: arr[0] = 4 → mp[4] = 0

i = 1: arr[1] = 1 → mp[1] = 1

i = 2: arr[2] = 2 → mp[2] = 2

i = 3: arr[3] = 4 → found duplicate (prev at 0), len = 3 - 0 + 1 = 4

i = 4: arr[4] = 5 → mp[5] = 4

i = 5: arr[5] = 4 → found duplicate (prev at 3), len = 5 - 3 + 1 = 3

i = 6: arr[6] = 3 → mp[3] = 6

i = 7: arr[7] = 2 → duplicate, prev at 2, len = 7 - 2 + 1 = 6

i = 8: arr[8] = 1 → duplicate, prev at 1, len = 8 - 1 + 1 = 8

✅ v = [4, 3, 6, 8] → min = 3

✅ Output: 3

    Test Case :

n = 4
arr = [3 3 3 3]

  Step-by-step:

i = 0: arr[0] = 3 → mp[3] = 0

i = 1: arr[1] = 3 → duplicate, prev at 0 → len = 2 → update mp[3] = 1

i = 2: arr[2] = 3 → duplicate, prev at 1 → len = 2 → update mp[3] = 2

i = 3: arr[3] = 3 → duplicate, prev at 2 → len = 2

✅ v = [2, 2, 2] → min = 2

✅ Output: 2


  ( Algorithm ) :

**/ 


   
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



int main() {

    FastIO

    int t;

    cin>>t;

    while (t--){

        int n;

        cin>>n;

        vector<int>vec(n);

        vector<int>vec1;

        map<int,int>mp;

        for (int i = 0; i < vec.size(); ++i) {

            cin>>vec[i];

        }

        for (int i = 0; i < n; ++i) {

            if ( mp.find (vec[i] ) == mp.end () ) {

                mp[vec[i]] = i;

            } else{

               vec1.push_back( i - mp[vec[i]] + 1 ) ; ////  Calculate the subarray length
                                                      //// length = current_index − previous_index + 1

                mp[vec[i]]=i;

            }

        }
        if (vec1.empty()){


            cout<<-1<<"\n";

        } else

        cout<<*min_element(vec1.begin(),vec1.end())<<"\n";

    }


return 0;

}


