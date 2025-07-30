/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calculate(struct TreeNode* tree, int soma_acumulada);
struct TreeNode* convertBST(struct TreeNode* root) {
    calculate( root, 0 );
    
    return root;
}

int calculate(struct TreeNode* tree, int soma_acumulada){
    if (tree == NULL) return soma_acumulada;

    soma_acumulada = calculate(tree -> right, soma_acumulada );
    
    tree -> val = tree -> val + soma_acumulada;

    soma_acumulada = tree->val;

    return calculate(tree->left, soma_acumulada);
}