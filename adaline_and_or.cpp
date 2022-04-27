#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class input{
public:
int x1, x2, y;
input(int x1, int x2, int y){
this->x1 = x1;
this->x2 = x2;
this->y = y;
}
};

class Adaline{

public:

void model(vector<input> inputs, float learningRate, int epochs, float w1, float w2,
float bias){
    
cout<<"Intial wts:\n";
cout<<"w1: "<<w1<<" , w2: "<<w2<<" , bias: "<<bias<<"\n";
int count=1;

while(epochs--){

cout<<"Epoch: "<<count++<<"\n";

for(int i=0; i<inputs.size(); i++){
// calculate yin
float yin = inputs[i].x1*w1 + inputs[i].x2*w2 + bias;
// update wts
w1 += learningRate*(inputs[i].y-yin)*inputs[i].x1;
w2 += learningRate*(inputs[i].y-yin)*inputs[i].x2;
bias += learningRate*(inputs[i].y-yin);
}
cout<<"w1: "<<w1<<" , w2: "<<w2<<" , bias: "<<bias<<"\n";
}
cout<<"Finished training";
}
};

int main(){
srand((unsigned)time(NULL));
// input
cout<<"Enter the no of epochs to run: ";
int epochs;
cin>>epochs;
cout<<"Enter input(bipolar) as 'x1 x2 y':\n";
vector<input> inputs;
int n=4;
for(int i=0; i<n; i++){
int x1, x2, y;
cin>>x1>>x2>>y;
inputs.push_back(input(x1, x2, y));
}
cout<<"Enter learning rate: ";
float learningRate;
cin>>learningRate;
cout<<"Enter initial values of w1, w2 & bias, if no value given, enter -1 for random values: ";
float w1, w2, bias;
cin>>w1>>w2>>bias;
(w1 == -1)?w1=(float)rand()/(2*RAND_MAX):w1; // if no values given, assign random values
(w2 == -1)?w2=(float)rand()/(2*RAND_MAX):w2;
(bias == -1)?bias=(float)rand()/(2*RAND_MAX):bias;
// func
Adaline model;
model.model(inputs, learningRate, epochs, w1, w2, bias);
return 0;
}
// AND-NOT i/p
// 2
// 1 1 -1
// 1 -1 1
// -1 1 -1
// -1 -1 -1
// 0.2
// 0.2 0.2 0.2