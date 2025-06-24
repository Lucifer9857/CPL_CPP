//:  Write a Program to implement Shoemaker’s Problem//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
int id, time, fine;
};

bool compare(Job a, Job b) {
if ((long long)a.fine * b.time == (long long)b.fine * a.time)
return a.id < b.id;
return (long long)a.fine * b.time > (long long)b.fine * a.time;
}

int main() {
int t;
cout << "Enter number of test cases: ";
cin >> t;
while (t--) {
int n;
cout << "Enter number of jobs: ";
cin >> n;
vector<Job> jobs(n);
for (int i = 0; i < n; i++) {
cout << "Enter time and fine for job " << (i + 1) << ": ";
cin >> jobs[i].time >> jobs[i].fine;
jobs[i].id = i + 1;
}

cout << "Jobs before sorting:\n";
for (int i = 0; i < n; i++) {
cout << "Job " << jobs[i].id << ": time=" << jobs[i].time << ", fine=" << jobs[i].fine << endl;
}

sort(jobs.begin(), jobs.end(), compare);

cout << "Jobs after sorting (by optimal order):\n";
for (int i = 0; i < n; i++) {
cout << "Job " << jobs[i].id << ": time=" << jobs[i].time << ", fine=" << jobs[i].fine << endl;
}

for (int i = 0; i < n; i++) {
cout << jobs[i].id;
if (i != n - 1) cout << " ";
}
cout << endl;
if (t) cout << endl;
}
return 0;
}

