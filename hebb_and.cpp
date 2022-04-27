#include<iostream>
#include<vector>
using namespace std;
class input{
public:
/* data */
int x1, x2;
int correctOutput;
int bias, w1, w2;
input(int x1, int x2, int output){
this->x1 = x1;
this->x2 = x2;
this->correctOutput = output;
this->bias = 0;
this->w1 = 0;
this->w2 = 0;
}
};
void hebbs(vector<input> in){
int epoch=1;
// one epoch
for(int i=0; i<in.size(); i++){
cout<<"Input "<<i+1<<": \n";
// get wt from previous iteration
if(i!=0){
in[i].w1 = in[i-1].w1;
in[i].w2 = in[i-1].w2;
in[i].bias = in[i-1].bias;
}
cout<<"Previous Wts: \n";
cout<<"w1: "<<in[i].w1<<" || "<<"w2: "<<in[i].w2<<" || "<<"bias:
"<<in[i].bias<<"\n";
// calculate new weights
int newW1, newW2, newBias;
newW1 = in[i].w1 + in[i].x1 * in[i].correctOutput;
newW2 = in[i].w2 + in[i].x2 * in[i].correctOutput;
newBias = in[i].bias + in[i].correctOutput;
// update wts

in[i].w1 = newW1;
in[i].w2 = newW2;
in[i].bias = newBias;
cout<<"Updated Wts: \n";
cout<<"w1: "<<in[i].w1<<" || "<<"w2: "<<in[i].w2<<"
"<<in[i].bias<<"\n\n";
// if last iter, update wts of 1st input
if(i == in.size()-1){
in[0].w1 = in[i].w1;
in[0].w2 = in[i].w2;
in[0].bias = in[i].bias;
}
}
}
|| "<<"bias:
int main(){
vector<input> in;
int t;
cin>>t;
// construct input array
while(t--){
int tx1, tx2, tout;
cin>>tx1>>tx2>>tout;
input tin(tx1, tx2, tout);
in.push_back(tin);
}
hebbs(in);
return 0;
}