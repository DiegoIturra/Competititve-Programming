#Uva 12403 Save Setu (ACEPTADO)
import sys

def main():
	testCases = int(input())
	string  = ""
	suma = 0
	for case in range(testCases):
		string = str(input())
		listString = string.split(' ')

		#mientras no exista report , suma
		if(listString[0] != "report"):
			suma += int(listString[1])
		else:
			print(suma)
		
if __name__ == '__main__':
	main()
