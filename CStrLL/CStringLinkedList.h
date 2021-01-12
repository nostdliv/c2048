typedef struct CStringLinkedList {
    char* value;
    struct CStringLinkedList* next;
} CStrLL_t;

CStrLL_t* CStrLL_create(const char* head_node_value);

int CStrLL_destroy(CStrLL_t* head);

int CStrLL_len(CStrLL_t* head);

CStrLL_t* CStrLL_append(CStrLL_t* head, const char* value);

const char* CStrLL_getValueByIndex(CStrLL_t* head, unsigned int index);

// returns -1 if failed
int CStrLL_getIndexByValue(CStrLL_t* head, const char* value);

// returns boolean
int CStrLL_isValueInList(CStrLL_t* head, const char* value);