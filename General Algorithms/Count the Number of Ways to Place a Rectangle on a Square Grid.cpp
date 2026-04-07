
/** 
    (Count the Number of Ways to Place a Rectangle on a Square Grid)


You have:

A square grid of size N × N

A rectangle of size H × W

You want to place the rectangle anywhere in the grid so that it fully fits inside and covers exactly H rows × W columns


To fit the rectangle inside the grid, its top-left corner must be placed in a position where it can extend H rows down and W columns right without exceeding the grid bounds.

So the top-left corner of the rectangle can be placed at:

Rows: 0 to N - H

Columns: 0 to N - W


That gives:

(N - H + 1) positions vertically
×
(N - W + 1) positions horizontally

✅ Final Answer:

(5−2+1)×(5−3+1)=4×3=12 ways


✅ Small Test Case:

Grid size: N = 3

Rectangle size: H = 2, W = 2


✅ Calculation:

Vertical positions (rows): 0 to N - H → 0 to 1 → 2 rows


Horizontal positions (columns): 0 to N - W → 0 to 1 → 2 columns

✅ Total ways = 2 × 2 = 4


ll 4 Placements (2×2 Rectangle in 3×3 Grid):

🟥 = Rectangle

. = Empty grid cell


🔹 Placement 1: Top-left at (0, 0):


🟥🟥 .
🟥🟥 .
. . .


🔹 Placement 2: Top-left at (0, 1):


. 🟥🟥
. 🟥🟥
. . .


🔹 Placement 3: Top-left at (1, 0):


. . .
🟥🟥 .
🟥🟥 .


🔹 Placement 4: Top-left at (1, 1):

. . .
. 🟥🟥
. 🟥🟥


✅ Final Answer for this test case: 4 ways






Algorithm : 


**/


  #include <iostream>

using namespace std;

int main() {

    int N, H, W;

    cin >> N >> H >> W;


    int ways = (N - H + 1) * (N - W + 1);

    cout << ways << "\n";


    return 0;
}


