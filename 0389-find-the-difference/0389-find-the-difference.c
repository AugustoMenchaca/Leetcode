char findTheDifference(char* s, char* t) {
    int i,contador;
    char diferenca;
    bool verifica = false;
    
    for(i = 0; i < strlen(t); i++){
        for(int z = 0; z < strlen(s); z++){
            if(s[z] == t[i]){
                verifica = true;
                s[z] = '0';
                break;
            }else {
                verifica = false;
            }
        }
        if(!verifica){
            diferenca = t[i];
            break;
        }
    }

    return  diferenca;
}