/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* value_vetor(struct TreeNode* root,int* vetor,int* posicao);

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int* vetor = NULL;
    int* posicao = (int*)malloc(sizeof(int));
    *posicao = 0;

    vetor = value_vetor(root, vetor, posicao);

    *returnSize = *posicao;

    free(posicao);

    return vetor;
}


int* value_vetor(struct TreeNode* root,int* vetor,int* posicao){
    if(root == NULL) return vetor;

    vetor = (int*)realloc(vetor, (*posicao + 1) * sizeof(int));

    vetor[*posicao] = root -> val;
    (*posicao)++;

    vetor = value_vetor(root -> left,vetor,posicao);
    vetor = value_vetor(root -> right,vetor,posicao);

    return vetor;
}