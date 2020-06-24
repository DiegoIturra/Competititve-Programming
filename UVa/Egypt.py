#Uva 11854 	Egypt (ACEPTADO) 
from sys import stdin

def main():
    for line in stdin:
        numbers = []
        a,b,c = line.split(' ')
        a = int(a)
        b = int(b)
        c = int(c)

        if a==0 and b==0 and c==0:
            break

        numbers.append(a)
        numbers.append(b)
        numbers.append(c)

        numbers.sort()

        if numbers[0]**2 + numbers[1]**2 == numbers[2]**2:
            print('right')
        else:
            print('wrong')

if __name__ == '__main__':
    main()
