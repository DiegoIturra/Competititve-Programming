#UVa 11364 Parking (ACEPTADO)
def main():
	testCases = int(input())
	for case in range(testCases):
		stores = int(input())
		listStores = [int(x) for x in input().split()]
		minStoreLength = min(listStores)
		maxStoreLength = max(listStores)
		print((maxStoreLength - minStoreLength) * 2) 

if __name__ == '__main__':
	main()