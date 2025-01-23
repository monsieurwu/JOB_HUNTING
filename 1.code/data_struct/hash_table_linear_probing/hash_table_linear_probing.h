#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  


typedef struct {
    int key;   
    int value; 
} hash_entry_t;


typedef struct {
    hash_entry_t *table[TABLE_SIZE]; 
} hash_table_t;


int hash_function(int key);
void init_hash_table(hash_table_t *hash_table);
void insert(hash_table_t *hash_table, int key, int value);
int search(hash_table_t *hash_table, int key);
