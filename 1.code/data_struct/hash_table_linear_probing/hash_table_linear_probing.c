#include "hash_table_linear_probing.h"

int hash_function(int key)
{
    return key % TABLE_SIZE;
}

void init_hash_table(hash_table_t *hash_table)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table->table[i] = NULL; 
    }
}

void insert(hash_table_t *hash_table, int key, int value)
{
    int index = hash_function(key); // �����ϣֵ���ҵ��洢����

    hash_entry_t *new_entry = (hash_entry_t *)malloc(sizeof(hash_entry_t));
    new_entry->key = key;
    new_entry->value = value;
    
    printf("insert key %d on index: %d\n", key, index);

    
    while (hash_table->table[index] != NULL) {
        printf("hash [%d] collision! test [%d]\n", index, (index + 1) % TABLE_SIZE);
        index = (index + 1) % TABLE_SIZE; 
    }

    hash_table->table[index] = new_entry; 
}

int search(hash_table_t *hash_table, int key)
{
    int index = hash_function(key); 

   
    while (hash_table->table[index] != NULL) {
        if (hash_table->table[index]->key == key) {
            printf("index [%d] ", index);
            return hash_table->table[index]->value; 
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return -1; 
}