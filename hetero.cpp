#include<iostream>
#include<vector>
using namespace std;
class heteroAssociative{
public:
void model(vector<vector<int>> input, vector<vector<int>> target, vector<int> test,
int rowIn, int colIn, int rowTar, int colTar){
// training model, i.e finding wt matrix
vector<vector<int>> wt;
for(int i=0; i<colIn; i++){
vector<int> twt;
for(int j=0; j<colTar; j++){
int t=0;
for(int k=0; k<rowIn; k++){
t = t + input[k][i]*target[k][j];
}
twt.push_back(t);
}
wt.push_back(twt);
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
for(int j=0; j<wt[0].size(); j++){
int temp=0;
for(int i=0; i<test.size(); i++){
temp += test[i]*wt[i][j];
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
cout<<"Enter no of rows & columns of i/p vector: ";
int rowIn, colIn;
cin>>rowIn>>colIn;
cout<<"Enter i/p matrix:\n";
vector<vector<int>> input;
for(int i=0; i<rowIn; i++){
vector<int> tin;
for(int j=0; j<colIn; j++){
int t; cin>>t;
tin.push_back(t);
}
input.push_back(tin);
}
cout<<"Enter no of rows & columns of target vector: ";
int rowTar, colTar; cin>>rowTar>>colTar;
cout<<"Enter target matrix:\n";
vector<vector<int>> target;
for(int i=0; i<rowTar; i++){
vector<int> ttar;
for(int j=0; j<colTar; j++){
int t; cin>>t;
ttar.push_back(t);
}
target.push_back(ttar);
}
cout<<"Enter test matrix:\n";
vector<int> test;
for(int i=0; i<colIn; i++){
int t; cin>>t;
test.push_back(t);
}
// func
heteroAssociative model;
model.model(input, target, test, rowIn, colIn, rowTar, colTar);

return 0;
}