bool verifica(char *tree, int *atual, int tamanho);

bool isValidSerialization(char *preorder)
{

    int *atual = (int *)malloc(sizeof(int));
    *atual = 0;
    int tamanho = strlen(preorder);

    bool tree = verifica(preorder, atual, tamanho);

    if (*atual < tamanho - 1){
        free(atual);
        return false;
    }
    free(atual);
    return tree;
}

bool verifica(char *tree, int *atual, int tamanho)
{

    if (*atual > tamanho)
        return false;
    if (tree[*atual] == '#')
        return true;
    
    if(tree[*atual + 1] != ','){
        *atual = *atual + 1;
    }
    *atual = *atual + 2;
    bool verifica_esquerda = verifica(tree, atual, tamanho);
    *atual = *atual + 2;
    bool verifica_direita = verifica(tree, atual , tamanho);

    if (verifica_direita == false || verifica_esquerda == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}