/**

           ( Balanced Parentheses Checking Algorithm ) :


    ✅ Algorithm Description :

  This algorithm determines whether a given string contains a valid and well-balanced sequence of brackets.
It supports multiple bracket types—specifically round () and square [] brackets—and verifies that:

Every opening bracket has a corresponding closing bracket

Brackets are properly nested

Closing brackets appear in the correct order

The algorithm processes the string from left to right using a stack to track unmatched opening brackets.


  🔹 Algorithm Steps :


   Initialize an empty stack to store opening brackets.

Traverse the input string character by character:

If the character is an opening bracket (( or [), push it onto the stack.

If it is a closing bracket:

Check whether the stack is non-empty

Check whether the top of the stack matches the closing bracket type

If yes, pop the stack.

Otherwise, mark the sequence as invalid.

After scanning the entire string:

If the stack is empty and no mismatch was found → the string is balanced.

Otherwise → the string is not balanced.

Output "Yes" for valid sequences and "No" for invalid ones.


  ✅ Test Cases :

  | Input String | Output |
| ------------ | ------ |
| `([])`       | Yes    |
| `([)]`       | No     |
| `(([]))`     | Yes    |
| `[`          | No     |





    ( Algorithm ) :

    **/


#include <bits/stdc++.h>
using namespace std;

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


int main() {
int t;
cin>>t;
cin.ignore();

while(t--) {


string s;

    getline(cin,s);

   // cin>>s;

    stack<char>s1;

bool flag = true;


    for (int i = 0; i < s.length(); ++i) {


        if (s[i]=='(' || s[i]=='['){

            s1.push(s[i]);


        } else if ( !s1.empty() && s[i]==')' && s1.top()=='(' ) {

            s1.pop();


        } else if ( !s1.empty()  && s[i] ==']' &&  s1.top()== '['  ) {

            s1.pop();


        } else {

            flag = false;
            break;

        }

    }

    if (flag && s1.empty()){


        cout<<"Yes"<<"\n";


    }else{

        cout<<"No"<<"\n";
    }



}

    return 0;
}

