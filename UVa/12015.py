#UVa 12015 - Google is feeling lucky (ACEPTADO)
casosPrueba = int(input())
listaPaginas = []

for case in range(casosPrueba):
	for i in range(10):
		webPage = str(input()) 
		lista = webPage.split() #hacemos un split de la entrada

		#insertamos el elemento de forma entera
		lista.insert(1,int(lista[1])) #pos,element

		#y luego removemos el numero en forma de string
		lista.remove(lista[2])

		#añadimos los pares a una lista de pares
		listaPaginas.append(lista)

	#vemos cual es la pagina con mayor numero de visitas
	# y obtenemos su valor
	mayor = 0
	longitud = len(listaPaginas)
	for pagina in range(longitud):
		if listaPaginas[pagina][1] > mayor:
			mayor = listaPaginas[pagina][1]


	#recorremos la lista de pares y buscamos las paginas que tengas igual num de consultas a mayor
	print("Case #"+str(case+1)+":")
	for pagina in range(longitud):
		if listaPaginas[pagina][1] == mayor:
			print(listaPaginas[pagina][0])

	#limpiamos la lista de pares , para evitar que se acumulen del caso anterior
	listaPaginas.clear()
		
