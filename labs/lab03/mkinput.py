#!/usr/bin/env python

import sys
import string

input1 = '''a'''
input2 = '''a
b
a'''
input3 = '''c
bb
a
aa'''

def doprint(xarg):
    print xarg

def complexoutput():
    letlist = string.ascii_lowercase
    for l in range(len(letlist)):
        print letlist[l]
    for l in range(len(letlist)):
        print letlist[len(letlist)-l-1]*2
    for l in range(len(letlist)):
        print letlist[l]*3


if len(sys.argv) < 2:
    print "Too few arguments"
    sys.exit(0)

num = int(sys.argv[1])
xhash = {
    1: lambda: doprint(input1),
    2: lambda: doprint(input2),
    3: lambda: doprint(input3),
    4: complexoutput
}

if 1 <= num <= 4:
    xhash[num]()
else:
    print "Bad test number"
