#include<iostream>
#include<vector>
using namespace std;
class hopfield{
// hopfield is autoassociative net with no self loop, so calling autoassociative model to get wt matrix
vector<vector<int>> autoAssociative(vector<int> input){
vector<vector<int>> wt;
// final wt matrix will be of n*n
for(int i=0; i<input.size(); i++){
vector<int> tWt;
for(int j=0; j<input.size(); j++){
if(i == j){
tWt.push_back(0);
continue;
}
tWt.push_back(input[i]*input[j]);
}
wt.push_back(tWt);
}
return wt;
}
public:
void model(vector<int> input, vector<int> test){
vector<vector<int>> wt = autoAssociative(input); // creating wt matrix
cout<<"Weight Matrix:\n"; // print wt matrix
for(int i=0; i<wt.size(); i++){
for(int j=0; j<wt[0].size(); j++)
cout<<wt[i][j]<<" ";
cout<<"\n";
}
// testing
for(int i=0; i<test.size(); i++) // converting bipolar vector to binary
(test[i]<0)?test[i]=0:test[i];
vector<int> y(test); // setting y = x
for(int i=0; i<y.size(); i++){ // choosing Yi updating Y, 0<i<size
int prod=0;
for(int j=0; j<y.size(); j++) // Yi = Xi + Y*W_i, W_i: Ith column of wt matrix
prod += y[j]*wt[j][i];
y[i] = test[i] + prod;
(y[i]<0)?y[i]=0:y[i];
(y[i]>0)?y[i]=1:y[i];
}
cout<<"yin:\n"; // printing y vector
for(int i=0; i<y.size(); i++)
cout<<y[i]<<" ";
cout<<"\n";
for(int i=0; i<input.size(); i++) // converting bipolar vector to binary
(input[i]<0)?input[i]=0:input[i];
for(int i=0; i<y.size(); i++){ // checking if input = y, if yes then recognizes
if(input[i] != y[i]){
cout<<"Don't recognizes";
return;
}
}
cout<<"Recognizes";
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
hopfield model;
model.model(input, test);
return 0;
}

// 4
// 1 1 1 -1
//-1 -1 1 -1