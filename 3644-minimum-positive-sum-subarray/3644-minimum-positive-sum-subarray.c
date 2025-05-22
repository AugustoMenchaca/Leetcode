int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int minima = INT_MAX;
    
    // Percorrer todos os subarrays
    for (int i = 0; i < numsSize; i++) {
        int soma = 0;
        
        // Extender o subarray de i até j
        for (int j = i; j < numsSize; j++) {
            soma += nums[j];
            int tamanho = j - i + 1;
            
            if (tamanho >= l && tamanho <= r && soma > 0) {
                if (soma < minima) {
                    minima = soma;
                }
            }

            if(tamanho > r) break;
        }
    }
    if (minima == INT_MAX) {
        return -1;
    }
    
    return minima;
}