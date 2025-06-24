//Sales by Match Problem//
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter color of socks: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> colorCount;
    int cnt = 0;
    int unp = 0;

    for (auto i : arr)
        colorCount[i]++;

    cout << "Pairs for each color:" << endl;
    for (auto i : colorCount) {
        if (i.second % 2 != 0) {
            unp++;
        }
        int pairs = i.second / 2;
        cnt += pairs;
        cout << "Color " << i.first << " has " << pairs << " pairs." << endl;
    }

    cout << "Total number of pairs: " << cnt << endl;
    cout << "Number of unpaired socks: " << unp << endl;

    return 0;
}
