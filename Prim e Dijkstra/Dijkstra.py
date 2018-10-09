import math # math.inf (Infinito)

# Faz a leitura do arquivo e retorna a martriz de adjacencia e o numero de vertices
def ReadFile(filename):
    with open(filename, 'r') as file:
        aux = file.read().replace(' ', '\n').replace('\t', '\n')
        input = aux.split('\n')
        input = [x for x in input if x != '']

        V = int(input.pop(0))
        graph = [[0 for column in range(V)]
                    for row in range(V)]

        aux = 0;
        for i in range(V):
            for j in range (i+1, V):
                graph[i][j] = int(input[aux])
                graph[j][i] = int(input[aux])
                aux += 1

        return graph, V

# Retorna o vertice com a menor chave que ainda nao está na solução
def minKey(key, mstSet, V):
        min = math.inf

        for v in range(V):
            if key[v] < min and mstSet[v] == False:
                min = key[v]
                min_index = v

        return min_index

# Imprime o resultado
def printResult(key, parent, V):
        print ('\nSolution:', end='')
        for i in range(1, V):
            print ('(' + str(parent[i]) + ',' + str(i) + ')', end='')

        print ('\n\nNode \tDistance from root')
        for node in range(V):
            print (str(node) + '\t\t' + str(key[node]))

def main():
    result = []
    resultValue = 0

    tests = {'1':'dij4.txt', '2':'dij10.txt', '3':'dij20.txt', '4':'dij40.txt', '5':'dij50.txt'}

    print('Escolha a instancia de teste desejada')
    print('(1)dij4.txt')
    print('(2)dij10.txt')
    print('(3)dij20.txt')
    print('(4)dij40.txt')
    print('(5)dij50.txt')
    option = input('>: ')
    print('\nTeste escolhido: ' + tests.get(option))
    print('\nEscolha o vertice raiz')
    option2 = int(input('>: '))

    graph, V = ReadFile(tests.get(option))

    key = [math.inf] * V # Inicializa todas as chaves como infinitas
    parent = [None] * V # Inicializa os pais de todos os vertices como nulos
    mstSet = [False] * V # Inicializa todos os vertices como nao pertences a solucao
    key[option2] = 0 # Altera a chave do vertice raiz
    parent[option2] = -1 # Altera o pai do vertice raiz

    for cout in range(V):

        # Pega o vertice com o menor valor de chava e o adiciona a solucao
        u = minKey(key, mstSet, V)
        mstSet[u] = True

        # Checa todos os vertices que sao adjacentes a u e que ainda nao estao na solucao
        for v in range(V):
            if graph[u][v] > 0 and mstSet[v] == False and key[v] > key[u] + graph[u][v]:
                key[v] = key[u] + graph[u][v]
                parent[v] = u

    printResult(key, parent, V)

if __name__ == '__main__':
    main()
