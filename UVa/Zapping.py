#Uva 12468 Zapping(ACEPTADO)
def main():
	while True:
		current,target = [int(x) for x in input().split()]
		if current == -1 and target == -1:
			break
		current += 1
		target += 1
		mitad = 50
		numPressed = 0
		if abs(current-target) > mitad:
			#mover boton hacia atras
			#verificar cual canal es mayor , si el current o el target
			if target > current:
				numPressed = (100 - target) + current
			else:
				numPressed = (100 - current) + target
		else:
			#mover boton hacia adelante
			numPressed = abs(target- current)
		print(numPressed)

if __name__ == '__main__':
	main()