int firstUniqChar(char* s) {
    int i,z,len=strlen(s);

    for(i=0;i<len;i++){
        int repetida=0;
        for(z=0;z<len;z++){
            if(s[i]==s[z] && i!=z){
                repetida=1;
                break;
            }
        }
        if(repetida==0)
            return i;
    }

    return -1;
}