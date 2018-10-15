class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value

    def toString(self):
        return ('(' + str(self.weight) + ',' + str(self.value) + ')')

''' Faz a leitura do arquivo e retorna uma lista com os itens, uma lista com a contagem
    dos pesos ate o peso maximo, a matriz memo e a capacidade maxima da mochila'''
def ReadFile(filename):
    with open(filename, 'r') as file:
        aux = file.read().replace(' ', '\n').replace('\t', '\n')
        input = aux.split('\n')
        input = [x for x in input if x != '']

        numItems = int(input.pop(0))
        knapsackCapacity = int(input.pop(0))

        memo = [[None for column in range(numItems+1)]
                    for row in range(knapsackCapacity+1)]

        aux = 0
        items = []
        for i in range(numItems):
            items.append(Item(int(input[aux]), int(input[aux + 1])))
            aux += 2

        W = list(range(0, knapsackCapacity+1))

        return items, W, memo, knapsackCapacity

def main():
    solution = []

    tests = {'1':'mochila01.txt', '2':'mochila02.txt', '3':'mochila1000.txt', '4':'mochila2500.txt', '5':'mochila5000.txt'}

    print('Escolha a instancia de teste desejada')
    print('(1)mochila01.txt')
    print('(2)mochila02.txt')
    print('(3)mochila1000.txt')
    print('(4)mochila2500.txt')
    print('(5)mochila5000.txt')
    option = input('>: ')
    print('\nTeste escolhido: ' + tests.get(option))

    items, W, memo, knapsackCapacity = ReadFile(tests.get(option))

    #Constroi a matriz memo
    for w in W:
        for i in range(len(items) + 1):
            if (w == 0 or i == 0):
                memo[w][i] = 0
            elif (w < items[i-1].weight):
                memo[w][i] = memo[w][i-1]
            else:
                memo[w][i] = max (memo[w - items[i - 1].weight][i - 1] + items[i - 1].value, memo[w][i-1])

    #Apresenta o valor da ultima posicao da matriz memo, que e o valor da solucao
    print('\nValue: ' + str(memo[w][i]))

    #Encontra os itens que foram selecionados para encontrar o valor da solucao
    for x in range(i, 0, -1):
        if (memo[knapsackCapacity][x] != memo[knapsackCapacity][x - 1]):
            solution.append(x)
            knapsackCapacity -= items[x-1].weight

    #Ordena os itens que foram selecionados
    solution.sort()

    #Apresenta os itens que foram selecionados
    print('Chosen Items: ', end='')
    print(solution)

if __name__ == '__main__':
    main()
