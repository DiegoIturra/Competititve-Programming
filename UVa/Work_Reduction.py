#Uva 10670: Work Reduction(ACEPTADO)
"""
Codigo Propio
Nombre:Diego Iturra
uva username: diturra2016
"""

from sys import stdin
import re

if __name__ == '__main__':
    numCasos = int(stdin.readline())

    for caso in range(numCasos):
        N,M,L = stdin.readline().strip().split()
        N = int(N)
        M = int(M)
        L = int(L)
        agencias = []
        for i in range(L):
            infoAgencia = stdin.readline()
            A,B = re.findall('[0-9]+', infoAgencia) #buscar numeros dentro del string
            A = int(A)
            B = int(B)
            nombreAgencia = re.findall('[A-Z]+',infoAgencia) #buscar el nombre de la agencia
            agencias.append([nombreAgencia[0],A,B]) #guardar info de la agencia
        
        #procesar todo el vector para cada caso
        valores = []
        tam = len(agencias)
        for i in range(tam): #recorrer la lista de agencias
            nombreAgencia = agencias[i][0]
            A = agencias[i][1]
            B = agencias[i][2]
            suma = 0
            tareaInicial = N
            """
            por cada agencia comparar si sale mas barato reducir a la mitad
            por el costo de B, o reducir a la mitad por el costo de reducir en
            uno el numero de tareas por el costo de A
            """
            while tareaInicial >= M and (tareaInicial//2) >= M:
                mitad = tareaInicial//2
                v1 = B
                v2 = (tareaInicial - mitad)*A
                suma += min(v1,v2)
                tareaInicial = mitad
            if tareaInicial >= M: #si aun queda tarea , reducir la diferencia por A
                suma += ((tareaInicial-M)*A)
            valores.append([suma,nombreAgencia])
        #luego ordenar por costos
        valores.sort()
        
        #mostrar salida
        tam = len(valores)
        print(f"Case {caso+1}")
        for j in range(tam):
            print(valores[j][1],valores[j][0])

