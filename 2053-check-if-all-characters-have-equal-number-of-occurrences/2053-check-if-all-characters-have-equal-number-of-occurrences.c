bool areOccurrencesEqual(char* s) {
    int i,z=0,*conta_letras,contador=0,num_letras=0;
    char *letras;

    letras=(char*)malloc(strlen(s)*sizeof(char));

    conta_letras=(int*)malloc(strlen(s)*sizeof(int));

    for(i=0;i<strlen(s);i++){
        bool repetida=false;
        for(z=0;z<num_letras;z++){
                if(s[i]==letras[z]){
                    repetida=true;
                    break;
                }
            }
        if(repetida==false){
            letras[num_letras]=s[i];
            num_letras++;
        }

    }
    
    for(i=0;i<num_letras;i++){
        contador=0;
        for(z=0;z<strlen(s);z++){
            if(letras[i]==s[z])
                contador++;
        }
        conta_letras[i]=contador;
    }

    for(i=0;i<num_letras;i++){
        for(z=0;z<num_letras;z++){
            if(conta_letras[i]!=conta_letras[z]){
                return false;
            }
        }
    }

    free(conta_letras);
    free(letras);
    
    return true;
}