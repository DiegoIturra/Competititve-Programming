#Uva 11264: Coin Collector(ACEPTADO)
def main():
	testCases = int(input())
	numCoins = 0
	for case in range(testCases):
		numCoins = int(input())
		coins = [int(i) for i in input().split()]
		maxCoins = 2 #siempre habran al menos dos monedas
		suma = coins[0]
		#para cada caso de prueba
		for i in range(1,numCoins-1):
			if(suma + coins[i] < coins[i + 1]):
				suma += coins[i]
				maxCoins += 1
		print(maxCoins)

if __name__ == '__main__':
	main()