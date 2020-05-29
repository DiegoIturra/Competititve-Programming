#Uva 10763 Foreign Exchange (ACEPTADO)
"""
Codigo Propio
Nombre:Diego Iturra
uva username: diturra2016
"""

if __name__ == '__main__':
    while(True):
        listaPares = []
        numCases = int(input())
        if numCases == 0:
            break
        for i in range(numCases):
            A,B = map(int,input().split())
            listaPares.append([A,B])

        #si es impar , entonces no puede haber un intercambio completo
        if len(listaPares)%2 == 0:
            #ordenar cada sublista
            for subLista in listaPares:
                subLista.sort()
            
            #luego ordenar la lista completa
            listaPares.sort()

            cumple = True
            limite = len(listaPares) - 1
            for i in range(0,limite,2):
                if listaPares[i] == listaPares[i+1]:
                    continue
                else: #si no es igual a la lista siguiente es porque no cumple
                    cumple = False
                    break
            if cumple:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")




        

