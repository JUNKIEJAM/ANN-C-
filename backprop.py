import numpy as np
import random
import math
class BPN:
V = []
W = []
V0 = []
W0 = []
Zin = []
Z = []
Yin = []
Y = []
DelK = []
DelW = []
DelW0 = []
DelinJ = []
DelV = []
DelV0 = []
DelJ = []
alpha = random.random() # the learning rate
def init (self, n, p, m):
self.n = n
self.p = p
self.m = m
# initialising the weights and biases
self.V = self.DelV = np.array([ [ random.random() for _ in range(self.p)] for _
in range(self.n) ])
self.W = self.DelW = np.array([ [ random.random() for _ in range(self.m)] for _
in range(self.p) ])
self.V0 = self.DelV0 = np.array([ random.random() for _ in range(self.p) ])
self.W0 = self.DelW0 = np.array([ random.random() for _ in range(self.m) ])
def sigmoid(self,x):
if type(x) is np.ndarray:
return 1.0/(1.0 + np.exp(-x))
else:
return 1.0/(1.0 + math.exp(-x))
def f(self, x):

return self.sigmoid(x)
def f_dash(self, x):
return self.f(x)*(1 - self.f(x) )
def feed_forward(self, X):
print( "---Feed Forward Phase---")
## This is the feed forward function, refer to the writeup above for more
information
print ("Weights(Input -> Hidden: ")
print (self.V)
print ("bias: ")
print (self.V0)
print ("Weights(Hidden -> Output): ")
print (self.W)
print ("bias: ")
print (self.W0)
for j in range(self.p):
zinj = self.V0[j]
for i in range(self.n):
zinj+=X[i]*self.V[i][j]
(self.Zin).append(zinj)
## Now, we'll calculate Zj = f(Zinj)
print ("Inputs(Hidden Layer): ")
print (self.Zin)
self.Z = self.f(np.array(self.Zin))
print ("Outputs(Hidden Layer): ")
print (self.Z)
for k in range(self.m):
yink = self.W0[k]
for j in range(self.p):
yink+=self.Z[j]*self.W[j][k]
(self.Yin).append(yink)
print ("Net Input(Output Layer): ")
print (self.Yin)
self.Y = self.f(np.array(self.Yin))
print ("Net Output(Output Layer): ")
print (self.Y)
print ("---End Feed Forward Phase---")
def backpropagate(self, targets, X):
## Now, we'll begin with the backpropagation phase
print ("---Back Propagation Phase---")
## Errors with each output layer neuron
for k in range(self.m):
delk = (targets[k] - self.Y[k])*self.f_dash(self.Yin[k])
self.DelK.append(delk)
print ("Output Errors for each Output Neuron: ")
print (self.DelK)
# Now we'll calculate the errors associated with the weights in Hidden and
Output Layer
for j in range(self.p):
for k in range(self.m):
self.DelW[j][k] = self.alpha*self.DelK[k]*self.Z[j]
# For Biases
for k in range(self.m):
self.DelW0[k] = self.alpha*self.DelK[k]
print ("Changes in weights (Hidden -> Output): ")
print (self.DelW)
print ("Change in bias: ")
print (self.DelW0)
## Now,we'll calculate the backward error for each Hidden Layer Neuron
for j in range(self.p):
delj = sum( [ self.DelK[k]*self.W[j][k] for k in range(self.m) ] )
self.DelinJ.append(delj)
print ("Input Errors with Each Hidden Layer Neuron: ")
print (self.DelinJ)
## Output Errors for each Hidden Layer Neuron
self.DelJ = np.array(self.DelinJ)*self.f_dash(np.array(self.Zin))
print ("Output Errors for Each Hidden Layer Neuron: ")
print (self.DelJ)
## Finally, we'll calculate the errors associated with weights joining Input
and Hidden Layer
for i in range(self.n):
for j in range(self.p):
self.DelV[i][j] = self.alpha*self.DelJ[j]*X[i]
## For Biases
for j in range(self.p):
self.DelV0[j] = self.alpha*self.DelJ[j]
print ("Changes in Weights (Input -> Hidden): ")
print (self.DelV)
print ("Change in bias: ")

print (self.DelV0)
print ("---End of Back Propagation Phase---")
def update(self):
print ("---Updation Phase Starts---")
self.W = self.W + self.DelW
self.V = self.V + self.DelV
self.W0 = self.W0 + self.DelW0
self.V0 = self.V0 + self.DelV0
print ("Updated Weights(Input -> Hidden): ")
print (self.V)
print ("Updated bias: ")
print (self.V0)
print ("Updated Weights(Hidden -> Output): ")
print (self.W)
print ("Updated bias: ")
print (self.W0)
print ("---End of Updation Phase---")
if name == " main ":
print ("Backpropagation Network: ")
print ("parameters are randomly taken between 0 and 1")
n,p,m = map(int, input("Enter number of neurons in Input, Hidden and Output Layers
respectively (n,p,m):").split())
epochs = int(input("Enter the number of Epochs:"))
bpn = BPN(n,p,m)
X = [ random.random() ]*n # the input vector
targets = [ random.random() ]*m # the output vector
for i in range(epochs):
print ("\n---EPOCH", i+1, "---\n")
bpn.feed_forward(X)
bpn.backpropagate(targets, X)
bpn.update()
print ("---END---")

