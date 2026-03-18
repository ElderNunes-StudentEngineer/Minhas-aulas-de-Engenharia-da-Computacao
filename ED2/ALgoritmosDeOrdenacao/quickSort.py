def quickSort(vetor, inicio, fim, opcao):
    if inicio < fim:
        pivo = particiona(vetor, inicio, fim, opcao)
        
        quickSort(vetor, inicio, pivo - 1, opcao)
        quickSort(vetor, pivo + 1, fim, opcao)
        
def particiona(vetor, inicio, fim, opcao):
    pivo = vetor[fim]
    i = inicio - 1
    
    for j in range(inicio, fim):
        if opcao == 'c': # Crescente
            if vetor[j] <= pivo:
                i += 1
                vetor[i], vetor[j] = vetor[j], vetor[i]
        elif opcao == 'd': # Decrescente
            if vetor[j] >= pivo:
                i += 1
                vetor[i], vetor[j] = vetor[j], vetor[i]
                
    vetor[i + 1], vetor[fim] = vetor[fim], vetor[i + 1]
    return i + 1

vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor original:", vetor)

vetor_crescente = vetor.copy()
quickSort(vetor_crescente, 0, len(vetor_crescente) - 1, 'c')
print("\nVetor em ordem crescente: ", vetor_crescente)

vetor_decrescente = vetor.copy()
quickSort(vetor_decrescente, 0, len(vetor_decrescente) - 1, 'd')
print("\nVetor em ordem decrescente: ", vetor_decrescente)
        