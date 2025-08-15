struct ListNode* mesclarListas(struct ListNode* lista1, struct ListNode* lista2) {
    struct ListNode cabeca;
    cabeca.next = NULL;

    struct ListNode* ponteiroFinal = &cabeca;

    while (lista1 && lista2) {
        if (lista1->val <= lista2->val) {
            ponteiroFinal->next = lista1;
            lista1 = lista1->next;
        } else {
            ponteiroFinal->next = lista2;
            lista2 = lista2->next;
        }
        ponteiroFinal = ponteiroFinal->next;
    }

    if (lista1 != NULL) {
        ponteiroFinal->next = lista1;
    } else {
        ponteiroFinal->next = lista2;
    }

    return cabeca.next;
}

struct ListNode* sortList(struct ListNode* inicio) {
    if (!inicio || !inicio->next) return inicio;

    struct ListNode* slow = inicio;
    struct ListNode* fast = inicio->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL; // Quebra a lista em duas

    struct ListNode* listaEsquerda = sortList(inicio);
    struct ListNode* listaDireita = sortList(mid);

    return mesclarListas(listaEsquerda, listaDireita);
    
}