def selectionSort(vetor, opcao):
    n = len(vetor)

    for i in range(n):
        indice_extremo = i
        for j in range(i + 1, n):
            if opcao == 'c':  # Ordem crescente
                if vetor[j] < vetor[indice_extremo]:
                    indice_extremo = j
            elif opcao == 'd':  # Ordem decrescente
                if vetor[j] > vetor[indice_extremo]:
                    indice_extremo = j
        vetor[i], vetor[indice_extremo] = vetor[indice_extremo], vetor[i]  # Troca os elementos se estiverem na ordem errada

    return vetor

vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor original: ", vetor)
print("\nVetor em ordem crescente: ", selectionSort(vetor.copy(), 'c'))
print("\nVetor em ordem decrescente: ", selectionSort(vetor.copy(), 'd'))
