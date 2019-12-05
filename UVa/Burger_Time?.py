#Uva 11661 	Burger Time? (ACEPTADO)
import sys

"""
solucion es O(n^2) -> algoritmo funciona pero NO entra en tiempo
"""
def findDistance(highway,length):
	values = []
	""" recorrer el string en busca de una letra 
	ya sea una Z o una R """
	flag = False
	for i in range(length):
		if highway[i] == 'Z':
			flag = True
			break
		elif highway[i] == 'R':
			count = -1
			index = i
			distance1 = sys.maxsize
			distance2 = distance1
			#buscar hacia adelante
			while index < length:
				count += 1
				if highway[index] == 'D':
					distance1 = count
					break
				index += 1

			#buscar hacia atras
			count = -1
			index = i
			while index >= 0:
				count += 1
				if highway[index] == 'D':
					distance2 = count
					break
				index -= 1
			values.append(min(distance1,distance2))
	if flag:
		minimum = 0
	else:
		minimum = min(values)
	return minimum


#solucion es O(n): entra en tiempo en solo una pasala lineal
def findSolution(highway,length):
	posD = -1
	posR = -1
	minimum = sys.maxsize
	for i in range(length):
		if highway[i] == 'Z':
			return 0
		elif highway[i] == 'D':
			posD = i
			if posR != -1:
				minimum = min(minimum,abs(posR-posD))
		elif highway[i] == 'R':
			posR = i
			if posD != -1:
				minimum = min(minimum,abs(posR-posD))
	return minimum

def main():
	while(True):
		length = int(input())
		if length == 0:
			break
		highway = str(input())

		#recorrer el string en busca de Z y/o R
		print(findSolution(highway,length))


if __name__ == '__main__':
	main()