#!/usr/bin/python
import math
name= "from the question , In array forat"

count = 0
for i in range(1786):
	x = str(name[i])
	l = len(x)
	summ = 0
	for j in range(l):
		summ = summ + ord(x[j]) - 64

	x = (-1 + math.sqrt(1 + 8*summ))/2
	y = int(x)
	if x == y:
		count = count + 1
		print y , i
print count
