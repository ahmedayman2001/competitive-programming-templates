
/**
                   
                 ( Two-level Pair Sorting (Primary Descending, Secondary Ascending )

   
 
       Description:

This algorithm sorts a list of pairs (first, second) according to two criteria:

Primary Criterion (first element): Sort in descending order — pairs with larger first values appear first.

Secondary Criterion (second element): If the first elements are equal, sort in ascending order — pairs with smaller second values appear first.


    Input pairs: (3,10), (1,5), (3,20), (2,7)

      After sorting:

      (3,10)  // first = 3, second = 10
      (3,20)  // first = 3, second = 20
      (2,7)   // first = 2, second = 7
      (1,5)   // first = 1, second = 5

   
   note :  🔹 What a lambda function is : 


    [](const pair<int,int> &a, const pair<int,int> &b){

    if(a.first != b.first)

        return a.first > b.first;

    return a.second < b.second;

}
 
    This is a lambda function:
 
    It is an anonymous function (no name).

    It is used here as the comparator for sort().

    Its purpose is to tell sort() how to compare two elements.
 




     
  (  Algorithm  ) : 

**/



int main() {

    FastIO       //   input.txt   output.txt

     freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);

      int n , k ;

      cin >> n >> k ;

    vector< pair <int , int > > v ;


    for (int i = 0; i < n ; ++i) {

        int x , y ;

        cin >> x >> y ;

        v.push_back({x , y }) ;

    }

    sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b){	


        if(a.first != b.first)

            return a.first > b.first;    // first descending  (if first element in pair : a  != first element in pair : b :: sort pair based on first element )

        return a.second < b.second;      // second ascending  (if first element in pair : a  == first element in pair : b :: sort pair based on second element )


    });


  return 0 ; 

  } 