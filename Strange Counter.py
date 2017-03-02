#!/bin/python

import sys

t = int(raw_input().strip())
N=3 #initial value of display
while t>N:
    t-=N #in every N seconds, display show N to 1,if we can skip it completely so do it
    N*=2 #N will be twice to its initial value
N-=(t-1) #here we are sure, in this cycle we can tell time, here time decrease by 1 each time
print N #final ans to judge
    
