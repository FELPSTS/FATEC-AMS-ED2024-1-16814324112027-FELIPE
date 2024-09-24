class Produto:
    # Autores:
    #Bruno Tonaki
    #Eric Chagas
    
    # Equipe:
    # Bruno Tonaki
    # Eric Chagas
    # Felipe Torquato
    # Henrique Canosa

    # Data:
    # 24/09/2024
    # Prof Verissímo
    # Paradigma: Recursividade
    def __init__(self, nome, preco, validade, quantidade):
        self.nome = nome
        self.preco = preco
        self.validade = validade
        self.quantidade = quantidade

    def __repr__(self):
        return f"{self.nome} - R${self.preco:.2f} - Válido até: {self.validade} - Quantidade: {self.quantidade}"

def ordena_por_nome(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_nome(produtos[:meio])
        direita = ordena_por_nome(produtos[meio:])

        return mescla_por_nome(esquerda, direita)

def mescla_por_nome(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].nome < direita[0].nome:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def ordena_por_preco(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_preco(produtos[:meio])
        direita = ordena_por_preco(produtos[meio:])

        return mescla_por_preco(esquerda, direita)

def mescla_por_preco(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].preco < direita[0].preco:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

def ordena_por_validade(produtos):
    if len(produtos) <= 1:
        return produtos
    else:
        meio = len(produtos) // 2
        esquerda = ordena_por_validade(produtos[:meio])
        direita = ordena_por_validade(produtos[meio:])

        return mescla_por_validade(esquerda, direita)

def mescla_por_validade(esquerda, direita):
    resultado = []
    while esquerda and direita:
        if esquerda[0].validade < direita[0].validade:
            resultado.append(esquerda.pop(0))
        else:
            resultado.append(direita.pop(0))
    resultado.extend(esquerda or direita)
    return resultado

# Exemplo de uso
produtos = [
   Produto("Arroz", 20.50, "10/10/2024", 100),
    Produto("Feijão", 9.30, "12/09/2024", 200),
    Produto("Macarrão", 4.75, "01/11/2024", 150),
    Produto("Azeite", 15.00, "05/12/2024", 80)
]

print("Ordenado por nome:")
produtos_ordenados_nome = ordena_por_nome(produtos)
print(produtos_ordenados_nome)

print("\nOrdenado por preço:")
produtos_ordenados_preco = ordena_por_preco(produtos)
print(produtos_ordenados_preco)

print("\nOrdenado por data de validade:")
produtos_ordenados_validade = ordena_por_validade(produtos)
print(produtos_ordenados_validade)

print("\nOrdenado por quantidade:")
produtos_ordenados_quantidade = ordena_por_validade(produtos)
print(produtos_ordenados_validade)
