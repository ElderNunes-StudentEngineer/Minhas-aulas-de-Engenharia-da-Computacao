def grep_registros(nomeArq, stringPesquisa):
    registrosEncontrados = []
    try:
        with open(nomeArq, 'r', encoding='utf-8') as arquivo:
            for linha in arquivo:
                if stringPesquisa in linha:
                    registrosEncontrados.append(linha.strip())
    except FileNotFoundError:
        print(f"Erro! Arquivo '{nomeArq}' não encontrado!\n")
    return registrosEncontrados

if __name__ == "__main__":
    
        print("\n--- Testando função grep ---")
        
        arquivo_para_grep = 'animes_metodo5_delimitadores.txt'
        
        termoBusca = 'Naruto'
        
        registros = grep_registros(arquivo_para_grep, termoBusca)
        print("Registros:")
        for registro in registros:
            print(f"  - {registro}")