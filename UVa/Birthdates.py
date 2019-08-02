#UVA- Birthdates(ACEPTADO)
def findOldestPerson(data):
	oldestPerson = None
	#primero ordenamos por clave year
	data.sort(key=lambda x: x[3])
	#creamos una lista para almacenar por menor clave: year
	listaYear = []
	menorYear = data[0][3] #actual annio menor
	for i in range(len(data)):
		if(data[i][3] == menorYear):
			listaYear.append(data[i])
	#una vez nuestra lista de annios buscamos por mes
	if(len(listaYear) <= 1):
		oldestPerson = listaYear[0]
	else:
		#si hay mas de una clave con el mismo annio
		#entonces ordenamos por mes
		listaYear.sort(key=lambda y: y[2])
		#asumimos que la primera persona tiene el mes menor
		menorMes = listaYear[0][2]
		listaMes = []
		for i in range(len(listaYear)):
			if(listaYear[i][2] == menorMes):
				listaMes.append(listaYear[i])
		#una vez finalizada la lista de mes buscamos por dia
		if(len(listaMes) <= 1):
			oldestPerson = listaMes[0]
		else:
			#si hay mas de una clave con el mismo mes
			#entonces ordenamos por dia
			listaMes.sort(key=lambda z: z[1])
			oldestPerson = listaMes[0]
	return oldestPerson


def findYoungestPerson(data):
	youngestPerson = None
	pos = 0
	#primero ordenamos por clave year
	data.sort(key=lambda x: x[3])
	#creamos una lista para almacenar por menor clave: year
	listaYear = []
	mayorYear = data[len(data)-1][3]
	for i in range(len(data)-1 ,-1,-1):
		if(data[i][3] == mayorYear):
			listaYear.append(data[i])
	#vemos la cantidad de personas con la misma clave annio
	if(len(listaYear) <= 1):
		youngestPerson = listaYear[0]
	else:
		#si hay mas personas con el mismo annio
		#entonces ordenamos por mes
		listaYear.sort(key=lambda y: y[2])
		mayorMes = listaYear[len(listaYear)-1][2]
		listaMes = []
		for i in range(len(listaYear)):
			if(mayorMes == listaYear[i][2]):
				listaMes.append(listaYear[i])
		#una vez finalizada la busqueda filtramos por dia
		if(len(listaMes) <= 1):
			youngestPerson = listaMes[0]
		else:
			#si hay mas de una persona con el mismo dia
			#ordenamos por dia
			listaMes.sort(key=lambda z: z[1])
			#asumimos que la ultima persona tiene el mayor dia
			youngestPerson = listaMes[len(listaMes)][1]
	return youngestPerson


def main():
	cant = int(input())
	data = []
	for persona in range(cant):
		infoPersona = str(input())
		info = infoPersona.split()
		info[1] = int(info[1]) #day
		info[2] = int(info[2]) #month
		info[3] = int(info[3]) #year
		data.append(info)
	
	youngestPerson = findYoungestPerson(data)
	print(youngestPerson[0])
	oldestPerson = findOldestPerson(data)
	print(oldestPerson[0])

if __name__ == '__main__':
	main()
