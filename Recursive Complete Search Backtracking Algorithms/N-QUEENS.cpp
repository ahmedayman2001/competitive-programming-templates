

 #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long
  #define el endl
#define ld long double
 //#define MOD 1073741824

 // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

  // const int N = 1e5+ 5    ;
  //const int mod = 1e9+7 ;
    //const ll mod = 1000000007LL;



    int n  ;
 char grid [10][10] ;

 vector <pair< int , int > > pos ;
 bool queen [10] ;
   void solve (int row ) {

       //// base case  ///
       if (row == n )
       {
           //// check if grid is valid ////

           bool valid = 1 ;

           for (int i = 0; i < pos.size() ; ++i) {

               for (int j = i+1; j < pos.size() ; ++j) {

                   int x = abs(pos[i].first - pos[j].first) ;
                   int y = abs (pos[i].second - pos[j].second );
                   if (x== y )  ////
                       valid = 0 ;
               }
           }
           if ( valid ) {


               for (int i = 0; i < n; ++i) {

                   for (int j = 0; j < n; ++j) {

                       cout<< grid[i][j] ;

                   }cout << el ;
               }
               cout << el ;

               return ;


           }

       }

       //// Transition ////
       for (int i = 0; i < n; ++i) {

           //// check column is valid or not ///
           if ( queen[i] )
               continue ;
           queen[i] = 1 ;
           grid[row][i] = 'Q' ;
           pos.push_back({row , i} ) ;
           solve(row+1) ;

           queen[i] = 0 ;
           grid[row][i] = '.' ;
           pos.pop_back() ;


       }

   }


 int main() {

        cin >> n ;

     for (int i = 0; i < n ; ++i) {
         for (int j = 0; j < n  ; ++j) {

             grid[i][j] = '.' ;
         }
     }

     solve(0) ;



      return 0 ;

}
 
/*
        bitset<31> b = 1 ;

     cout<<b<<"\SIZE";
      cout<<b[0]<<endl ;
      b[4] = 1 ;
    cout<<b<<"\SIZE";

    cout<<b.count()<<endl;
    cout<<b.size()<<"\SIZE" ;
      cout<<b.to_ullong() <<endl ;

*/




