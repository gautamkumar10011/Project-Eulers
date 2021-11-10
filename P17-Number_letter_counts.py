#!/usr/bin/python
digit = ["","One","Two" ,"Three","Four", "Five", "Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
ten = ["","", "Twenty","Thirty" ,"Forty" ,"Fifty","Sixty" ,"Seventy", "Eighty" , "Ninety"]
lenth = 0
for i in range(1,1000):
	j = i
	if i / 100 != 0 :
		lenth = lenth + len("Hundred") + len(str(digit[i/100]))
		print digit[i/100] , "Hundred"
		i  = i % 100

 	if j > 100 and j % 100 != 0 :
		lenth = lenth + len("and")
		print "and"
	if i / 10 != 0 :
		if i / 10 == 1 :
			lenth = lenth + len(str(digit[i])) 
			print digit[i]
		else :
			lenth = lenth + len(str(ten[i/10])) 
			print ten[i/10]
			i  = i % 10
			lenth = lenth + len(str(digit[i]))
			print digit[i]
	else :
			if i != 0 :
				lenth = lenth + len(str(digit[i]))	
				print digit[i]
	print
lenth = lenth + len("thousand") + len("one")
print lenth
		
