#UVa 12279 Emoogle Balance (ACEPTADO)
def main():
	case = 0
	while(True):
		testCases = int(input())
		if(testCases == 0):
			break
		case += 1
		listEvents = [int(x) for x in input().split()]
		reasonTreat = 0
		giveTreat = 0
		for event in listEvents:
			if(event > 0):
				reasonTreat += 1
			else:
				giveTreat += 1
		emoogleBalance = reasonTreat - giveTreat
		print("Case " + str(case) + ": " + str(emoogleBalance))
		

if __name__ == '__main__':
	main()
