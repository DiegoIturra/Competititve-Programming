"""
UVA 11362 Phone List (ACEPTADO)
Nombre : Diego Iturra Huenteo
codigo propio
uva username: diturra2016
"""
from sys import stdin

def main():
	numCases = int(stdin.readline().rstrip())
	for i in range(numCases):
		numPhones = int(stdin.readline().rstrip())
		phones = []
		for j in range(numPhones):
			phone = stdin.readline().rstrip()
			phones.append(phone)
		phones.sort()

		#string matching
		match = False
		for i in range(len(phones)-1):
			if phones[i+1] >= phones[i]: #en caso contrario el string actual no cabe dentro del string objetivo
				substring = phones[i+1][:len(phones[i])]#substring del string mayor a partir de la longitud del primero
				if substring == phones[i]:
					match = True
					break
		if match:
			print("NO")
		else:
			print("YES")

if __name__ == '__main__':
	main()