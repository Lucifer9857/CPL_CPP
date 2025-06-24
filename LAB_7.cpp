//Write a Program to implement the QWERTY Problem//
#include <bits/stdc++.h>
using namespace std;

int main() {
unordered_map<char, char> qwerty_map;

string row1 = "`1234567890-=";
string row2 = "QWERTYUIOP[]\\";
string row3 = "ASDFGHJKL;\'";
string row4 = "ZXCVBNM,./";


for (size_t i = 1; i < row1.length(); ++i)
qwerty_map[row1[i]] = row1[i - 1];
for (size_t i = 1; i < row2.length(); ++i)
qwerty_map[row2[i]] = row2[i - 1];
for (size_t i = 1; i < row3.length(); ++i)
qwerty_map[row3[i]] = row3[i - 1];
for (size_t i = 1; i < row4.length(); ++i)
qwerty_map[row4[i]] = row4[i - 1];


for (size_t i = 1; i < row2.length(); ++i)
qwerty_map[tolower(row2[i])] = tolower(row2[i - 1]);
for (size_t i = 1; i < row3.length(); ++i)
qwerty_map[tolower(row3[i])] = tolower(row3[i - 1]);
for (size_t i = 1; i < row4.length(); ++i)
qwerty_map[tolower(row4[i])] = tolower(row4[i - 1]);

string line;
while (getline(cin, line)) {
for (char ch : line) {
if (ch == ' ') {
cout << ' ';
} else if (qwerty_map.count(ch)) {
cout << qwerty_map[ch];
} else {
cout << ch;
}
}
cout << endl;
}

return 0;
}
