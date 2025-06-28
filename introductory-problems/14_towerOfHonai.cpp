#include <iostream>
using namespace std;

void towerOfHonai(int n, int A, int C, int B){     // we have to move n disc from tower A to tower C using tower A
    if(n == 0) return ;
    // move upper n-1 disc from tower A to Tower B using tower C and then move last disc from tower A to tower C 
    towerOfHonai(n-1, A, B, C); 
    cout << A << " " << C << "\n";
    // now tower A is empty , tower B contain n - 1 disc while tower C contain last disc
    // Now we have to move n - 1 disc from tower B to tower C using tower A
    towerOfHonai(n-1, B, C, A);
}

int main(){
    int n;
    cin >> n;
    int minMoves = (1 << n) - 1;
    cout << minMoves << "\n";
    towerOfHonai(n, 1, 3, 2);
    return 0;
}