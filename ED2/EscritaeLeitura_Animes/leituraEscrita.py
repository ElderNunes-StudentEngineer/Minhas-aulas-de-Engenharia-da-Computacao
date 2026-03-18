import csv
import os
from collections import OrderedDict

#==============================================================================
# DEFINIÇÃO GLOBAL DAS COLUNAS
#==============================================================================
COLUNAS_CHAVES = [
    'nome', 'anime_url', 'anime_img', 'episodes', 'votes', 'weight', 'rating',
    'rate_1', 'rate_2', 'rate_3', 'rate_4', 'rate_5', 'genre_action', 
    'genre_adventure', 'genre_comedy', 'genre_drama', 'genre_family', 
    'genre_fantasy', 'genre_food', 'genre_harem', 'genre_historical', 
    'genre_horror', 'genre_idols', 'genre_isekai', 'genre_jdrama', 
    'genre_magical girls', 'genre_martial arts', 'genre_mecha', 'genre_music', 
    'genre_mystery', 'genre_post-apocalyptic', 'genre_romance', 'genre_sci-fi', 
    'genre_seinen', 'genre_sgdrama', 'genre_shojo', 'genre_shonen', 
    'genre_slice of life', 'genre_sports', 'genre_supernatural', 'genre_thriller'
]

#==============================================================================
# FUNÇÃO DE LEITURA 
#==============================================================================
def ler_csv_para_dataset(nome_arquivo_csv):
    """
    Lê o CSV, carrega todas as colunas e converte todos os campos
    numéricos para os tipos corretos (int/float).
    """
    dataset = []
    try:
        with open(nome_arquivo_csv, mode='r', encoding='utf-8') as csvfile:
            leitor_csv = csv.DictReader(csvfile)
            for linha in leitor_csv:
                try:
                    # Converte todos os campos que devem ser inteiros
                    for chave in ['episodes', 'votes', 'weight', 'rate_1', 'rate_2', 'rate_3', 'rate_4', 'rate_5']:
                        linha[chave] = int(linha[chave])
                    
                    # Converte todos os campos que devem ser float 
                    for chave in ['rate'] + [k for k in linha if k.startswith('genre_')]:
                         linha[chave] = float(linha[chave])
                    
                    # Renomeia as chaves para o padrão ('anime' -> 'nome', 'rate' -> 'rating')
                    linha['nome'] = linha.pop('anime')
                    linha['rating'] = linha.pop('rate')
                    
                    dataset.append(linha)
                except (ValueError, KeyError, TypeError):
                    continue
    except FileNotFoundError:
        print(f"ERRO CRÍTICO: O arquivo de entrada '{nome_arquivo_csv}' não foi encontrado.")
        return None
    
    print(f"Sucesso: {len(dataset)} animes lidos do arquivo '{nome_arquivo_csv}'.")
    return dataset

#==============================================================================
# MÉTODO 1: TAMANHO FIXO
#==============================================================================
TAMANHOS_FIXOS = OrderedDict([
    ('nome', 150), ('anime_url', 250), ('anime_img', 250), ('episodes', 10), 
    ('votes', 10), ('weight', 10), ('rating', 10), ('rate_1', 10), 
    ('rate_2', 10), ('rate_3', 10), ('rate_4', 10), ('rate_5', 10),
    ('genre_action', 5), ('genre_adventure', 5), ('genre_comedy', 5), 
    ('genre_drama', 5), ('genre_family', 5), ('genre_fantasy', 5), 
    ('genre_food', 5), ('genre_harem', 5), ('genre_historical', 5), 
    ('genre_horror', 5), ('genre_idols', 5), ('genre_isekai', 5), 
    ('genre_jdrama', 5), ('genre_magical girls', 5), ('genre_martial arts', 5), 
    ('genre_mecha', 5), ('genre_music', 5), ('genre_mystery', 5), 
    ('genre_post-apocalyptic', 5), ('genre_romance', 5), ('genre_sci-fi', 5), 
    ('genre_seinen', 5), ('genre_sgdrama', 5), ('genre_shojo', 5), 
    ('genre_shonen', 5), ('genre_slice of life', 5), ('genre_sports', 5), 
    ('genre_supernatural', 5), ('genre_thriller', 5)
])

TAMANHO_REGISTRO_BYTES = sum(TAMANHOS_FIXOS.values())

def escritaTamanhoFixo(nome_arquivo, dataset):
    with open(nome_arquivo, 'wb') as arquivo:
        for anime in dataset:
            registro_completo = b''
            for chave, tamanho in TAMANHOS_FIXOS.items():
                valor_str = str(anime.get(chave, '')) # .get para segurança
                valor_bytes = valor_str.encode('utf-8')
                valor_bytes = valor_bytes[:tamanho] 
                valor_pad = valor_bytes.ljust(tamanho, b' ')
                registro_completo += valor_pad
            arquivo.write(registro_completo)
    print(f"Método 1: Arquivo binário '{nome_arquivo}' salvo com sucesso!")

def leituraTamanhoFixo(nome_arquivo):
    dataset_lido = []
    chaves_inteiras = {'episodes', 'votes', 'weight', 'rate_1', 'rate_2', 'rate_3', 'rate_4', 'rate_5'}
    chaves_float = {'rating'} | {k for k in COLUNAS_CHAVES if k.startswith('genre_')}

    try:
        with open(nome_arquivo, 'rb') as arquivo:
            while True:
                registro_bytes = arquivo.read(TAMANHO_REGISTRO_BYTES)
                if not registro_bytes:
                    break 
                
                registro_lido = {}
                posicao_atual = 0
                
                for chave, tamanho in TAMANHOS_FIXOS.items():
                    campo_bytes = registro_bytes[posicao_atual : posicao_atual + tamanho]
                    posicao_atual += tamanho
                    
                    # Converte de volta para string e remove os espaços
                    valor_str = campo_bytes.decode('utf-8').strip()
                    
                    try:
                        if chave in chaves_inteiras:
                            registro_lido[chave] = int(valor_str)
                        elif chave in chaves_float:
                            registro_lido[chave] = float(valor_str)
                        else:
                            registro_lido[chave] = valor_str
                    except (ValueError, TypeError):
                        registro_lido[chave] = None 
                
                dataset_lido.append(registro_lido)

    except FileNotFoundError:
        return []
    return dataset_lido


#==============================================================================
# MÉTODOS 2 e 5: DELIMITADORES 
#==============================================================================
def escritaComDelimitador(nome_arquivo, dataset, delimitador=';'):
    with open(nome_arquivo, 'w', encoding='utf-8', newline='') as arquivo:
        escritor_csv = csv.writer(arquivo, delimiter=delimitador)
        escritor_csv.writerow(COLUNAS_CHAVES)
        
        for anime in dataset:
            linha_para_escrever = [anime.get(chave, '') for chave in COLUNAS_CHAVES]
            escritor_csv.writerow(linha_para_escrever)

    print(f"Métodos 2/5: Arquivo de texto '{nome_arquivo}' salvo com sucesso!")

#==============================================================================
# MÉTODO 3: INDICADOR DE TAMANHO
#==============================================================================
def escritaQtdeBytes(nome_arquivo, dataset):
    with open(nome_arquivo, 'w', encoding='utf-8') as arquivo:
        for anime in dataset:
            partes_registro = []
            # Itera na ordem correta das colunas
            for chave in COLUNAS_CHAVES:
                valor_str = str(anime.get(chave, ''))
                partes_registro.append(f"{len(valor_str)}|{valor_str}")
            
            registro_final = "|".join(partes_registro)
            arquivo.write(registro_final + '\n')
    print(f"Método 3: Arquivo de texto '{nome_arquivo}' salvo com sucesso!")

#==============================================================================
# MÉTODO 4: ARQUIVO DE ÍNDICES 
#==============================================================================
def escritaArquivoIndices(nome_base_arquivo, dataset):
    arquivo_dados_nome = f"{nome_base_arquivo}_dados.txt"
    arquivo_indices_nome = f"{nome_base_arquivo}_indices.txt"
    
    with open(arquivo_dados_nome, 'w', encoding='utf-8') as f_dados, \
         open(arquivo_indices_nome, 'w', encoding='utf-8') as f_indices:
        
        posicao_atual_bytes = 0
        for anime in dataset:
            valores = [str(anime.get(chave, '')) for chave in COLUNAS_CHAVES]
            registro = ";".join(valores) + "\n"
            
            f_indices.write(f"{anime['nome']};{posicao_atual_bytes}\n")
            f_dados.write(registro)
            posicao_atual_bytes += len(registro.encode('utf-8'))
            
    print(f"Método 4: Arquivos '{arquivo_dados_nome}' e '{arquivo_indices_nome}' salvos!")

#==============================================================================
# ROTINA PRINCIPAL DE EXECUÇÃO
#==============================================================================
if __name__ == "__main__":
    arquivo_csv_entrada = 'animes.csv'
    
    dataset_completo = ler_csv_para_dataset(arquivo_csv_entrada)
    
    if dataset_completo:
        print("\n--- Iniciando a escrita dos arquivos para cada método ---")
        
        escritaTamanhoFixo('animes_metodo1_tamanho_fixo.bin', dataset_completo)
        escritaComDelimitador('animes_metodo2_qtde_campos.txt', dataset_completo, delimitador=';')
        escritaQtdeBytes('animes_metodo3_qtde_bytes.txt', dataset_completo)
        escritaArquivoIndices('animes_metodo4', dataset_completo)
        escritaComDelimitador('animes_metodo5_delimitadores.txt', dataset_completo, delimitador='|')
        
        print("\n--- Processo de escrita concluído! ---")
        
        print("\n--- Verificando a leitura do arquivo de tamanho fixo (Método 1)... ---")
        dataset_lido = leituraTamanhoFixo('animes_metodo1_tamanho_fixo.bin')
        if dataset_lido:
            print(f"Leitura bem-sucedida! Total de {len(dataset_lido)} registros lidos.")
            print("Amostra do primeiro registro lido do arquivo binário:")
            primeiro_registro = dataset_lido[0]
            for chave, valor in primeiro_registro.items():
                print(f"  - {chave}: {valor}")
        else:
            print("Falha ao ler o arquivo de verificação.")