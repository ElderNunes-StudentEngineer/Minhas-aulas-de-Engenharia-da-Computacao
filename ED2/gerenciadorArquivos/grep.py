def grep(nomeArq, stringPesquisa):
    indicesEncontrados = set()
    try:
        with open(nomeArq, 'r', encoding='utf-8') as arquivo:
            for i, linha in enumerate(arquivo):
                if stringPesquisa in linha:
                    indicesEncontrados.add(i)
    except FileNotFoundError:
        print(f"Erro! Arquivo '{nomeArq}' não encontrado!\n")
    return indicesEncontrados    

if __name__ == "__main__":
    
        print("\n--- Testando função grep ---")
        
        arquivo_para_grep = 'animes_metodo5_delimitadores.txt'

        termo_busca_1 = "Naruto"
        linhas_encontradas_1 = grep(arquivo_para_grep, termo_busca_1)
        print(f"Buscando por '{termo_busca_1}': Linhas encontradas nos índices {linhas_encontradas_1}")
