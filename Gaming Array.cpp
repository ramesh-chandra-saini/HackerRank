#!/bin/python

import sys


g = int(raw_input().strip())
for a0 in xrange(g):
    n = int(raw_input().strip())
    arr = map(int,raw_input().split(' '))
    #print n,arr
    mx, __mx  = [], 0 # store left max
    for i in arr:
        if i>__mx:
            __mx = i
        mx.append(__mx)
    ans = 0;
    #print 'Hi'
    #print n, arr,mx
    j=len(mx)-1
    while j>=0:
        #print j,' ==> ',
        while j>=0 and arr[j]!=mx[j] :
            j-=1;#find left max actual position in arr and split array over that point
        j-=1
        #print j
        ans+=1;#count as this one partition(Step)
    if ans%2==1:
        print 'BOB'
    else:
        print 'ANDY'
    

