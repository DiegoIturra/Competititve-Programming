#Uva 11332: Summing Digits (ACEPTADO)

def decompose(number):
	num = 0
	"""
	remainder: almacena el digito en cada iteracion
	num: suma cada digito para generar un numero cada vez mas pequeño
		en cada llamada recursiva
	"""
	while number > 0:
		remainder = number % 10
		number = number // 10
		num += remainder

	if num < 10:
		return num
	else:
		return decompose(num)

def main():
	while(True):
		number = int(input())
		if number == 0:
			break
		print(decompose(number))

if __name__ == '__main__':
	main()