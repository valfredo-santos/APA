class Aresta:    
    def __init__(self, vertice1, vertice2, valor):
        self.vertice1 = vertice1
        self.vertice2 = vertice2
        self.valor = valor
    
    def toString(self):
        return ('(' + str(self.vertice1) + ',' + str(self.vertice2) + ')')

def takeValue(elem):
    return elem.valor

def ReadFile(filename):
    with open(filename, 'r') as file:    
        aux = file.read().replace(' ', '\n').replace('\t', '\n')
        input = aux.split('\n')
        input = [x for x in input if x != '']
                
        edges = []        
        n = input.pop(0)
        
        aux = 0;
        for i in range(int(n)):
            for j in range (i+1, int(n)):
                edges.append(Aresta(i, j, int(input[aux])))
                aux += 1
        
        
        edges.sort(key = takeValue)
        
        treetable = []
        
        for x in range(int(n)):
            treetable.append(x)
        
        return edges, treetable

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
    
    edges, treetable = ReadFile(tests.get(option))
    
    for x in edges:
                           
        tree1 = treetable[x.vertice1]
        tree2 = treetable[x.vertice2]
        
        if (tree1 != tree2): # Checa se os vértices não se encontram na mesma árvore
            #print ("Current Solution:", result)
            result.append(x)
            resultValue += x.valor
            
            for y in range(len(treetable)): # Atualiza a àrvore de todos os vértices que foram unidos
                if (treetable[y] == tree2):
                    treetable[y] = tree1
        
    print ('Solution:', end='')
    
    for x in result:
        print(x.toString(), end='')
    
    print('')
        
    print ('Value:', resultValue)
            
if __name__ == '__main__':
    main()
