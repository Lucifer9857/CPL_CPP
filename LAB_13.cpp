//Write a Program to implement the Combinatorics Pascal's Triangle of Death Problem//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<unsigned long long> dp(10001, ULLONG_MAX);


unsigned long long hanoi3(int n) {
if (n == 64) {

return ULLONG_MAX;
}
return (1ULL << n) - 1;
}


unsigned long long hanoi4(int n) {
if (n == 0) return 0ULL;
if (n == 1) return 1ULL;
if (dp[n] != ULLONG_MAX) return dp[n];

unsigned long long min_moves = ULLONG_MAX;

for (int k = 1; k < n; ++k) {
unsigned long long moves = 2 * hanoi4(k) + hanoi3(n - k);
if (moves < min_moves) {
min_moves = moves;
}
}

return dp[n] = min_moves;
}

int main() {
int n;
while (cin >> n) {
cout <<"Output:"<< hanoi4(n) << endl;
}
return 0;
}
