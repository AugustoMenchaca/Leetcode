int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* resultado = (int*)calloc(temperaturesSize, sizeof(int));
    int* pilha = (int*)malloc(sizeof(int) * temperaturesSize);
    int topo = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (topo >= 0 && temperatures[i] > temperatures[pilha[topo]]) {
            int indice = pilha[topo--];
            resultado[indice] = i - indice;
        }
        pilha[++topo] = i;
    }

    free(pilha);
    *returnSize = temperaturesSize;
    return resultado;
}