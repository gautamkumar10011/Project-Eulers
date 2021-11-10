#!/usr/bin/python
f1 = 1
f2=  1
fn = 2
counter = 2
while len(str(fn)) < 1000 :
	fn = f1 + f2
	f1 = f2
	f2 = fn 
	counter = counter + 1
print counter
