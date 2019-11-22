#Uva 621: Secret Research (ACEPTADO)

def main():
	numSequence = int(input())
	sequence = ""
	for i in range(numSequence):
		sequence = str(input())
		size = len(sequence)

		if sequence == "1" or sequence == "4" or sequence == "78":
			print('+')
			continue
		elif(size >= 2):
			if(sequence[size-2] == "3" and sequence[size-1] == "5"):
				print('-')
				continue
			if(sequence[0] == "9" and sequence[size-1] == "4"):
				print('*')
				continue
			if(sequence[0] == "1" and sequence[1] == "9" and sequence[2] == "0"):
				print('?')
				continue
			else:
				print('?')
				continue
		else:
			print('?')

if __name__ == '__main__':
	main()