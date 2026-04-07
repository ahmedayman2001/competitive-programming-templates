/**


   Greedy Maximal Lexicographic Compression (MaxD Greedy Algorithm) :



   Description

A greedy algorithm that constructs a binary string a such that, after element-wise addition with a given binary string b and removal of consecutive equal digits, the resulting sequence d is lexicographically maximal.



You are given a binary string b.

You construct a (also binary) such that:

c[i] = a[i] + b[i]

Then d is formed by removing consecutive equal digits from c

You want d to be as large as possible (lexicographically).

Greedy MaxD Algorithm =

A greedy algorithm to construct a binary string a that maximizes the final compressed sequence d formed from a + b.

Input:

1
n = 6
s = "110011"


| i | s[i] | Try a[i] = 1 |  c[i]=1+b[i]    | prev | Accept?| a[i] | new prev |
| - | ----- | ----------- | ------------- | ---- | ------- | -----  | -------- |
| 0 | 1     | 1+1 = 2     | 2             | -1   | ✅       | 1     | 2        |
| 1 | 1     | 1+1 = 2     | 2             | 2    | ❌       | 0     | 1        |
| 2 | 0     | 1+0 = 1     | 1             | 1    | ❌       | 0     | 0        |
| 3 | 0     | 1+0 = 1     | 1             | 0    | ✅       | 1     | 1        |
| 4 | 1     | 1+1 = 2     | 2             | 1    | ✅       | 1     | 2        |
| 5 | 1     | 1+1 = 2     | 2             | 2    | ❌       | 0     | 1        |


Output: 100110 ✅


   Algorithm :  

**/


   int t;

cin >> t;

while (t--) {

    int n;

    cin >> n;

    string s;  // this is b

    cin >> s;

    vector<int> vec(n);  // this will store the result a[i]

    int prev = -1;       // previous c[i-1] value


    for (int i = 0; i < n; ++i) {

        int bi = s[i] - '0';  // convert '0' or '1' to int (0 or 1)


        if ( 1 + bi != prev ) {

            vec[i] = 1;       // pick a[i] = 1

            prev = 1 + bi;

        } else {

            vec[i] = 0;       // fallback to a[i] = 0

            prev = 0 + bi;
        }
    }

    for (int i = 0; i < n; ++i) {

        cout << vec[i];  // print result a as binary string

    }
    cout << "\n";
}

   

