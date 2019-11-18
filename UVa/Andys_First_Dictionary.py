#Uva 10815: Andy's First Dictionary (ACEPTADO)
from sys import stdin

def main():
	diccionario = {}
	palabras = set()
	palabra = ""
	for linea in stdin:
		for caracter in linea:
			#si el caracter es minuscula o mayuscula , se crea una palabra
			if (ord(caracter) >= 65 and ord(caracter) <= 90) or (ord(caracter) >= 97 and ord(caracter) <= 122):
				palabra += caracter
			else:
				palabras.add(palabra.lower().rstrip())
				palabra = ""
	palabras.discard('') #eliminar caracter vacio
	palabrasOrdenadas = sorted(palabras,reverse=False) #ordenar en orden ascendente
	for palabra in palabrasOrdenadas:
		print(palabra)

if __name__ == '__main__':
	main()
