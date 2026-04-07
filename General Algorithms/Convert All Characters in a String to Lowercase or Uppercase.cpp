
/**

    (Convert All Characters in a String to Lowercase or Uppercase)


 test case :


input : s = "HeLLoWorLD"

output: "helloworld"

OR

test case :

input : s = "HeLLoWorLD"

output: "HELLOWORLD"



    (Algorithm ) :


 **/


    #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long

   // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


  int main() {

    FastIO


      string s;
      cin >> s;  // أدخل string فيه حروف كبيرة وصغيرة

     // transform(s.begin(), s.end(), s.begin(), ::toupper);

      // OR

     // transform(s.begin(), s.end(), s.begin(), ::tolower);

      // cout << "Uppercase: " << s << endl;

      // OR

    //  cout << "Lowercase: " << s << endl;



      return 0;

  }

