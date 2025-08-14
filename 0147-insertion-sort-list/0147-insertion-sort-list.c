/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* guarda_valores(struct ListNode* item, int* dados, int contador);

struct ListNode* insertionSortList(struct ListNode* head) {
    int* dados = (int*)malloc(sizeof(int));
    int* vetor = guarda_valores(head, dados, 0);

    struct ListNode* passador = head;

    while(passador != NULL){
        passador -> val = *vetor;

        vetor++;
        passador = passador -> next;
    }

    return head;
}

int compara_inteiros(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}


int* guarda_valores(struct ListNode* item, int* dados, int contador)
{
    if(item == NULL ) {
        qsort(dados, contador, sizeof(int), compara_inteiros);
        
        return dados; 
    }
    dados = (int*)realloc(dados,(contador + 1) * sizeof(int));

    dados[contador] = item->val;
    
    return guarda_valores(item->next, dados, contador + 1);
}