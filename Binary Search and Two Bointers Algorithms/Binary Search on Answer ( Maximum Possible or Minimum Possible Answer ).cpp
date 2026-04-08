/**


Binary Search or Answer ( Maximum Possible or Minimum Possible Answer ) :


🏢 Problem Description: Tower and Egg
You are given a building with n floors, numbered from 1 to n.

You want to find out the highest floor from which you can drop an egg without it breaking.

👇 At each floor:
If you drop the egg and it does not break, it's safe → you can try a higher floor.

If the egg breaks, the floor is not safe → try a lower floor.

You can ask the user (or simulate) whether the egg breaks or not at a given floor.

🔍 Why Binary Search?
Binary Search helps you find the answer faster by always checking the middle floor between current low and high limits. It reduces the number of checks from n to log₂(n) steps.

.

📌 Input/Output Summary:
Input:
n → total number of floors
For each floor, user inputs 1 (safe) or 0 (breaks)

Output:
The highest safe floor

Test case :

Enter number of floors:
10
Number of All Floors = 10
Now you have floors between 1 to 10 In every Floor choose Yes or No (1 or 0) to get Highest Safe Floor in the Final Result.
Current Floor is = 5
1
Current Floor is = 8
1
Current Floor is = 9
0
The safer Highest Floor is: = 8





(Algorithm) :

**/


#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// **  Stay strong & keep solving! 💪👨‍💻  ** //

// Problem (Tower and egg) //

// Binary Search or Answer ( Maximum Possible or Minimum Possible Answer ) //


int main() {

    FastIO

    int n;

    cout << "Enter number of floors: "<<endl;

    cin>>n;

    cout<<"Number of All Floors = "<<n<<endl;


    cout<<"Now you have floors between 1 to "<<n<<" In every Floor choose Yes or No (1 or 0) to get Highest Safe Floor in the Final Result."<<endl;

    int l =1 ;

    int r = n ;

    int ans = 0;

    while (l <= r){


       int mid = (l + r )/2;

        cout<<"Current Floor is = "<< mid<<endl;

        int check;

        cin>>check;

        if (check==1){

            ans = mid;

            l = mid +1;


        } else{


            r = mid -1 ;

        }

    }

        if (ans !=0)

        cout<<"The safer Highest Floor is: = "<< ans<<endl;

else

    cout<<"Sorry No Safer Floor"<<endl;



    return 0;

}


