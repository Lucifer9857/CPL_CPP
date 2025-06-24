//Write a Program to implement Reverse and Add Problem//
#include <bits/stdc++.h>
using namespace std;


int fun(int num){
        int prev=num;
    int i =0;

    while(true){

        string rev = to_string(prev);
        reverse(rev.begin(),rev.end());

        if(stoi(rev) == prev){
            cout<<"It took "<<i<<" iterations for the answer"<<endl;
            cout<<"Answer: "<<prev<<endl;
            break;

        }
        else{
            int a= stoi(rev);
            prev = prev + a;
     }
     i++;
    }
}





int main(){

int n;
cout<<"Enter N numbers: ";
cin>>n;

vector<int> arr;
while(n){
    int num;
    cout<<"Enter the Number: ";
    cin>>num;
    arr.push_back(num);
    n--;
}

for(int i = 0;i<arr.size();i++){
    fun(arr[i]);
}

return 0;
}
