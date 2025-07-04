int verifica(struct TreeNode* filho){
    if(filho == NULL) return 0;
    int RHigh = 0, LHigh = 0;

    LHigh = verifica(filho->left);
    if(LHigh == -100) return -100;

    RHigh = verifica(filho->right);
    if(RHigh == -100) return -100;

    if(RHigh - LHigh > 1 || LHigh - RHigh > 1){

        return -100;

    }else {

        if(LHigh > RHigh){
            return LHigh + 1;
        }else {
            return RHigh + 1;
        }

    }

}

bool isBalanced(struct TreeNode* root) {
    if(root == NULL) return true;
    
    int Resultado;

    Resultado = verifica(root);

    if(Resultado == -100){
        return false;
    }else {
        return true;
    }
}