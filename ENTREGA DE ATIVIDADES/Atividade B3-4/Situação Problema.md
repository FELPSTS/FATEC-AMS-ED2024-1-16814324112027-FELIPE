# Atividade B3-4: Benchmark - Elaboração da Situação Problema

## Equipe
- Bruno Tonaki
- Eric Valencia Chagas
- Felipe Torquato Santos de Souza
- Henrique Augusto Pais Canosa

## Descrição

A situação problema envolve um sistema de gestão de inventário para um grande supermercado, onde é necessário ordenar listas de produtos de acordo com critérios como nome, preço e data de validade. Para isso, serão comparados dois algoritmos de ordenação: **Bubble Sort** (iterativo) e **Merge Sort** (recursivo). A solução proposta irá testar ambos os algoritmos com diferentes tamanhos de lista, a fim de determinar qual é o mais eficiente em diferentes cenários.

## Solução

- **Loop 1 e 2**: Usados no algoritmo **Bubble Sort** para comparar e trocar elementos repetidamente até que a lista esteja ordenada.
- **Loop 3**: Utilizado no processo de intercalação do **Merge Sort**, onde as duas metades da lista são combinadas.
- **Recursão**: Aplicada no **Merge Sort**, que divide a lista ao meio repetidamente até que os subarrays contenham apenas um elemento.

## Implementação

A linguagem utilizada será **Python**, com a implementação de ambos os algoritmos de ordenação (Bubble Sort e Merge Sort). O programa executará benchmarks para medir o tempo de execução dos dois algoritmos em listas de diferentes tamanhos.