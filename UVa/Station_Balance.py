#Uva 410 Station Balance (ACEPTADO)
"""
Codigo Propio
Nombre:Diego Iturra
uva username: diturra2016
"""

from sys import stdin

def imbalance(mass1,mass2,AM):
	return abs((mass1 + mass2) - AM)

def calculateAM(massList,numCameras):
	return sum(massList) / numCameras

if __name__ == '__main__':
	case = 1
	for line in stdin:
		C,S = line.split()
		C = int(C) #numero de camaras
		S = int(S) #cantidad de especimenes
		massList = [int(i) for i in input().split()]

		am = calculateAM(massList,C) #se obtiene el AM

		if S < 2*C:
			remaining = 2*C - S
			for i in range(remaining):
				massList.append(0) #rellenar con ceros
		massList.sort()

		left = 0
		right = len(massList) - 1
		totalImbalace = 0
		sets = []

		"""
		tomar el extremo derecho y el izquierdo y calcular imbalance
		e ir reduciendo el indice derecho y aumentando el indice izquierdo
		"""
		while(right > left):
			totalImbalace += imbalance(massList[left],massList[right],am)
			sets.append([massList[left],massList[right]])

			right -= 1
			left += 1

		#imprimir salida
		print("Set #{}".format(case))
		tamBuckets = len(sets)
		for i in range(tamBuckets):
			if sets[i][0] == 0 and sets[i][1] == 0:
				print(" {}:".format(i))
				continue
			print(" {}: ".format(i),end="")
			for j in range(len(sets[i])):
				if sets[i][j] != 0:
					if j == len(sets[i])-1:
						print(sets[i][j],end="")
					else:
						print(sets[i][j],end=" ")
				else:
					continue
			print()

		print("IMBALANCE = {:.5f}".format(totalImbalace))
		print()
		case += 1





		
		



