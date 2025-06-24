//Write a Program to implement A multiplication Problem//
#include <iostream>
using namespace std;

int main() {
unsigned long long n;


while (cin >> n) {
unsigned long long low = 1, high = 1;
int turn = 0; // 0 = Stan, 1 = Ollie


while (high < n) {
low *= 2;
high *= 9;
turn = 1 - turn; // Switch player
}


if (turn == 1) // Stan just played
cout << "Stan wins." << endl;
else
cout << "Ollie wins." << endl;
}

return 0;
}
