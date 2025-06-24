//Write a Program to implement Crypt Kicker II//
#include<bits/stdc++.h>
using namespace std;

string decrypt(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] = 65 + (s[i] - 65 + 5) % 26;
        } else if (s[i] >= 97 && s[i] <= 122) {
            s[i] = 97 + (s[i] - 97 + 5) % 26;
        }

    }
    return s;
}

int main() {
    int input;
    cin >> input;
    cin.ignore();

    for (int i = 0; i < input; i++) {
        vector<string> lines;
        string s;

        while (getline(cin, s)) {
            if (s.empty()) {
                break;
            }
            lines.push_back(decrypt(s));
        }


        for (auto line : lines) {
            cout << line << endl;
        }


        if (i < input - 1) {
            cout << endl;
        }
    }

    return 0;
}
