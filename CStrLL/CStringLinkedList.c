#include <string.h>
#include <stdlib.h>

#include <CStringLinkedList.h>

CStrLL_t* CStrLL_create(const char* head_node_value) {
    CStrLL_t* head = malloc(sizeof(CStrLL_t));

    head->value = malloc(sizeof(char) * strlen(head_node_value) + 1);
    strcpy(head->value, head_node_value);

    head->next = NULL;

    return head;
}

int CStrLL_destroy(CStrLL_t* head) {
    if (head == NULL) return -1;

    CStrLL_t* prev;
    CStrLL_t* curr = head;
    int nodes = 0;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev->value);
        free(prev);
    }

    return 0;
}

int CStrLL_len(CStrLL_t* head) {
    int len = 1;
    CStrLL_t* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
        len++;
    }

    return len;
}

CStrLL_t* CStrLL_append(CStrLL_t* head, const char* value) {
    CStrLL_t* curr = head;
    CStrLL_t* new = malloc(sizeof(CStrLL_t));

    new->next = NULL;
    new->value = malloc(sizeof(char) * strlen(value) + 1);
    strcpy(new->value, value);

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new;

    return new;
}

const char* CStrLL_getValueByIndex(CStrLL_t* head, unsigned int index) {
    CStrLL_t* curr = head;

    for (int i = 0; i < index; i++) {
        if (curr->next == NULL) return NULL;
        else curr = curr->next;
    }

    return curr->value;
}

int CStrLL_getIndexByValue(CStrLL_t* head, const char* value) {
    int index = 0;
    CStrLL_t* curr = head;

    while (curr->next != NULL) {
        if (!strcmp(curr->value, value)) return index;
        curr = curr->next;
        index++;
    }

    return -1;
}

int CStrLL_isValueInList(CStrLL_t* head, const char* value) {
    CStrLL_t* curr = head;
    
    while (curr->next != NULL) {
        if (!strcmp(curr->value, value)) return 1;
        curr = curr->next;
    }

    return 0;
}