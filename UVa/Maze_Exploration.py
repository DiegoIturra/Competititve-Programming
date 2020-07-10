#UVA 784-Maze Exploration (ACEPTADO)
from sys import stdin
import re

#movimientos posibles
movX = [-1,1,0,0]
movY = [0,0,1,-1]

#obtener posicion del *
def getPosition(grid):
    pos = []
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == '*':
                pos.append(i)
                pos.append(j)
                break
    return pos

#generar vecinos a partir de la posicion (x,y)
def generarVecinos(x,y,grid,visitados,queue):
    for i in range(4):
        rr = x + movX[i]
        cc = y + movY[i]

        #Si se sale de la matriz o ya ha sido visitado o si es una pared
        if rr < 0 or cc < 0: continue
        if visitados[rr][cc] == True: continue
        if grid[rr][cc] != ' ' and grid[rr][cc] != '*': continue

        queue.append([rr,cc])
        visitados[rr][cc] = True
        grid[rr][cc] = '#'

#busqueda en anchura
def BFS(grid):
    queue = []
    visitados = generarVisitados(grid)
    startPos = getPosition(grid)
    queue.append(startPos)

    while len(queue) > 0:
        current = queue.pop(0)
        x = current[0]
        y = current[1]

        generarVecinos(x,y,grid,visitados,queue)

#crea una matriz de visitados
def generarVisitados(grid):
    visitados = []
    for i in range(len(grid)):
        visitados.append([])
        for j in range(len(grid[i])):
            if grid[i][j] == ' ' or grid[i][j] == '*':
                visitados[i].append(False)
            else:
                visitados[i].append(None)
    return visitados


def main():
    numMaze = int(stdin.readline())

    maze = []
    endLine = []
    count = 0
    for i in range(numMaze):
        while(True):
            lab = stdin.readline()
            if lab[0] == '_': #si se halla un _ entonces termino el laberinto actual
                endLine.append(lab)
                break

            #si es un string valido
            lista = []
            lab = re.sub(r"[\n]", "", lab) #eliminar salto de linea
            for char in lab:
                lista.append(char)
            maze.append(lista)

        BFS(maze)

        #imprimir
        for i in range(len(maze)):
            for j in range(len(maze[i])):
                print(maze[i][j],end="")
            print()
        print(endLine[count],end="")
        count += 1

        #limpiar laberinto actual
        maze.clear()

if __name__ == '__main__':
    main()
