bool strongPasswordCheckerII(char* password) {
    int i , verifica ;
    bool check_int = false , check_upper = false , check_special = false , check_lower = false;

    static char special[] = "!@#$%^&*()-+";

    if( strlen(password) < 8){
        return false;
    }else{
        for(i=0;i<strlen(password);i++){
            verifica = password[i];

            if(verifica > 47 && verifica < 58) check_int = true;

            if(verifica > 64 && verifica < 91) check_upper = true;

            if(verifica > 96 && verifica < 123 ) check_lower = true;
            
            for(int z = 0; z < strlen(special); z++){
                if(password[i] == special[z]) check_special = true;
            }
            if(i+1 < strlen(password) && password[i] == password[i+1]) return false;
        }
        if(check_int && check_upper && check_special && check_lower) return true;
    }
    return false;
}