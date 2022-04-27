#include<iostream>
#include<vector>
using namespace std;

int main(){

int w1 = 1, w2 = 1;

vector<vector<int>> inp = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

cout << "weights (w1, w2): [1, 1]\n";
cout << "Threshold: 1\n";
cout << "Inputs yin output\n";

for (int i = 0; i < 4; i++){

int yin = w1 * inp[i][0] + w2 * inp[i][1];

int output = yin >= 1 ? 1 : 0;

cout<<inp[i][0]<< " "<<inp[i][1]<<" "<<yin<<" "<<output<<endl;

}
}