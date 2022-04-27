#include<iostream>
#include<vector>
using namespace std;
class autoAssociative{
public:
void model(vector<int> input, vector<int> test){
vector<vector<int>> wt;
// final wt matrix will be of n*n
for(int i=0; i<input.size(); i++){
vector<int> tWt;
for(int j=0; j<input.size(); j++){
tWt.push_back(input[i]*input[j]);
}
wt.push_back(tWt);
}
// print wt matrix
cout<<"Weight Matrix:\n";
for(int i=0; i<wt.size(); i++){
for(int j=0; j<wt[0].size(); j++)
cout<<wt[i][j]<<" ";
cout<<"\n";
}
// test the model
cout<<"Test result: ";
vector<int> result;
for(int i=0; i<test.size(); i++){
int temp=0;
for(int j=0; j<test.size(); j++){
temp += test[j]*wt[j][i];
}
if(temp > 0)
temp=1;
else if(temp < 0)
temp=-1;
result.push_back(temp);
cout<<temp<<" ";
}
}
};
int main(){
// INPUT
cout<<"Enter size of input vector: ";
int n;
cin>>n;
cout<<"Enter the i/p vector: ";
vector<int> input;
for(int i=0; i<n; i++){
int tin;
cin>>tin;
input.push_back(tin);
}
cout<<"Enter the test vector: ";
vector<int> test;
for(int i=0; i<n; i++){
int ttest; cin>>ttest;
test.push_back(ttest);
}
// func
autoAssociative model;
model.model(input, test);
return 0;
}
// 4
// 1 1 1 -1
// 1 0 1 -1