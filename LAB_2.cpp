//Minesweeper Problem//
#include<iostream>
#include <vector>
using namespace std;

vector<vector<char>> fun(vector<vector<char>> arr, int n, int m) {
    vector<vector<char>> ans = arr;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == '*') {
                continue;
            }

            int count = 0;

            if(i > 0 && arr[i-1][j] == '*') count++;
            if(i < n-1 && arr[i+1][j] == '*') count++;
            if(j > 0 && arr[i][j-1] == '*') count++;
            if(j < m-1 && arr[i][j+1] == '*') count++;
            if(i > 0 && j > 0 && arr[i-1][j-1] == '*') count++;
            if(i > 0 && j < m-1 && arr[i-1][j+1] == '*') count++;
            if(i < n-1 && j > 0 && arr[i+1][j-1] == '*') count++;
            if(i < n-1 && j < m-1 && arr[i+1][j+1] == '*') count++;

            ans[i][j] = static_cast<char>(count + '0');
        }
    }
    return ans;
}

int main(){
    int n, m;
    cout << "Enter the dimensions:" << endl;
    cin >> n >> m;

    cout << "Enter the Elements:" << endl;
    vector<vector<char>> arr(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<char>> result = fun(arr, n, m);

    cout << "Result:" << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
