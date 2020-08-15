#UVA 11233 	Deli Deli (ACEPTADO)
from sys import stdin

def main():
	L,N = stdin.readline().split(' ')
	L = int(L)
	N = int(N)

	diccionario = {}
	palabras = []
	#guardar singulares y plurales en un diccionario
	for i in range(L):
		singular,plural = stdin.readline().strip().split()
		diccionario[singular] = plural
	#guardar lista de palabras en una lista
	for j in range(N):
		palabra = stdin.readline().strip()
		palabras.append(palabra)

	vocales = set()
	letras  = "aeiou"
	for char in letras:
		vocales.add(char)

	"""Leer lista de palabras y aplicar criterios especificados en el enunciado del problema"""
	for palabra in palabras:
		size = len(palabra)
		if palabra in diccionario:
			print(diccionario[palabra])
		elif palabra[size-2] not  in vocales and palabra[size-1] == 'y':
			palabra = palabra.replace(palabra[size-1],"ies")
			print(palabra)
		elif palabra[size-1] == 's' or palabra[size-1] == 'o' or\
			palabra[size-1] == 'x' or (palabra[size-2] == 'c' and palabra[size-1] == 'h')\
			or (palabra[size-2] == 's' and palabra[size-1] == 'h'):
			palabra = palabra + "es"
			print(palabra)
		else:
			palabra = palabra + "s"
			print(palabra)

if __name__ == '__main__':
	main()