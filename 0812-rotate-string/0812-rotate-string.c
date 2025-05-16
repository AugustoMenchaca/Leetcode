bool rotateString(char* s, char* goal) {
    int i,j;

    int tamanho = strlen(s);

    char *v_termina=s,temp;

    char copia[strlen(s)+1];

    strcpy(copia,s);

    while(*v_termina!='\0'){
        if(strcmp(copia,goal)==0)
            return true;
        temp=copia[0];
        for(i=0;i<tamanho-1;i++){
            copia[i]=copia[i+1];
        }
        copia[tamanho-1]=temp;
        v_termina++;
    }

    return false;
}