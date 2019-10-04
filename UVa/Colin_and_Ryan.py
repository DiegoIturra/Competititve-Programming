#Uva 10880 - Colin and Ryan (ACEPTADO)
#codigo propio
import math

def main():
	testCases = int(input())
	case = 0
	for i in range(testCases):
		case += 1
		cookies , cookiesLeft = [int(x) for x in input().split()]
		if cookies == cookiesLeft:
			print("Case #" + str(case) + ": " + str(0))
			continue
		print("Case #" + str(case) + ":",end="")
		diferencia = cookies - cookiesLeft
		top = int(math.sqrt(diferencia))
		listaFactores = set() #evitar repeticiones de factores

		#ver los factores
		for j in range(1,top+1):
			if diferencia % j == 0:
				listaFactores.add(j)
				listaFactores.add(diferencia // j)
		#ordenar e imprimir
		sortList = sorted(listaFactores)
		for factor in sortList:
			if factor > cookiesLeft:
				print(" " + str(factor),end="")
		print()

if __name__ == '__main__':
	main()