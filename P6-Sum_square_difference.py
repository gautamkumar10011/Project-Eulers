#!/usr/bin/python
import math
n = int(input("enter the range :"))
sumofthesq =  n *(n + 1) * (2*n + 1)/6
sqofsum    = (n*(n+1)/2)**2
diff = sqofsum - sumofthesq

print diff
