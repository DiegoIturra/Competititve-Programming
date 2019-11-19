#Uva 12289: One-Two-Three (ACEPTADO)

def main():
	testCases = int(input())
	word = ""
	one = "one"
	two = "two"
	for i in range(testCases):
		word = str(input())
		countOne = 0
		countTwo = 0

		if len(word) == 5:
			print(3)
			continue
		elif len(word) == 3:
			#es uno o dos
			for char in word:
				if char in one:
					countOne += 1
				if char in two:
					countTwo += 1
			if countOne > countTwo:
				print(1)
			elif countOne < countTwo:
				print(2)
			else:
				print(1)


if __name__ == '__main__':
	main()