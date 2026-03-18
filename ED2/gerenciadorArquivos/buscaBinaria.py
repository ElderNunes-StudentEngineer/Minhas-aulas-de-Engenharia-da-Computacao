def extrai_chave_canon(registro_str):
    return registro_str.split(',')[0].upper()

def buscaBinaria(lista, chave_busca, registro_saida):
    chave_busca_canon = chave_busca.upper()

    inicio = 0
    
    fim = len(lista) - 1
    
    registro_encontrado_str = None
    
    while inicio <= fim:
        
        meio = (inicio + fim) // 2
        
        registro_mid_str = lista[meio]
        
        chave_mid = extrai_chave_canon(registro_mid_str)
        
        if chave_mid == chave_busca_canon:
            registro_saida[0] = registro_mid_str
            return True
        
        if chave_mid < chave_busca_canon:
            inicio = meio + 1 
            
        else: 
            fim = meio - 1
            
    registro_saida[0] = None
    return False

def main():
    NOME_ARQUIVO = 'testeBuscaBinaria.txt'
    
    try:
        with open(NOME_ARQUIVO, 'r') as f:
            lista_registros_ordenada = [linha.strip() for linha in f]

        registro_encontrado = [None] 

        chave_procurada_1 = "MANTOVANI" 
        encontrado = buscaBinaria(lista_registros_ordenada, chave_procurada_1, registro_encontrado)

        if encontrado:
            print(f"Chave '{chave_procurada_1}': ENCONTRADO!")
            print(f"Registro: {registro_encontrado[0]}")
        else:
            print(f"Chave '{chave_procurada_1}': NÃO ENCONTRADO.")

        print("\n" + "="*50 + "\n")

        chave_procurada_2 = "PEREIRA"
        encontrado = buscaBinaria(lista_registros_ordenada, chave_procurada_2, registro_encontrado)

        if encontrado:
            print(f"Chave '{chave_procurada_2}': ENCONTRADO!")
            print(f"Registro: {registro_encontrado[0]}")
        else:
            print(f"Chave '{chave_procurada_2}': NÃO ENCONTRADO.")

    except FileNotFoundError:
        print(f"Erro: O arquivo '{NOME_ARQUIVO}' não foi encontrado.")
    except Exception as e:
        print(f"Ocorreu um erro: {e}")

if __name__ == "__main__":
    main()