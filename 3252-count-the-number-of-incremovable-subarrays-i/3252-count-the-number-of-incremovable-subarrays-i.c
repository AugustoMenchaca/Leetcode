int incremovableSubarrayCount(int* nums, int numsSize) {
    int i,j;
    bool verifica = true;
    int contador = 0; 
    int vetor_teste[numsSize];

    for (int start = 0; start < numsSize; start++) {
        for (int end = start; end < numsSize; end++) {
            
            int prev = -1;
            bool crescente = true;

            for (int i = 0; i < numsSize; i++) {
                if (i >= start && i <= end) {
                    continue;
                }

                if (prev != -1) {
                    if (nums[prev] >= nums[i]) {
                        crescente = false;
                        break;
                    }
                }
                prev = i;
            }

            if (crescente) {
                contador++;
            }
        }
    }

    return contador;
}