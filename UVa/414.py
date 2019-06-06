#UVA 11849 Machined Surfaces (ACEPTADO)
import sys

def main():
	while(True):
		numCasos = int(sys.stdin.readline())
		#verificamos que la entrada no sea un cero
		if(numCasos == 0):
			break
		#leemos las n superficies dadas en el fichero
		espacios = []
		for i in range(numCasos):
			superficie = str(sys.stdin.readline().strip().split(' '))
			cantEspacios = superficie.count(' ')
			espacios.append(cantEspacios)
		minimo = min(espacios) #guardamos la superficie con espacio minimo

		suma = 0
		for i in espacios:
			suma +=(i-minimo)
		print(suma)

if __name__ == '__main__':
	main()