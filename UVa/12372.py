#Uva 12372 Packing for Holiday (ACEPTADO)

def main():
	testCases = int(input())
	for case in range(testCases):	
		length,width,heigth = [int(x) for x in input().split()] #leer entrada en una sola linea
		if(length > 20 or width > 20 or heigth > 20):
			print("Case " + str(case+1) + ": " + "bad")
		else:
			print("Case " + str(case+1) + ": " + "good")

if __name__ == '__main__':
	main()
