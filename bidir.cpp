#include<iostream>
#include<vector>
using namespace std;
class BAM{
// BAM is heteroassociative net with two layer working bidirectionally
vector<vector<int>> heteroassociative(vector<vector<int>> input, vector<vector<int>>
target){
int rowIn=input.size(), colIn=input[0].size(), rowTar=target.size(),
colTar=target[0].size();
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
return wt;
}
public:
void model(vector<vector<int>> input, vector<vector<int>> target, vector<int>
testXY, vector<int> testYX){
// TEST-1
// test model for layer X -> layer Y
vector<vector<int>> wt = heteroassociative(input, target);
// print wt matrix
cout<<"=================================\n";
cout<<"Weight Matrix for X->Y:\n";
for(int i=0; i<wt.size(); i++){
for(int j=0; j<wt[0].size(); j++)
cout<<wt[i][j]<<" ";
cout<<"\n";

}
cout<<"Test 1: X->Y :: [";
for(int i=0; i<testXY.size(); i++)
cout<<testXY[i]<<" ";
cout<<"]\nTest result: ";
vector<int> result;
for(int j=0; j<wt[0].size(); j++){
int temp=0;
for(int i=0; i<testXY.size(); i++){
temp += testXY[i]*wt[i][j];
}
if(temp > 0)
temp=1;
else if(temp < 0)
temp=-1;
result.push_back(temp);
cout<<temp<<" ";
}
//======================================================================
// TEST-2
// test model for layer Y -> layer X
// wt matrix for Y->X is transpose of wt matrix
vector<vector<int>> wtT;
for(int j=0; j<wt[0].size(); j++){
vector<int> tWt;
for(int i=0; i<wt.size(); i++){
tWt.push_back(wt[i][j]);
}
wtT.push_back(tWt);
}
// print wt matrix
cout<<"\n=================================\n";
cout<<"Weight Matrix for Y->X:\n";
for(int i=0; i<wtT.size(); i++){
for(int j=0; j<wtT[0].size(); j++)
cout<<wtT[i][j]<<" ";
cout<<"\n";
}
cout<<"Test 2: Y->X :: [";
for(int i=0; i<testYX.size(); i++)
cout<<testYX[i]<<" ";
cout<<"]\nTest result: ";
result.clear();

for(int j=0; j<wtT[0].size(); j++){
int temp=0;
for(int i=0; i<testYX.size(); i++){
temp += testYX[i]*wtT[i][j];
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
cout<<"Enter test vectors:\n";
vector<int> testXY;
for(int i=0; i<colIn; i++){

    int t; cin>>t;
testXY.push_back(t);
}
vector<int> testYX;
for(int i=0; i<colTar; i++){
int t; cin>>t;
testYX.push_back(t);
}
// func
BAM model;
model.model(input, target, testXY, testYX);
return 0;
}
/*
Que: BAM to recognize E & F
E: target(-1, 1) F: target(1, 1)
* * * * * *
* . . * * *
* * * * . .
* . . * . .
* * * * . .
'*' : 1,
'.' : -1
=====INPUT=====:
2 15
1 1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 1
1 1 1 1 1 1 1 -1 -1 1 -1 -1 1 -1 -1
2 2
-1 1
1 1
1 1 1 1 -1 -1 1 1 1 1 -1 -1 1 1 1
1 1
*/