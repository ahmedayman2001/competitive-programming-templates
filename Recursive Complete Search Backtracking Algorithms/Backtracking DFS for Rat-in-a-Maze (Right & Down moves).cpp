/**
    
     Backtracking DFS for Rat-in-a-Maze (Right & Down moves)  : 



    Rat in a maze: a 2D maze is given where R is the position of a rat, C is the position of a piece of cheese, # is a wall, and . is an empty cell. What is the different paths by which the rat can get to the piece of cheese if it can moves down (D) and right (R) on the empty cells.


Reads an n × m grid with:

'R' = starting point

'C' = destination

'#' = blocked cells

'.' = free cells

Uses recursive backtracking to find all possible paths from R to C, moving only Right (R) or Down (D).



       Example Maze (3×3)

       R . .
      . # .
      . . C
  
Coordinates:

Start R = (0,0)

Cheese C = (2,2)

Allowed moves: Right R, Down D.


solve(0,0) path=""
│
├─ Right → solve(0,1) path="R"
│   │
│   ├─ Right → solve(0,2) path="RR"
│   │    │
│   │    └─ Down → solve(1,2) path="RRD"
│   │          │
│   │          └─ Down → solve(2,2) path="RRDD" ✅ PRINT "RRDD"
│   │
│   └─ Down → (1,1) wall ❌
│
└─ Down → solve(1,0) path="D"
    │
    ├─ Right → (1,1) wall ❌
    │
    └─ Down → solve(2,0) path="DD"
         │
         └─ Right → solve(2,1) path="DDR"
              │
              └─ Right → solve(2,2) path="DDRR" ✅ PRINT "DDRR"





How pop_back() works in the tree

Let’s zoom on "RRDD":

Start: ""

Push 'R' → "R"

Push 'R' → "RR"

Push 'D' → "RRD"

Push 'D' → "RRDD" → reached cheese → print.

Now return:

Pop 'D' → "RRD"

Pop 'D' → "RR"

Pop 'R' → "R"

Pop 'R' → ""

Now the Down branch of the root can be explored ("DDRR").


Output Order
RRDD
DDRR


( Algorithm ) :

**/


#include <bits/stdc++.h>   // Includes all standard C++ libraries

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


char arr[10][10];              // Grid to represent the maze or map

pair<int , int> r , c;         // Positions: r = start (R), c = destination (C)

string path = "";              // Stores the path taken as a sequence of moves

int n , m;                     // Dimensions of the grid

// Check if a cell (i, j) is valid to move into

bool valid(int i, int j) {

    return (i < n && j < m && arr[i][j] != '#'); 

    // Valid if inside the grid AND not a wall ('#')
}

// Recursive backtracking function to explore all paths

void solve(int i , int j) {

    // Base case: if we reached the destination (C)

    if (i == c.first && j == c.second) {

        cout << path << endl;   // Print the current path

        return;                 // Stop exploring this branch
    }

    // ----------- Transition (explore neighbors) ------------

    // Move Right → (i, j+1)

    if (valid(i, j+1)) {

        path.push_back('R');        // Add move to path

        solve(i, j+1);              // Recurse from new position

        path.pop_back();            // Backtrack (remove last move)
    }

    // Move Down ↓ (i+1, j)

    if (valid(i+1, j)) {

        path.push_back('D');        // Add move to path

        solve(i+1, j);              // Recurse from new position

        path.pop_back();            // Backtrack (remove last move)
    }
}

// ---------------- Main Function ----------------

int main() {

    FastIO   // Fast input/output

    cin >> n >> m;   // Read grid dimensions

    // Read the grid and find positions of R (start) and C (end)

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {

            cin >> arr[i][j];

            if (arr[i][j] == 'R')

                r = {i, j};     // Save start position

            else if (arr[i][j] == 'C')

                c = {i, j};     // Save destination position

        }
    }


    // Start DFS/backtracking search from 'R'

    solve(r.first, r.second);


    return 0;
}
