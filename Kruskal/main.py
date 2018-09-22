''' Realiza a leitura do arquivo e retorna um dicionário com as arestas e seus pesos,
    uma lista da ordem crescente das arestas em relação ao peso e uma lista que informa 
    em qual árvore cada vértice se encontra inicialmente. '''

def ReadFile(filename):
    with open(filename, 'r') as file:    
        aux = file.read().replace(' ', '\n').replace('\t', '\n')
        input = aux.split('\n')
        input = [x for x in input if x != '']
                
        edges = {}        
        n = input.pop(0)
        
        aux = 0;
        for i in range(int(n)):
            for j in range (i+1, int(n)):
                edges[str(i) + ',' + str(j)] = int(input[aux])
                aux += 1
        
        sequenceList = sorted(edges, key = edges.get)
        treetable = []
        
        for x in range(int(n)):
            treetable.append(x)
        
        return edges, sequenceList, treetable

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
    
    edges, sequenceList, treetable = ReadFile(tests.get(option))
    
    for x in sequenceList:
        
        aux = x.split(',')
        
        if (treetable[int(aux[0])] != treetable[int(aux[1])]): # Checa se os vértices não se encontram na mesma árvore
            #print ("Current Solution:", result)
            result.append(x)
            resultValue += edges.get(x)
            
            tree1 = treetable[int(aux[0])]
            tree2 = treetable[int(aux[1])]
            
            for y in range(len(treetable)): # Atualiza a àrvore de todos os vértices que foram unidos
                if (treetable[y] == tree2):
                    treetable[y] = tree1
        
    print ("\nFinal Solution:", result)
    print ("Solution's Value:", resultValue)
            
if __name__ == '__main__':
    main()
