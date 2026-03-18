import linecache
import os
import bisect  # Para inserir na lista de forma ordenada
import re      # Para criar a chave canônica

TAMANHO_REGISTRO = 512

def buscabinaria(tabela_ordenada, chave_consulta_str):
    inicio = 0
    fim = len(tabela_ordenada) - 1

    while inicio <= fim:
        meio = (inicio + fim) // 2
        
        chave_atual = tabela_ordenada[meio][0]
        
        if chave_atual == chave_consulta_str:
            rrn_encontrado = tabela_ordenada[meio][1]
            return [True, rrn_encontrado]
        
        elif chave_consulta_str < chave_atual:
            fim = meio - 1  # Busca na metade esquerda 
        else:
            inicio = meio + 1  # Busca na metade direita 

    return [False, None]

class IndicePrimario:
    
    def __init__(self, data_file, index_file):
        self.data_file_path = data_file
        self.index_file_path = index_file
        self.tabela_ind = []  # Tabela em memória (lista de tuplas ordenada)
        self.rrn_count = 0
        self._carregar_indice()

    def _criar_chave_canonica(self, titulo):
        chave = titulo.upper().replace(' ', '')
        return chave

    def _ler_com_rrn(self, rrn):
        try:
            linha_raw = linecache.getline(self.data_file_path, rrn + 1)
            
            if not linha_raw:
                print(f"Erro: Ponteiro {rrn} não encontrou linha em {self.data_file_path}.")
                return None
                
            linha_limpa = linha_raw.strip().rstrip('*')
            
            campos_registro = linha_limpa.split('|')
            return campos_registro
            
        except Exception as e:
            print(f"Erro ao ler arquivo de dados com RRN {rrn}: {e}")
            return None

    def _carregar_indice(self):
        if os.path.exists(self.index_file_path) and os.path.getsize(self.index_file_path) > 0:
            print(f"Carregando índice existente de '{self.index_file_path}'...")
            with open(self.index_file_path, 'r', encoding='utf-8') as f:
                for linha in f:
                    if not linha.strip():
                        continue
                    
                    partes = linha.strip().rpartition(' ')
                    chave_canonica = partes[0]
                    rrn_str = partes[2]
                    
                    self.tabela_ind.append( (chave_canonica, int(rrn_str)) )
            
            self.tabela_ind.sort() 
            self.rrn_count = len(self.tabela_ind)
            print(f"Índice carregado. {self.rrn_count} registros.")

        else:
            print(f"Arquivo de índice não encontrado. Construindo de '{self.data_file_path}'...")
            try:
                rrn = 0
                with open(self.data_file_path, 'r', encoding='utf-8') as f_dados:
                    for linha in f_dados:
                        if not linha.strip():
                            continue
                        
                        linha_limpa = linha.strip().rstrip('*')
                        campos = linha_limpa.split('|')
                        
                        if not campos or not campos[0]:
                            continue

                        titulo_amigavel = campos[0]
                        chave_canonica = self._criar_chave_canonica(titulo_amigavel)
                        
                        self.tabela_ind.append( (chave_canonica, rrn) )
                        rrn += 1
                
                self.tabela_ind.sort()
                self.rrn_count = len(self.tabela_ind)

                # Salvar o índice recém-criado no 'indice.txt'
                with open(self.index_file_path, 'w', encoding='utf-8') as f_indice:
                    for chave, rrn_val in self.tabela_ind:
                        f_indice.write(f"{chave} {rrn_val}\n")
                
                print(f"Índice construído e salvo com {self.rrn_count} registros.")

            except FileNotFoundError:
                print(f"Arquivo de dados '{self.data_file_path}' não encontrado. Começando zerado.")
                open(self.index_file_path, 'w').close()
                open(self.data_file_path, 'w').close()
            except Exception as e:
                print(f"Erro ao construir índice: {e}")

    def pesquisar(self, titulo_amigavel):
        print(f"\nBuscando pelo título: {titulo_amigavel}...")
        
        chave_canonica = self._criar_chave_canonica(titulo_amigavel)

        retorno_busca = buscabinaria(self.tabela_ind, chave_canonica)
        
        encontrado = retorno_busca[0]
        rrn = retorno_busca[1]

        if not encontrado:
            print(f"Resultado: Chave canônica '{chave_canonica}' não encontrada.")
            return None
        else:
            print(f"Resultado: Chave '{chave_canonica}' encontrada. Aponta para RRN {rrn}.")
            
            registro_campos = self._ler_com_rrn(rrn)
            
            return registro_campos


if __name__ == "__main__":
    
    DATA_FILE = 'arquivoDadosRegistrosFixos.txt'
    INDEX_FILE = 'indice.txt'

    db = IndicePrimario(DATA_FILE, INDEX_FILE)

    print("Iniciando pesquisas...")

    registro = db.pesquisar("BLEACH")
    if registro:
        print(f"Dados Encontrados: {registro[0]}, Eps: {registro[3]}, Link: {registro[1]}")

    registro = db.pesquisar("Naruto Shippuuden")
    if registro:
        print(f"Dados Encontrados: {registro[0]}, Eps: {registro[3]}, Link: {registro[1]}")

    registro = db.pesquisar("A Centaur's Life")
    if registro:
        print(f"Dados Encontrados: {registro[0]}") 

    registro = db.pesquisar("Meu Anime Nao Existe")
    if registro:
        print(f"Dados Encontrados: {registro[0]}")
