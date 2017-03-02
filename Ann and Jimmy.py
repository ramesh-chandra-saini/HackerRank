#!/bin/python

import sys

ans = 1
n = int(raw_input().strip())
for i in range(1,n-1-1+1):
    for j in range(1,n-i-1+1):
        k = n-i-j
        if(i*j*k>ans):
            ans = i*k*j
print ans
# your code goes here
