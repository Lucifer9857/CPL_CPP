//Write a Program to implement the Steps combinatorics Problem//
#include <iostream>
#include <vector>

using namespace std;

vector<int> fun(int n) {
vector<int> ret;
ret.push_back(1);
long long res = 1;
for (int i = 1; i < n; i++) {
res = res * (n - i);
res = res / i;
ret.push_back(res);
}
return ret;
}

vector<vector<int>> generate(int numRows) {
vector<vector<int>> ans;
for (int i = 0; i < numRows; i++) {
ans.push_back(fun(i + 1));
}
return ans;
}

int main() {
int numRows;
cout << "Enter number of rows for Pascal's Triangle: ";
cin >> numRows;

vector<vector<int>> triangle = generate(numRows);

cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
for (auto row : triangle) {
for (int val : row) {
cout << val << " ";
}
cout << endl;
}

return 0;
}
