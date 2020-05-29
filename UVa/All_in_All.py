#Uva 10340 	All in All (ACEPTADO)
#
"""
Codigo Propio
"""
from sys import stdin

def main():
	for line in stdin:
		s,t = line.split()
		
		#solucion
		isSequence = False
		counter = 0
		pos = 0
		for i in range(len(s)): #por cada letra en S
			for j in range(pos,len(t)): #por cada letra en T
				if s[i] == t[j]:
					pos = j+1 #letra siguiente,para evitar repeticion
					counter += 1
					break
			if counter == len(s): #si se encontraron todas las ocurrencias en orden
				isSequence = True #entonces es una subsecuencia de T
				break
		if isSequence:
			print("Yes")
		else:
			print("No")

if __name__ == '__main__':
	main()