def bubbleSort(vetor, opcao):
    n = len(vetor)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if opcao == 'c': # Ordem crescente
                if vetor[j] > vetor[j + 1]:
                    vetor[j], vetor[j + 1] = vetor[j + 1], vetor[j] # Troca os elementos se estiverem na ordem errada
            elif opcao == 'd': # Ordem decrescente
                if vetor[j] < vetor[j + 1]:
                    vetor[j], vetor[j + 1] = vetor[j + 1], vetor[j] # Troca os elementos se estiverem na ordem errada
    return vetor

vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor: ", vetor)
print("\n\nVetor em ordem crescente: ", bubbleSort(vetor.copy(), 'c'))
print("\n\nVetor em ordem decrescente: ", bubbleSort(vetor.copy(), 'd'))