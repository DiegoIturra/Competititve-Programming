#Uva 10611: The Playboy Chimp(ACEPTADO)

def binarySearch(listaAlturas,alturaLuchu):
	right = len(listaAlturas)-1
	left = 0
	mitad = 0
	candidatas = []
	#buscar el mas alto pero mas bajo que luchu
	while(left <= right):
		mitad = (left + right) // 2
		if(listaAlturas[mitad] < alturaLuchu):
			left = mitad + 1
		elif(listaAlturas[mitad] >= alturaLuchu):
			right = mitad - 1
	if(right < 0):
		candidatas.append('X')
	else:
		candidatas.append(listaAlturas[right])
	#setear datos de la busqueda anterior
	right = len(listaAlturas)-1
	left = 0
	mitad = 0
	#buscar el mas bajo pero mas alto que luchu
	while(left <= right):
		mitad = (left + right) // 2
		if(listaAlturas[mitad] <= alturaLuchu):
			left = mitad + 1
		elif(listaAlturas[mitad] > alturaLuchu):
			right = mitad - 1
	if(left >= len(listaAlturas)):
		candidatas.append('X')
	else:
		candidatas.append(listaAlturas[left])
	return candidatas

def main():
	NumChimpaces = int(input())
	alturas = [int(altura) for altura in input().split()]
	numConsultas = int(input())
	consultas = [int(consulta) for consulta in input().split()]
	alto = None
	bajo = None
	for alturaLuchu in consultas:
		bajo,alto = binarySearch(alturas,alturaLuchu)
		print(bajo,end=" ")
		print(alto)

if __name__ == '__main__':
	main()