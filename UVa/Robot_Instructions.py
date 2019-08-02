#UVa 12503 - Robot Instructions (ACEPTADO)

casosPrueba = int(input())
listaInstrucciones = []

#creamos una lista con ceros , que luego iremos reemplazando por "LEFT" Y "RIGHT" ---> [0,'LEFT',0,'RIGHT'.....]
movimientos = []#una lista que indica los movimientos del robot en la posicion con el numero de la instruccion
for i in range(100):
	movimientos.append(0)

#bucle a nivel mayor
for caso in range(casosPrueba):
	numeroInstrucciones = int(input())
	posicionRobot = 0
	#guardamos todas las instrucciones en una lista
	for i in range(numeroInstrucciones):
		instruccion = str(input()) #recibimos la instruccion
		lista = instruccion.split() #dividimos la instruccion como una lista
		if(lista[0] == "SAME"):
			lista.insert(2,(int(lista[2])-1))#ponemos el numero como entero -1 para que parta en 0
			lista.remove(lista[3]) #y removemos el numero en forma de string
		listaInstrucciones.append(lista)

	#recorremos la lista en busca de instrucciones
	lenght = len(listaInstrucciones)
	for instruccion in range(lenght):
		#si la instruccion es a la derecha
		if(listaInstrucciones[instruccion][0] == "RIGHT"):
			posicionRobot += 1;
			movimientos[instruccion] = "RIGHT"
		#si la instruccion es a la izquierda
		elif(listaInstrucciones[instruccion][0] == "LEFT"):
			posicionRobot -= 1;
			movimientos[instruccion] = "LEFT"
		#si la instruccion es same , nos dirijimos a la posicion donde esta el numero
		#de la instruccion A ejecutar
		elif(listaInstrucciones[instruccion][0] == "SAME"):
			numInstruccion = listaInstrucciones[instruccion][2] #guardamos el numero de la instruccion a ejecutar
			#usaremos las el vector de indicaciones para identificar la posicion y movernos
			if(movimientos[numInstruccion] == "RIGHT"):
				posicionRobot += 1
			else:
				posicionRobot -= 1
			movimientos[instruccion] = movimientos[numInstruccion]
			
	print(posicionRobot)
	#vaciamos la lista para los siguientes casos de prueba
	listaInstrucciones.clear()
