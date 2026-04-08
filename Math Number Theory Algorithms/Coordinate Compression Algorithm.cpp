/**
 
               ( Coordinate Compression Algorithm ) :



    📘 Algorithm Description

Coordinate Compression is a technique used to replace large or arbitrary values with smaller, consecutive integers while preserving their relative order.

It maps each unique value to its rank (0-based or 1-based) in the sorted list of distinct values.



 🧠 Why we use it

Coordinate Compression is useful when:

Values are large (e.g. up to 1e9)

Values are sparse

We want to use:

Arrays

Fenwick Tree

Segment Tree

DP with indexing

We need to reduce memory usage

We must preserve order, not exact values


   
  🧩 How the Algorithm Works (Step-by-Step)

1- Copy all values into a temporary container.

2- Sort the container.

3- Remove duplicates to keep only distinct values.

4- For each original value:

       Use lower_bound to find its position in the sorted unique list.

      Replace the value with that position (its compressed index).

      🧪 Example :

          Input :
            arr = {10, 50, 30, 50, 10, 30}
         
          Unique Sorted Values : 
           
            v = {10, 30, 50}

 
         Compressed Form : 
         arr = {0, 2, 1, 2, 0, 1}
          
        Decompression (Optional) :
         original_value = v[arr[i]]


   🧪 Example: Frequency Array : 🧪 Example: Frequency Array 


   v   = {10, 30, 50}
  arr = {0, 2, 1, 2, 0, 1}

    Build frequency array : 

    vector<int> freq(v.size(), 0);

  for (int i = 0; i < 6; i++) {
     freq[arr[i]]++;
   }
     


         ⚠️ Important Notes

freq.size() == v.size() ✔

Loop over arr.size() ✔

Compression must be done before counting ✔


         ( Algorithm ): 

**/

        #include <bits/stdc++.h>

  using namespace std;

  #define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

  #define ll long long
  #define el endl
 //#define MOD 1073741824

 // أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

  // const int N = 1e5+ 5    ;
  //const int mod = 1e9+7 ;
    //const ll mod = 1000000007LL;



  int main() {


      int arr [] = {10 , 50 , 30 , 50 , 10 , 30 } ;

      vector < int > v =  {10 , 50 , 30 , 50 , 10 , 30 } ;

      sort(v.begin() , v.end() ) ;

      v.erase(unique(v.begin() , v.end() ) , v.end() ) ;



      for (int i = 0; i < 6; ++i) {

          arr[i] = lower_bound(v.begin() , v.end() , arr[i] )-v.begin()  ;

      }

      for (auto it: arr ) {


          cout<<it <<" " ;

      } cout<<el ;

      for (auto it: arr ) {

          cout<<v[it]<<" " ; // Original Array //  

      }



    return 0 ;

}








       


    


  


        
