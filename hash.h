#ifndef HASH_H
#define HASH_H

#include "types.h"

#define TABLE_SIZE 11

typedef struct {
    char key[MAX_PACKAGE_ID];
    Package* data;
    bool is_deleted;
} HashEntry;

void init_hash_table(HashEntry* table[]);
int hash_function_type_b(const char* key);
void insert_package(HashEntry* table[], Package* pkg);
Package* search_package(HashEntry* table[], const char* key);

#endif
