#Uva 11292: The Dragon of Loowater(ACEPTADO)
def main():
	dragones = [] 
	caballeros = []
	dragon = caballero = None
	while(True):
		numDragones,numCaballeros = [int(i) for i in input().split()]
		if numCaballeros == 0 and numDragones == 0:
			break
		#leer los diametros de las cabezas de los dragones
		for i in range(numDragones):
			dragon = int(input())
			dragones.append(dragon)
		#leer las alturas de los caballeros
		for i in range(numCaballeros):
			caballero = int(input())
			caballeros.append(caballero)
		
		#ordenar la entrada para hacer las comparaciones con todos los caballeros y dragones
		dragones.sort()
		caballeros.sort()
		dinero = 0
		i = 0
		j = 0
		#SOLUCION GREEDY
		#mientras queden caballeros y dragones por comparar
		while(i < numDragones and j < numCaballeros):
			#si un caballero no puede matar un dragon , entonces prueba con el siguiente
			while(dragones[i] > caballeros[j] and j < numCaballeros):
				j += 1
				if j == numCaballeros: #para evitar hacer comparaciones con posiciones no existentes
					break
			#si se ha recorrido toda la lista de caballeros
			#ya no se pueden matar mas dragones
			if(j == numCaballeros):
				break
			dinero += caballeros[j]
			j += 1
			i += 1
		if(i == len(dragones)):
			print(dinero)
		else:
			print("Loowater is doomed!")
		dragones.clear()
		caballeros.clear()

if __name__ == '__main__':
	main()