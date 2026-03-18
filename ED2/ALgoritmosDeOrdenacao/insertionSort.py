def insertionSort(vetor, opcao):
    n = len(vetor)
    
    for i in range(1, n):
        chave = vetor[i]
        j = i - 1
        
        if opcao == 'c': # Ordem Crescente
            while j >= 0 and vetor[j] > chave:
                vetor[j + 1] = vetor[j]
                j -= 1
        elif opcao == 'd': # Ordem Decrescente
            while j >= 0 and vetor[j] < chave:
                vetor[j + 1] = vetor[j]
                j -= 1
                
        vetor[j + 1] = chave
        
    return vetor
        
vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor original: ", vetor)
print("\nVetor em ordem crescente: ", insertionSort(vetor.copy(), 'c'))
print("\nVetor em ordem decrescente: ", insertionSort(vetor.copy(), 'd'))
            