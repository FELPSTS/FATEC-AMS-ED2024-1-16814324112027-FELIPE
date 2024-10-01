from datetime import datetime

    # Autores:
    # Felipe Torquato
    # Henrique Canosa
    
    # Equipe:
    # Bruno Tonaki
    # Eric Chagas
    # Felipe Torquato
    # Henrique Canosa

    # Data:
    # 24/09/2024
    # Prof Verissímo
    # Paradigma: Iteratividade

# Definição do Produto com nome, preço, data de validade e quantidade
class Produto:
    def __init__(self, nome, preco, data_validade, quantidade):
        self.nome = nome
        self.preco = preco
        self.data_validade = datetime.strptime(data_validade, '%d/%m/%Y')
        self.quantidade = quantidade

    def __repr__(self):
        return f"{self.nome} - R$ {self.preco:.2f} - Validade: {self.data_validade.strftime('%d/%m/%Y')} - Quantidade: {self.quantidade}"

def bubble_sort(produtos, chave):
    n = len(produtos)
    for i in range(n):

        trocou = False
        for j in range(0, n - i - 1):
            if getattr(produtos[j], chave) > getattr(produtos[j + 1], chave):

                produtos[j], produtos[j + 1] = produtos[j + 1], produtos[j]
                trocou = True

        if not trocou:
            break

def inserir_produtos():
    produtos = []
    num_produtos = int(input("Quantos produtos deseja inserir? "))

    for _ in range(num_produtos):
        nome = input("Nome do produto: ")
        preco = float(input("Preço do produto: "))
        data_validade = input("Data de validade (dd/mm/yyyy): ")
        quantidade = int(input("Quantidade do produto: "))
        produtos.append(Produto(nome, preco, data_validade, quantidade))

    return produtos

produtos = inserir_produtos()

print("\nEscolha o critério de ordenação:")
print("1. Nome")
print("2. Preço")
print("3. Data de Validade")
print("4. Quantidade")
criterio = int(input("Digite o número do critério escolhido: "))

if criterio == 1:
    chave = 'nome'
elif criterio == 2:
    chave = 'preco'
elif criterio == 3:
    chave = 'data_validade'
elif criterio == 4:
    chave = 'quantidade'
else:
    print("Critério inválido. Usando 'nome' como padrão.")
    chave = 'nome'

bubble_sort(produtos, chave)

print("\nProdutos ordenados:")
for produto in produtos:
    print(produto)
