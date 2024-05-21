#include <stdio.h>
#include <stdlib.h>

typedef struct HashTableEntry {
    int key;
    void *value;
} HashTableEntry;

typedef struct Node {
    HashTableEntry entry;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

typedef struct HashTable {
    int size;
    int capacity;
    LinkedList** array;
} HashTable;

int getcode(int key){
    return key%13;
}

HashTable* CreateHashTable(int size){
    HashTable* h = malloc(sizeof(HashTable));
    h->capacity = size;
    h->size = 0;
    h->array = malloc(size*sizeof(LinkedList*));
    for(int i=0; i<size;i++){
        h->array[i] = malloc(sizeof(LinkedList));
        h->array[i]->tail = NULL;
        h->array[i]->head = NULL;
        h->array[i]->size = 0;
    }
    return h;
}

char* get(HashTable* table, int key){
    int index = getcode(key);
    LinkedList* L = table->array[index];
    Node* current = L->head;
    while(current!=NULL){
        if(current->entry.key == key){
            return current->entry.value;
        }
        current = current->next;
    }
    return NULL;
}

void put(HashTable* table, int key, char* value){
    int index = getcode(key);
    LinkedList* l = table->array[index];
    Node* new = malloc(sizeof(Node));
    new->entry.value = value;
    new->entry.key = key;
    new->next = NULL;
    if(l->size == 0){
        l->head = new;
        l->tail = new;
    }
    else{
        l->tail->next = new;
        l->tail = new;
    }
    l->size++;
    table->size++;
}

void removeN(HashTable* table, int key){
    int index = getcode(key);
    LinkedList* l = table->array[index];
    if(l->size == 0){
        return;
    }
    Node* current = l->head;
    Node* before = l->head;
    while(current!=NULL){
        if(current->entry.key == key){
            if(current == l->head){
                l->head = l->head->next;
                free(current);
                return;
            }
            before->next = current->next;
            free(current);
        }
        before = current;
        current = current->next;
    }
    return;
}

int loadfactore(HashTable* table){
    int total_elements = table->size;
    int total_buckets = table->capacity;
    return total_elements/total_buckets;
}

int collision_rate(HashTable* table) {
    int total_collisions = 0;

    for (int i = 0; i < table->capacity; i++) {
        LinkedList* list = table->array[i];
        if (list->size > 1) {
            total_collisions += list->size - 1;
        }
    }

    int total_elements = table->size;

    int rate = (total_collisions * 100) / total_elements;

    return rate;
}


int main() {
    HashTable* table = CreateHashTable(13);
    put(table, 1, "One");
    put(table, 14, "Fourteen");
    put(table, 25, "Twenty-Five");
    put(table, 5, "Five");
    printf("Value for key 1: %s\n", get(table, 1));
    printf("Value for key 14: %s\n", get(table, 14));
    printf("Value for key 25: %s\n", get(table, 25));
    printf("Value for key 5: %s\n", get(table, 5));
    printf("Value for key 10: %s\n", get(table, 10));
    removeN(table, 14);
    printf("Value for key 14 after removal: %s\n", get(table, 14));
    printf("Load factor: %d\n", loadfactore(table));
    printf("Collision rate: %d%%\n", collision_rate(table));
    return 0;
}