def busca_binária(A, x):
    início = 0
    fim = len(A) - 1

    while início <= fim:
        meio = (início + fim) // 2
        if A[meio] == x:
            return meio
        elif A[meio] < x:
            início = meio + 1
        else:
            fim = meio - 1

    return -1