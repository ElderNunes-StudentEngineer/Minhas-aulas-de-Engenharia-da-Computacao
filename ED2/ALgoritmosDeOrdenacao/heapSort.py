def heapify(vetor, n, i):
    maior = i
    esquerda = 2 * i + 1
    direita = 2 * i + 2

    if esquerda < n and vetor[esquerda] > vetor[maior]:
        maior = esquerda
    if direita < n and vetor[direita] > vetor[maior]:
        maior = direita

    if maior != i:
        vetor[i], vetor[maior] = vetor[maior], vetor[i]
        heapify(vetor, n, maior)

def build_max_heap(vetor):
    n = len(vetor)
    for i in range(n // 2 - 1, -1, -1):
        heapify(vetor, n, i)

def heapSort(vetor):
    n = len(vetor)

    build_max_heap(vetor)

    for i in range(n - 1, 0, -1):
        vetor[0], vetor[i] = vetor[i], vetor[0]
        heapify(vetor, i, 0)

vetor = [22, 54, 66, 88, 45, 99, 2]
print("Vetor original:", vetor)

heapSort(vetor)
print("Vetor ordenado (crescente):", vetor)
