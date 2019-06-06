#UVa 11942- Lumberjack Sequencing (ACEPTADO)

casosPrueba = int(input())
print("Lumberjacks:")
while(casosPrueba):
	cadenaNumeros = str(input()) #leemos la entrada como string
	lista = cadenaNumeros.split() #luego hago un split de la entrada

	#convertimos los numeros de strings a enteros y los dejamos en su misma posicion
	largo = len(lista)
	for i in range(largo):
		lista[i] = int(lista[i])

	"""si la lista es igual a la lista ordenada o si la lista es igual
	a la lista ordenada de forma reversa """
	if(lista == sorted(lista) or lista == sorted(lista,reverse=True)):
		print("Ordered")
	else:
		print("Unordered")
	casosPrueba -= 1
