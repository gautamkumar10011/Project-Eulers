#!/usr/bin/python
limit = 1000000
length = 1
max_length = -11
required_num = 1
pre = 0
for i in range(2,limit+1,1):
	length = 1
	pre = i
	while i != 1:
		if i%2 == 0:
			i = i /2 
		else:	
			i = 3* i +1
		length += 1
	if(length > max_length):
		max_length = length 
		required_num = pre

print required_num
print
print max_length
