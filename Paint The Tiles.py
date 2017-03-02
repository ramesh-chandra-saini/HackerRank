#!/bin/python

import sys


N = int(raw_input().strip())
C = raw_input().strip()
ans ,i= 0, 0 #store ans
while i<N :
    c = C[i] #first color of segment
    while i<N and c==C[i]:
        i+=1 #till you get same color, count into one segment
    ans+=1 #update number of segment
print ans #print ans to judge
