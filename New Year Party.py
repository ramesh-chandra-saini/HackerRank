#!/bin/python

import sys


n = int(raw_input().strip())
t = map(int,raw_input().strip().split(' '))
ans = 0
for i in t:
    ans = max(ans+1,i)
print ans
