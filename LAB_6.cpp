//Write a Program to implement Automated Judge Script//
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
string extractNumber(vector<string>& lines) {
string digits;
for (string line : lines) {
for (char c : line) {
if (isdigit(c)) {
digits += c;
}
}
}
return digits;
}
int main() {
int runnumber = 1;
while(true){
int n;
cin>>n;
cin.ignore();
if(n==0){
break;
}
vector<string> correct(n);
for(int i = 0;i<n;i++){
getline(cin,correct[i]);
}
int m;
cin>>m;
cin.ignore();
vector<string> tocheck(m);
for(int i = 0;i<m;i++){
getline(cin,tocheck[i]);
}
if(correct == tocheck){
cout << "Run #" << runnumber << ": Accepted" << endl;
}
else{
string judgeextractednumber = extractNumber(correct);
string correctextractednumber = extractNumber(tocheck);
if(judgeextractednumber == correctextractednumber){
cout << "Run #" << runnumber << ": Presentation Error" << endl;
}
else{
cout << "Run #" << runnumber << ": Wrong Answer" << endl;
}
}
runnumber++;
}
return 0;
}
