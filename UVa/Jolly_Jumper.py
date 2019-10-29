#Uva 10038: Jolly Jumper(ACEPTADO)
from sys import stdin

def main():
	for line in stdin:
		secuencia = line.split()
		secuencia = list(map(int,secuencia))
		secuencia.pop(0)
		size = len(secuencia)
		hallados = []

		#rellenar lista de booleanos
		for i in range(size + 1):
			hallados.append(False)

		#para cada elemento en la secuencia
		for i in range(size - 1):
			diferencia = abs(secuencia[i] - secuencia[i+1])
			if(diferencia <= size-1):
				hallados[diferencia] = True

		isJolly = True
		for i in range(1,size):
			if not hallados[i]:
				print("Not jolly")
				isJolly = False
				break

		if isJolly:
			print("Jolly")

if __name__ == '__main__':
	main()

