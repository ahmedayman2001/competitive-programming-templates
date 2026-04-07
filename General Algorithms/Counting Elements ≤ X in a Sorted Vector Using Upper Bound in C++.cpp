/** 

   ( Counting Elements ≤ X in a Sorted Vector Using Upper Bound in C++ )


upper_bound(vec.begin(), vec.end(), 8)

Finds the first element greater than 8

In this vector, it returns an iterator to 9

So the index of 9 is 7, meaning all 7 elements before it are <= 8

Subtracting vec.begin() gives the count of elements ≤ 8



Algorithm :  

 **/

#include <bits/stdc++.h>

using namespace std;


int main() {

    vector<int> vec = { 2, 3, 4, 5, 6, 7, 8, 9, 10 } ;

    int x = 8;


    int count = upper_bound(vec.begin(), vec.end(), x ) - vec.begin();

    cout << "Count of elements <= " << x << " = " << count << "\n";


    return 0;
}
