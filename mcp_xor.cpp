#include<iostream>
#include<vector>
using namespace std;

int main(){

cout << "Since XOR is not linearly separable, we have to use two ANDNOT's and one OR
MCP.\n";

vector<vector<int>> input = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

cout << "Weights :: 1st ANDNOT : [1, -1]\n";

cout << "Weights :: 2nd ANDNOT : [-1, 1]\n";
int wt1 = 1, wt2 = 1;
cout << "weights :: OR : [1, 1]\n";
cout << "Threshold (for all three): 1\n";
cout << "Inputs ANDNOT_1 ANDNOT_2 yin output\n";
for(int i = 0; i < 4; i++){
int a = input[i][0] - input[i][1];
a = a >= 1 ? 1 : 0;
int b = input[i][1] - input[i][0];
b = b >= 1 ? 1 : 0;
int yin = wt1 * a + wt2 * b;
int output = yin >= 1 ? 1 : 0;
cout<<input[i][0]<<" "<<input[i][1]<<" "<<a<<" "<<b<<"
"<<yin<<" "<<output<<"\n";
}
}