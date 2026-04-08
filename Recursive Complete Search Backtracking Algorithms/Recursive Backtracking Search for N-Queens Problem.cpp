/**


  ( Recursive Backtracking Search for N-Queens Problem )

  N Queens: you are given an integer N and you are asked to find all different possible ways where queens can be placed on a NxN chessboard so that none attack each other.

       (   https://youtu.be/61jdLiffzRg?si=e2y7xPHHJ5Ga1kSA   )

input: 4

Output :

.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

solve(0)
 ├── place (0,0)
 │     ├── place (1,1) ❌ diagonal conflict later
 │     ├── place (1,2)
 │     │      ├── place (2,0) ❌ diagonal with (1,2)
 │     │      ├── place (2,1) ❌ col conflict
 │     │      ├── place (2,2) ❌ col conflict
 │     │      └── place (2,3)
 │     │              ├── place (3,0) ❌ diagonal conflict
 │     │              ├── place (3,1) → ✅ Solution #1
 │     │              ├── place (3,2) ❌ col conflict
 │     │              └── place (3,3) ❌ col conflict
 │     └── place (1,3)
 │            ├── place (2,0)
 │            │      ├── place (3,1) ❌ diagonal
 │            │      ├── place (3,2) → ✅ Solution #2
 │            │      └── place (3,3) ❌ col
 │            ├── place (2,1) ❌ diagonal
 │            ├── place (2,2) ❌ col
 │            └── place (2,3) ❌ col
 │
 ├── place (0,1)
 │     ├── place (1,0) ❌ diagonal conflict
 │     ├── place (1,2) ❌ diagonal conflict
 │     └── place (1,3)
 │            ├── place (2,0) ❌ diagonal
 │            ├── place (2,2) ❌ diagonal
 │            └── place (2,3) ❌ col
 │     (no valid solutions from this branch)
 │
 ├── place (0,2)
 │     ├── place (1,0)
 │     │      ├── place (2,1) ❌ diagonal
 │     │      ├── place (2,3)
 │     │             ├── place (3,0) ❌ col
 │     │             ├── place (3,1) ❌ diagonal
 │     │             └── place (3,2) ❌ col
 │     ├── place (1,1) ❌ diagonal
 │     ├── place (1,2) ❌ col
 │     └── place (1,3) ❌ diagonal
 │     (no valid solutions from this branch)
 │
 └── place (0,3)
       ├── place (1,0)
       │      ├── place (2,1) ❌ col
       │      ├── place (2,2) ❌ diagonal
       │      └── place (2,3) ❌ col
       ├── place (1,1)
       │      ├── place (2,0) ❌ diagonal
       │      ├── place (2,2) ❌ col
       │      └── place (2,3) ❌ diagonal
       └── place (1,2) ❌ diagonal
       (no valid solutions)

Step 1:

 grid[i][j] = '.' → empty cell.

If we put a queen: grid[row][i] = 'Q'.

queen[i] → column i is already used by a queen.

pos → stores (row, col) of all queens placed so far.

Base case: when row == n, check diagonals and print solution.

So recursion = try placing queen in every column of each row.

Step 2: Example with n = 4
We must place 4 queens on a 4×4 board.
Let’s trace:

Call solve(0) → Row = 0

Try columns one by one: i = 0, 1, 2, 3

Choice 1: Place Q at (0,0)

Grid:

Q . . .
. . . .
. . . .
. . . .


(Backtracking for N-Queens) :

1- We place queens row by row.

In each row, we try every column and check if we can place a queen there.

2- We use queen[i] to make sure no two queens are in the same column.

3- Diagonal check is done only when all queens are placed (row == n)
(you could also optimize by checking diagonals while placing, but here it’s checked at the end).

4- Backtracking steps:

Place a queen → Recurse → Undo placement → Try next position.

5- When all n queens are placed successfully, the board is printed.



( Algorithm ) :

**/



#include <bits/stdc++.h> // includes all standard libraries

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr); // Fast input/output

#define ll long long

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;


int n; // size of the chessboard (n x n)

char grid[10][10]; // the chessboard grid, storing '.' (empty) or 'Q' (queen)

vector<pair<int, int>> pos; // stores positions of queens placed so far: (row, col)

bool queen[10]; // marks which columns are already occupied by a queen

// Recursive backtracking function to place queens row by row

void solve(int row) {

    // base case: if we placed queens in all rows

    if (row == n) {

        // check if the configuration is valid (no diagonal conflicts)

        bool valid = 1;

        for (int i = 0; i < pos.size(); ++i) {

            for (int j = i + 1; j < pos.size(); ++j) {

                int x = abs(pos[i].first - pos[j].first);   // row difference

                int y = abs(pos[i].second - pos[j].second); // column difference

                if (x == y) // if same diagonal

                    valid = 0;
            }
        }

        // if configuration is valid, print the board

        if (valid) {

            for (int i = 0; i < n; ++i) {

                for (int j = 0; j < n; ++j) {

                    cout << grid[i][j];

                }

                cout << endl;
            }

            cout << endl; // blank line between solutions
        }
    }

    // recursive step: try placing a queen in this row

    for (int i = 0; i < n; ++i) {

        // if column already has a queen, skip

        if (queen[i])

            continue;

        // choose: place queen at (row, i)

        queen[i] = 1;             // mark column as used

        grid[row][i] = 'Q';       // place queen on board

        pos.push_back({row, i});  // save position

        // explore: go to next row

        solve(row + 1);

        // undo (backtrack): remove queen and restore state

        queen[i] = 0;    
   
        grid[row][i] = '.';   
   
        pos.pop_back();        
    }
}

int main() {

    FastIO

    cin >> n; // input board size

    // initialize grid with '.'

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            grid[i][j] = '.';
        }
    }

    // start solving from the first row

    solve(0);

    return 0;
}
