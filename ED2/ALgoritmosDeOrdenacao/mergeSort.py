def mergeSort(vetor, inicio, fim, opcao):
    if inicio < fim:
        meio = (inicio + fim) // 2

        mergeSort(vetor, inicio, meio, opcao)        # Lado esquerdo
        mergeSort(vetor, meio + 1, fim, opcao)        # Lado direito

        merge(vetor, inicio, meio, fim, opcao)       

def merge(vetor, inicio, meio, fim, opcao):
    esquerda = vetor[inicio:meio + 1]
    direita = vetor[meio + 1:fim + 1]

    i = j = 0
    k = inicio

    while i < len(esquerda) and j < len(direita):
        if opcao == 'c':  # Crescente
            if esquerda[i] <= direita[j]:
                vetor[k] = esquerda[i]
                i += 1
            else:
                vetor[k] = direita[j]
                j += 1
        elif opcao == 'd':  # Decrescente
            if esquerda[i] >= direita[j]:
                vetor[k] = esquerda[i]
                i += 1
            else:
                vetor[k] = direita[j]
                j += 1
        k += 1

    while i < len(esquerda):
        vetor[k] = esquerda[i]
        i += 1
        k += 1

    while j < len(direita):
        vetor[k] = direita[j]
        j += 1
        k += 1

vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor original:", vetor)

vetor_crescente = vetor.copy()
mergeSort(vetor_crescente, 0, len(vetor_crescente) - 1, 'c')
print("\nVetor em ordem crescente: ", vetor_crescente)

vetor_decrescente = vetor.copy()
mergeSort(vetor_decrescente, 0, len(vetor_decrescente) - 1, 'd')
print("\nVetor em ordem decrescente: ", vetor_decrescente)