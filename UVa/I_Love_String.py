#Uva 10679 I Love Strings!! (ACEPTADO)
import re

testCases = int(input())
numQueries = 0
subString = ""
string = ""

for case in range(testCases):
	string = input()
	numQueries = int(input())
	for query in range(numQueries):
		subString = input()
		if re.search(subString,string) is not None:
			print("y")
		else:
			print("n")
