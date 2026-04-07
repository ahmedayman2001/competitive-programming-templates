/**
 
        ( Fast Cyclic Sum Exceed Algorithm ) :


     Description:

An optimized algorithm to compute the minimum number of elements needed from an infinitely repeating array such that their running sum becomes strictly greater than a given value x.
It avoids slow simulation by computing full cycles using sumA, then processes only the remaining elements with a prefix scan.
Time complexity is O(n).
    


      ( Algorithm ) : 

**/

   #include <bits/stdc++.h>

using namespace std;


#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

#define ll long long

int main() {

    FastIO

    int n;

    ll x;

    cin >> n;

    vector<ll> a(n); // 0-based indexing is simpler


    ll sumA = 0;

    for (int i = 0; i < n; ++i) {

        cin >> a[i];

        sumA += a[i];

    }

    cin >> x ;

    // Count full cycles

    ll fullCycles = x / sumA;

    ll total = fullCycles * sumA;

    ll count = fullCycles * n;

    // Add elements one by one until total > x

    for (int i = 0; i < n; ++i) {
        total += a[i];

        count++;

        if (total > x) break;
    }

    cout << count << "\n";

    return 0;
}




   /*
 *
 * //   Time limit Exceed Solution //


   int n ;

    ll x;

      cin>>n;

    vector<int>vec1(n+1);

    for (int i = 1; i <= n; ++i) {

        cin>>vec1[i];
    }
    cin>>x;

    ll res =0;

    ll cnt =0;

int idx2 = 1;

    while (res<x) {

        res+=vec1[idx2];

        cnt++;

        idx2++;

        if (idx2>n)

            idx2=1;

    }

       cout<<cnt<<"\n";

 */

