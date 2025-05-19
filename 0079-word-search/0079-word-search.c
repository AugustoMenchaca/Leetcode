bool verifica(int c_letra, int i, int z, char** board, char* word, int boardSize, int* boardColSize, bool** visitado);

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i, z, c_letra = 0;
    
    char *teste=word,**teste_board=board;

    bool** visitado = (bool**)malloc(boardSize * sizeof(bool*));
    for (i = 0; i < boardSize; i++) {
        visitado[i] = (bool*)calloc(boardColSize[i], sizeof(bool));
    }

    for (i = 0; i < boardSize; i++) {
        for (z = 0; z < boardColSize[i]; z++) {
            if (word[c_letra] == board[i][z]) {
                if (verifica(c_letra, i, z, teste_board, teste, boardSize, boardColSize, visitado)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool verifica(int c_letra, int i, int z, char** board, char* word, int boardSize, int* boardColSize, bool** visitado) {
    if (board[i][z] != word[c_letra]) return false;

    if (word[c_letra + 1] == '\0') return true;

    visitado[i][z] = true;
    c_letra++;

    bool achou = false;

    if (!achou && z > 0 && !visitado[i][z - 1] && word[c_letra] == board[i][z - 1]) {
        achou = verifica(c_letra, i, z - 1, board, word, boardSize, boardColSize, visitado);
    }

    if (!achou && z + 1 < boardColSize[i] && !visitado[i][z + 1] && word[c_letra] == board[i][z + 1]) {
        achou = verifica(c_letra, i, z + 1, board, word, boardSize, boardColSize, visitado);
    }

    if (!achou && i > 0 && !visitado[i - 1][z] && word[c_letra] == board[i - 1][z]) {
        achou = verifica(c_letra, i - 1, z, board, word, boardSize, boardColSize, visitado);
    }

    if (!achou && i + 1 < boardSize && !visitado[i + 1][z] && word[c_letra] == board[i + 1][z]) {
        achou = verifica(c_letra, i + 1, z, board, word, boardSize, boardColSize, visitado);
    }

    visitado[i][z] = false;

    return achou;
}