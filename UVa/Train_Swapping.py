#Uva 299 Train Swapping (ACEPTADO)
from sys import stdin

def main():
    numCases = int(stdin.readline())

    for i in range(numCases):
        lenght = int(stdin.readline())
        listCarriage = list(map(int, input().split()))
        countSwapping = 0

        #Bubble Sort 
        for j in range(lenght-1):
            for k in range(0,lenght-j-1):
                if listCarriage[k] > listCarriage[k+1]:
                    temp = listCarriage[k]
                    listCarriage[k] = listCarriage[k+1]
                    listCarriage[k+1] = temp
                    countSwapping += 1
        print('Optimal train swapping takes {} swaps.'.format(countSwapping))

if __name__ == '__main__':
    main()