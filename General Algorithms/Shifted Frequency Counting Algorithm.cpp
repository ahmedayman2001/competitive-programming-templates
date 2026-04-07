/** 


 ( Shifted Frequency Counting Algorithm )


  int a[]={-4,1,-4,-2,2,10,5,4};

    🔢 Step 1: Input Array

 a = [-4, 1, -4, -2, 2, 10, 5, 4]


 🔎 Step 2: Find Minimum Element

  int minElement = *min_element(a, a+8); // minElement = -4


Then shift it:

minElement = abs(minElement); // minElement = 4


🔁 Step 3: Shift All Elements by +4

for (int i = 0; i < 8; ++i) {

    a[i] += minElement; // a[i] += 4
}

 Resulting array becomes:

 a = [0, 5, 0, 2, 6, 14, 9, 8]

(Original values shifted by +4 so the minimum becomes 0.)


🔍 Step 4: Find Maximum Value in Shifted Array


int mxm = *max_element(a, a+8); // mxm = 14



🧮 Step 5: Frequency Array Initialization


int frq[mxm+1]; // frq[15]

memset(frq, 0, sizeof frq); // initialize all to 0


🔢 Step 6: Count Frequency

for (int i = 0; i < 8; ++i) {
    frq[a[i]]++;
}
Breakdown:

a[0] = 0 → frq[0]++

a[1] = 5 → frq[5]++

a[2] = 0 → frq[0]++

a[3] = 2 → frq[2]++

a[4] = 6 → frq[6]++

a[5] = 14 → frq[14]++

a[6] = 9 → frq[9]++

a[7] = 8 → frq[8]++

Final frequency array (frq):


Index : frq[index]
   0  : 2      ← corresponds to -4 (original value appeared 2 times)
   1  : 0
   2  : 1      ← -2 appeared once
   3  : 0
   4  : 0
   5  : 1      ← 1 appeared once
   6  : 1      ← 2 appeared once
   7  : 0
   8  : 1      ← 4 appeared once
   9  : 1      ← 5 appeared once
  10  : 0
  11  : 0
  12  : 0
  13  : 0
  14  : 1      ← 10 appeared once



📤 Step 7: Output with Reverse Shift (–4)

for (int i = 0; i <= mxm; ++i) {

    cout << i - minElement << " " << frq[i] << "\n";
}

-4 2
-3 0
-2 1
-1 0
 0 0
 1 1
 2 1
 3 0
 4 1
 5 1
 6 0
 7 0
 8 0
 9 0
10 1


   ✅ Final Output (Matches Frequencies of Original Array):
Value	Frequency
-4	2
-2	1
1	1
2	1
4	1
5	1
10	1

 

    Algorithm :

**/

   

#include <bits/stdc++.h>
using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;



int main() {

    FastIO

    int a[]={-4,1,-4,-2,2,10,5,4};

    // Shifting elements to be in 0:n-1 //

    int minElement =*min_element(a,a+8);

    minElement= abs(minElement);

    for (int i = 0; i < 8; ++i) {

        a[i]+=minElement;
    }

    int mxm =*max_element(a,a+8);

    int frq[mxm+1];

    memset(frq,0, sizeof frq);

    for (int i = 0; i <8 ; ++i) {

        frq[a[i]]++;
    }


    for (int i = 0; i <=mxm; ++i) {


        cout<<i-minElement<<" "<<frq[i]<<"\n";
    }


return 0;

}






