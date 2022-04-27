#include<iostream>
#include<vector>
using namespace std;
class input{
public:
// data
int x1, x2, correctOutput, w1, w2, bias;
// constructor
input(int x1, int x2, int correctOutput){
this->x1 = x1;
this->x2 = x2;
this->correctOutput = correctOutput;
this->w1 = 0;
this->w2 = 0;
this->bias = 0;
}
};
class perceptron{
public:
void model(vector<input> inputs, int learningRate){
// loop till weights stop updating
bool isChanged;
int epochs=1;
do{
isChanged = false;
cout<<"Epoch: "<<epochs++<<"\n";
for(int i=0; i<4; i++){
// inherit wts from prev iteration
if(i!=0){
inputs[i].w1 = inputs[i-1].w1;
inputs[i].w2 = inputs[i-1].w2;
inputs[i].bias = inputs[i-1].bias;
}
// calculate output
int yin = inputs[i].x1*inputs[i].w1 + inputs[i].x2*inputs[i].w2 +
inputs[i].bias;
if(yin>0)

yin=1;
else if(yin<0)
yin=-1;
else
yin=0;
// update wts if y != t
if(yin != inputs[i].correctOutput){
isChanged = true;
inputs[i].w1 += learningRate*inputs[i].correctOutput*inputs[i].x1;
inputs[i].w2 += learningRate*inputs[i].correctOutput*inputs[i].x2;
inputs[i].bias += learningRate*inputs[i].correctOutput;
}
// if last row, carry wts to next epoch
if(i == 3){
inputs[0].w1 = inputs[i].w1;
inputs[0].w2 = inputs[i].w2;
inputs[0].bias = inputs[i].bias;
}
}
// printing wts after each epoch complete
cout<<"w1: "<<inputs[0].w1<<" , w2: "<<inputs[0].w2<<" , bias:
"<<inputs[0].bias<<"\n";
}
while(isChanged);
// return final wts
cout<<"Model training finished.";
}
};
int main(){
// input
vector<input> inputs;
cout<<"Enter I/P (Bipolar) as 'x1 x2 y':\n";
for(int i=0; i<4; i++){
int x1, x2, y;
cin>>x1>>x2>>y;
inputs.push_back(input(x1, x2, y));
}
int learningRate;
cin>>learningRate;
// func
perceptron p;
p.model(inputs, learningRate);

return 0;
}