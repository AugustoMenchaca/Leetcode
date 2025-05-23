/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int i, z;

    int** matriz = (int**)malloc((rowIndex + 1) * sizeof(int*));

    for(i = 0; i <= rowIndex; i++){
        matriz[i] = (int*)malloc((i + 1) * sizeof(int));
    }

    for(i = 0;i <= rowIndex; i++){
        matriz[i][0] = 1;
        
        matriz[i][i] = 1;
        for(z = 1; z <= i - 1; z++){
            matriz[i][z] = matriz[i-1][z] + matriz[i-1][z-1];
        }
    }

   *returnSize = rowIndex + 1;

   for(i = 0; i < rowIndex; i++){
    free(matriz[i]);
   }

    return matriz[rowIndex];
}