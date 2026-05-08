#include "hash.h"

void init_hash_table(HashEntry* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

int hash_function_type_b(const char* key) {
    unsigned long hash = 0;
    int p = 31;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * p) + key[i];
    }
    return hash % TABLE_SIZE;
}

void insert_package(HashEntry* table[], Package* pkg) {
    int index = hash_function_type_b(pkg->package_id);
    int start_index = index;

    while (table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) {
            printf("Tablo dolu! %s eklenemedi.\n", pkg->package_id);
            return;
        }
    }

    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    strcpy(newEntry->key, pkg->package_id);
    newEntry->data = pkg;
    newEntry->is_deleted = false;
    table[index] = newEntry;
    printf("Paket %s, Index %d konumuna yerlestirildi.\n", pkg->package_id, index);
}

Package* search_package(HashEntry* table[], const char* key) {
    int index = hash_function_type_b(key);
    int start_index = index;

    while (table[index] != NULL) {
        if (strcmp(table[index]->key, key) == 0) {
            return table[index]->data;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) break;
    }
    return NULL;
}
