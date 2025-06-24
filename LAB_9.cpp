//Write a Program to implement the Longest Nap Problem//
#include<bits/stdc++.h>
using namespace std;

int toMinutes(int h, int m) {
return h * 60 + m;
}

void printNap(int start, int duration, int day) {
int h = start / 60;
int m = start % 60;
cout << "Day #" << day << ": the longest nap starts at ";
printf("%02d:%02d", h, m);

cout << " and will last for ";
if (duration >= 60)
cout << duration / 60 << " hours and " << duration % 60 << " minutes.\n";
else
cout << duration << " minutes.\n";
}

int main() {
int s, day = 1;
while (cin >> s) {
vector<pair<int, int>> appts;
for (int i = 0; i < s; ++i) {
int sh, sm, eh, em;
char colon;
cin >> sh >> colon >> sm >> eh >> colon >> em;
int start = toMinutes(sh, sm);
int end = toMinutes(eh, em);
appts.push_back({start, end});
cin.ignore(1000, '\n'); // Skip the rest of the line (description)
}


appts.push_back({600, 600});
appts.push_back({1080, 1080});

sort(appts.begin(), appts.end());

int maxNap = 0, napStart = 0;
for (int i = 1; i < appts.size(); ++i) {
int gap = appts[i].first - appts[i - 1].second;
if (gap > maxNap) {
maxNap = gap;
napStart = appts[i - 1].second;
}
}

printNap(napStart, maxNap, day++);
}
return 0;
}
